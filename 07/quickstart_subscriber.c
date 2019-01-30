
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rti_me_c.h"
#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"

#include "quickstart.h"
#include "quickstartSupport.h"
#include "quickstartPlugin.h"
#include "quickstartApplication.h"

/* See Wire Protocol Specification on http://www.omg.org/spec/DDSI-RTPS/2.2/
* for more details about CDR encapsulation.
*/

/*ci \brief Unsigned Long type size */
#define UNSIGNED_LONG_SIZE  4


/* LAB #2 -- add code that will be called in the event that a deadline is 
 * missed.
 */
void myModule_msgTypeSubscriber_on_requested_deadline_missed(
        void *listener_data,
        DDS_DataReader * reader,
        const struct DDS_RequestedDeadlineMissedStatus *status) 
{   
    printf("INFO: Deadline missed! this has happened %d times\n", 
            status->total_count);
}

/* LAB #7 -- change function signature so that we can call this from the 
 * WaitSet loop instead of it being called by the DR listener
 */
void
myModule_msgTypeSubscriber_on_data_available(DDS_DataReader * reader)
{
    myModule_msgTypeDataReader *hw_reader = myModule_msgTypeDataReader_narrow(reader);
    DDS_ReturnCode_t retcode;
    struct DDS_SampleInfo *sample_info = NULL;
    myModule_msgType *sample = NULL;

    struct DDS_SampleInfoSeq info_seq = 
    DDS_SEQUENCE_INITIALIZER;
    struct myModule_msgTypeSeq sample_seq = 
    DDS_SEQUENCE_INITIALIZER;

    const DDS_Long TAKE_MAX_SAMPLES = 32;
    DDS_Long i;

    retcode = myModule_msgTypeDataReader_take(hw_reader, 
    &sample_seq, &info_seq, TAKE_MAX_SAMPLES, 
    DDS_ANY_SAMPLE_STATE, DDS_ANY_VIEW_STATE, DDS_ANY_INSTANCE_STATE);

    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to take data, retcode(%d)\n", retcode);
        goto done;
    }

    /* Print each valid sample taken */
    for (i = 0; i < myModule_msgTypeSeq_get_length(&sample_seq); ++i)
    {
        sample_info = DDS_SampleInfoSeq_get_reference(&info_seq, i);

        if (sample_info->valid_data)
        {
            sample = myModule_msgTypeSeq_get_reference(&sample_seq, i);

            printf("\nValid sample received\n");
            /* TODO read sample attributes here */

            /* LAB #1 -- print the member values frrom the received sample */
            printf("id = %d\n", sample->id);
            printf("value1 = %d\n", sample->value1);
            printf("name = %s\n", sample->name);
        }
        else
        {
            printf("\nSample received\n\tINVALID DATA\n");
        }
    }

    myModule_msgTypeDataReader_return_loan(hw_reader, &sample_seq, &info_seq);

    done:
    myModule_msgTypeSeq_finalize(&sample_seq);
    DDS_SampleInfoSeq_finalize(&info_seq);
}

void
myModule_msgTypeSubscriber_on_subscription_matched(void *listener_data,
DDS_DataReader * reader,
const struct
DDS_SubscriptionMatchedStatus
*status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a publisher\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a publisher\n");
    }
}

/*i
* \brief Helper function to filter an myModule_msgType sample
*
* \param[in]  sample       A myModule_msgType data sample to filter
* \param[out] drop_sample  Out parameter determining whether the sample
*                          should be filtered out or not.
*/
void 
myModule_msgTypeSubscriber_filter_sample(myModule_msgType *sample,
DDS_Boolean *drop_sample)
{
    /* Example filter: drop samples with even-numbered count in id */

    *drop_sample = (sample->id % 2 == 0) ? DDS_BOOLEAN_TRUE : DDS_BOOLEAN_FALSE;
}

/*i
* \brief Helper function to deserialize an unsigned long
*
* \param[in]  src_buffer      Pointer to CDR stream buffer
* \param[in]  need_byte_swap  Indicates whether it is needed to swap bytes
* \param[out] instance        Deserialized unsigned long
*/
void
myModule_msgTypeSubscriber_deserialize_unsigned_long(char **src_buffer,
RTI_BOOL need_byte_swap,
DDS_UnsignedLong *instance)
{
    RTI_INT32 i;
    if (need_byte_swap)
    {
        for (i = 3; i >= 0; --i)
        {
            *((RTI_INT8*)instance + i) = *((*src_buffer)++);
        }
    }
    else
    {
        *instance = *(RTI_UINT32*)(*src_buffer);
        (*src_buffer) += CDR_LONG_SIZE;
    }
}

/*i
* \brief Implementation of \ref DDS_DataReaderListener::on_before_sample_deserialize
*/
DDS_Boolean
myModule_msgTypeSubscriber_on_before_sample_deserialize(
    void *listener_data,
    DDS_DataReader *reader,
    struct NDDS_Type_Plugin *plugin,
    struct CDR_Stream_t *stream,
    DDS_Boolean *dropped)
{
    DDS_Boolean result = DDS_BOOLEAN_FALSE;
    DDS_Long id = 0;
    RTI_BOOL need_byte_swap = DDS_BOOLEAN_FALSE;
    char *src_buffer = NULL;

    need_byte_swap = stream->need_byte_swap;
    src_buffer = CDR_Stream_get_current_position_ptr(stream);

    /* deserialize only field 'id', instead of the whole sample */

    if (!CDR_Stream_check_size(stream, UNSIGNED_LONG_SIZE))
    {
        printf("Failed to deserialize id. The stream is too short, missing data\n");
        goto done;
    }

    /* Note primitive types must be aligned to their length in the CDR stream.
    * For example, a long must start on a 4-byte boundary. The boundaries are
    * counted from the start of the CDR stream.
    * As the sample 'id' is the first data in the stream it is already aligned.
    * Position 0 (beginning of the stream) is aligned to 4 (size of long).
    */
    myModule_msgTypeSubscriber_deserialize_unsigned_long(&src_buffer,
    need_byte_swap,
    (DDS_UnsignedLong*)&id);

    /* filter the sample */
    *dropped = (id % 2 == 0) ? DDS_BOOLEAN_TRUE : DDS_BOOLEAN_FALSE;

    if (*dropped)
    {
        printf("\nSample filtered, before deserialize...\n\tDROPPED - id: %d\n",
        id);
    }

    result = DDS_BOOLEAN_TRUE;
    done:
    return result;
}

/*i
* \brief Implementation of \ref DDS_DataReaderListener::on_before_sample_commit
*/
DDS_Boolean
myModule_msgTypeSubscriber_on_before_sample_commit(
    void *listener_data,
    DDS_DataReader *reader,
    const void *const sample,
    const struct DDS_SampleInfo *const sample_info,
    DDS_Boolean *dropped)
{
    myModule_msgType *hw_sample = (myModule_msgType *)sample; 

    myModule_msgTypeSubscriber_filter_sample(hw_sample, dropped);

    if (*dropped)
    {
        printf("\nSample filtered, before commit...\n");
    }

    return DDS_BOOLEAN_TRUE;
}

int
subscriber_main_w_args(DDS_Long domain_id, char *udp_intf, char *peer,
DDS_Long sleep_time, DDS_Long count)
{
    DDS_Subscriber *subscriber;
    DDS_DataReader *datareader;
    struct DDS_DataReaderQos dr_qos = DDS_DataReaderQos_INITIALIZER;
    DDS_ReturnCode_t retcode;
    struct DDS_DataReaderListener dr_listener =
    DDS_DataReaderListener_INITIALIZER;
    struct Application *application;

    /* LAB #7 -- Waitset variables */
    DDS_WaitSet *waitset = NULL;
    DDS_StatusCondition *dr_condition = NULL;
    struct DDS_ConditionSeq active_conditions = DDS_SEQUENCE_INITIALIZER;
    DDS_Boolean finalize_active_conditions = DDS_BOOLEAN_FALSE;
    struct DDS_Duration_t wait_timeout = { 10, 0 }; /* 10 seconds */

    application = Application_create("subscriber", "publisher", domain_id,
    udp_intf, peer, sleep_time, count);

    if (application == NULL)
    {
        return 0;
    }

    subscriber =
    DDS_DomainParticipant_create_subscriber(application->participant,
    &DDS_SUBSCRIBER_QOS_DEFAULT,
    NULL, DDS_STATUS_MASK_NONE);
    if (subscriber == NULL)
    {
        printf("subscriber == NULL\n");
        goto done;
    }

    #ifdef USE_SAMPLE_FILTER
    /* choose one callback to enable */
    #ifdef FILTER_ON_DESERIALIZE
    dr_listener.on_before_sample_deserialize =
    myModule_msgTypeSubscriber_on_before_sample_deserialize;
    #else
    dr_listener.on_before_sample_commit = 
    myModule_msgTypeSubscriber_on_before_sample_commit;
    #endif

    #endif

    /* INTEROPERABILITY NOTE:
    Non-Connext Micro DDS writers and readers will have default LivelinessQoS
    kind set to DDS_AUTOMATIC_LIVELINESS_QOS.

    Because Connext Micro currently only supports
    DDS_MANUAL_BY_TOPIC_LIVELINESS_QOS for finite lease_duration,
    a non-Connext Micro writer must set its liveliness kind to
    DDS_MANUAL_BY_TOPIC_LIVELINESS_QOS as well in order for
    Requested-Offered (RxO) semantics to be compatible.
    */
   
    /* LAB #7 -- remove the on_data_available callback... we'll handle this with 
     * a WaitSet
     */    
    
    /*dr_listener.on_data_available = 
            myModule_msgTypeSubscriber_on_data_available; */
    dr_listener.on_subscription_matched =
            myModule_msgTypeSubscriber_on_subscription_matched;
    /* LAB #2 -- add function pointer to the callback to handle deadline*/
    dr_listener.on_requested_deadline_missed = 
            myModule_msgTypeSubscriber_on_requested_deadline_missed;        

    /* Publisher sends samples with id = 0 or id = 1, so 2 instances maximum.
    * But in case filtering is done, all samples with 'id = 0' are
    * filtered so only one instance is needed.
    */
    #ifdef USE_SAMPLE_FILTER
    dr_qos.resource_limits.max_instances = 1;
    #else
    dr_qos.resource_limits.max_instances = 2;
    #endif

    dr_qos.resource_limits.max_samples_per_instance = 32;
    dr_qos.resource_limits.max_samples = dr_qos.resource_limits.max_instances *
    dr_qos.resource_limits.max_samples_per_instance;
    /* if there are more remote writers, you need to increase these limits */
    dr_qos.reader_resource_limits.max_remote_writers = 10;
    dr_qos.reader_resource_limits.max_remote_writers_per_instance = 10;
    dr_qos.history.depth = 32;


    /* LAB #2 -- add a deadline to DataReader */
    /* LAB #4 -- set deadline to 1.5 to be compatible with DW */
    dr_qos.deadline.period.sec = 1;
    dr_qos.deadline.period.nanosec = 500000000;

    /* LAB #6 -- introduce exculsive ownership */
    dr_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;

    /* Reliability QoS */
    #ifdef USE_RELIABLE_QOS
    dr_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    #else
    dr_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    #endif

    /* LAB #7 -- remove the DDS_DATA_AVAILABLE_STATUS mask */
    /* LAB #2 -- change mask to include DDS_REQUESTED_DEADLINE_MISSED_STATUS */
    datareader = DDS_Subscriber_create_datareader(subscriber,
    DDS_Topic_as_topicdescription
    (application->topic), &dr_qos,
    &dr_listener,
    /* DDS_DATA_AVAILABLE_STATUS | */
    DDS_SUBSCRIPTION_MATCHED_STATUS |
    DDS_REQUESTED_DEADLINE_MISSED_STATUS);

    if (datareader == NULL)
    {
        printf("datareader == NULL\n");
        goto done;
    }

    /* LAB #7 -- Initialize waitset related variables */

    if (!DDS_ConditionSeq_initialize(&active_conditions)) {
        printf("cannot initialize active_conditions\n");
        return -1;
    }
    finalize_active_conditions = DDS_BOOLEAN_TRUE;
    if (!DDS_ConditionSeq_set_maximum(&active_conditions, 1)) {
        printf("cannot set maximum of active_conditions\n");
        return -1;
    }

    /* LAB #7 -- create the WaitSet */
    waitset = DDS_WaitSet_new();
    if (waitset == NULL ) {
        printf("waitset == NULL\n");
        return -1;
    }

    /* LAB #7 -- get the DataReader's status condition */
    dr_condition = DDS_Entity_get_statuscondition(
            DDS_DataReader_as_entity(datareader));

    /* LAB #7 -- set the mask */
    retcode = DDS_StatusCondition_set_enabled_statuses(dr_condition,
                                                       DDS_DATA_AVAILABLE_STATUS);

    if (retcode != DDS_RETCODE_OK) {
        printf("Cannot set status condition's enabled statuses\n");
        return -1;
    }

    /* LAB #7 -- attached the condition to the waitset */
    retcode = DDS_WaitSet_attach_condition(waitset,
                DDS_StatusCondition_as_condition(dr_condition));
    if (retcode != DDS_RETCODE_OK)
    {
        printf("Cannot attach DR condition to waitset\n");
        return -1;
    }

    retcode = Application_enable(application);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to enable application\n");
        goto done;
    }

    /* LAB #7 -- add a loop to simply run the WaitSet code forever (until a
     * ctrl-C, anyway)
     */ 
    while (1)
    {
        retcode = DDS_RETCODE_ERROR;
        retcode = DDS_WaitSet_wait(waitset, &active_conditions, &wait_timeout);

        /* LAB #7 -- Because we only attached 1 condition to the waitset, we know
        * that it will be either DDS_DATA_AVAILABLE_STATUS or a timeout that causes
        * the waitset to return.
        * 
        * If there were more active conditions, we would need to iterate through
        * active_conditions to see which status changed. */
        switch (retcode) {
            case DDS_RETCODE_OK:
                myModule_msgTypeSubscriber_on_data_available(datareader);
                break;
            case DDS_RETCODE_TIMEOUT:
                printf("WaitSet_wait timed out\n");
                break;
            default:
                printf("ERROR in WaitSet_wait: retcode=%d\n", retcode);
                break;
        }  
    }

    done:

    Application_delete(application);

    DDS_DataReaderQos_finalize(&dr_qos);

    return 0;
}

#if !(defined(RTI_VXWORKS) && !defined(__RTP__))
int
main(int argc, char **argv)
{
    DDS_Long i = 0;
    DDS_Long domain_id = 0;
    char *peer = NULL;
    char *udp_intf = NULL;
    DDS_Long sleep_time = 1000;
    DDS_Long count = 0;

    for (i = 1; i < argc; ++i)
    {
        if (!strcmp(argv[i], "-domain"))
        {
            ++i;
            if (i == argc)
            {
                printf("-domain <domain_id>\n");
                return -1;
            }
            domain_id = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-udp_intf"))
        {
            ++i;
            if (i == argc)
            {
                printf("-udp_intf <interface>\n");
                return -1;
            }
            udp_intf = argv[i];
        }
        else if (!strcmp(argv[i], "-peer"))
        {
            ++i;
            if (i == argc)
            {
                printf("-peer <address>\n");
                return -1;
            }
            peer = argv[i];
        }
        else if (!strcmp(argv[i], "-sleep"))
        {
            ++i;
            if (i == argc)
            {
                printf("-sleep_time <sleep_time>\n");
                return -1;
            }
            sleep_time = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-count"))
        {
            ++i;
            if (i == argc)
            {
                printf("-count <count>\n");
                return -1;
            }
            count = strtol(argv[i], NULL, 0);
        }
        else if (!strcmp(argv[i], "-h"))
        {
            Application_help(argv[0]);
            return 0;
        }
        else
        {
            printf("unknown option: %s\n", argv[i]);
            return -1;
        }
    }

    return subscriber_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#elif defined(RTI_VXWORKS)
int
subscriber_main(void)
{
    /* Explicitly configure args below */
    DDS_Long domain_id = 44;
    char *peer = "10.10.65.103";
    char *udp_intf = NULL;
    DDS_Long sleep_time = 1000;
    DDS_Long count = 0;

    return subscriber_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#endif
