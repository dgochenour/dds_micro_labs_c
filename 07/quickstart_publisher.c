
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "rti_me_c.h"
#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"

#include "quickstart.h"
#include "quickstartSupport.h"
#include "quickstartApplication.h"

/* LAB #3 -- add listener callback to handle incompatible QoS */
void myModule_msgTypePublisher_on_offered_incompatible_qos(
        void *listener_data,
        DDS_DataWriter * writer,
        const struct DDS_OfferedIncompatibleQosStatus *status)
{
    printf("INFO: Offered QoS was incompatible with DataReader\n");
    printf("INFO: QoS Policy ID = %d\n", status->last_policy_id);
}   

void
myModule_msgTypePublisher_on_publication_matched(void *listener_data,
DDS_DataWriter * writer,
const struct
DDS_PublicationMatchedStatus *status)
{
    if (status->current_count_change > 0)
    {
        printf("Matched a subscriber\n");
    }
    else if (status->current_count_change < 0)
    {
        printf("Unmatched a subscriber\n");
    }
}

int
publisher_main_w_args(DDS_Long domain_id, char *udp_intf, char *peer,
DDS_Long sleep_time, DDS_Long count)
{
    DDS_Publisher *publisher;
    DDS_DataWriter *datawriter;
    myModule_msgTypeDataWriter *hw_datawriter;
    struct DDS_DataWriterQos dw_qos = DDS_DataWriterQos_INITIALIZER;
    DDS_ReturnCode_t retcode;
    myModule_msgType *sample = NULL;
    struct Application *application = NULL;
    DDS_Long i;
    struct DDS_DataWriterListener dw_listener =
    DDS_DataWriterListener_INITIALIZER;

    sample = myModule_msgType_create();
    if (sample == NULL)
    {
        printf("failed myModule_msgType_create\n");
        return 0;
    }

    application = Application_create("publisher", "subscriber", domain_id,
    udp_intf, peer, sleep_time, count);

    if (application == NULL)
    {
        printf("failed Application create\n");
        goto done;
    }

    publisher = DDS_DomainParticipant_create_publisher(application->participant,
    &DDS_PUBLISHER_QOS_DEFAULT,
    NULL,
    DDS_STATUS_MASK_NONE);
    if (publisher == NULL)
    {
        printf("publisher == NULL\n");
        goto done;
    }

    #ifdef USE_RELIABLE_QOS
    dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    #else
    dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    #endif
    dw_qos.resource_limits.max_samples_per_instance = 32;
    dw_qos.resource_limits.max_instances = 2;
    dw_qos.resource_limits.max_samples = dw_qos.resource_limits.max_instances *
    dw_qos.resource_limits.max_samples_per_instance;
    dw_qos.history.depth = 32;
    dw_qos.protocol.rtps_reliable_writer.heartbeat_period.sec = 0;
    dw_qos.protocol.rtps_reliable_writer.heartbeat_period.nanosec = 250000000;

    /* LAB #6 -- introduce exculsive ownership */
    dw_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;
    dw_qos.ownership_strength.value = 10;

    /* LAB #2 -- Add deadline to the DataWriter Qos */
    /* LAB #3 -- Adjust the deadline to be longer than the DR's... to cause an
     * intentional error that will cause the callback to be called
     */ 
    dw_qos.deadline.period.sec = 1;
    dw_qos.deadline.period.nanosec = 500000000;

    /* INTEROPERABILITY NOTE:
    Non-Connext Micro DDS writers and readers will have default LivelinessQoS
    kind set to DDS_AUTOMATIC_LIVELINESS_QOS.

    Because Connext Micro currently only supports
    DDS_MANUAL_BY_TOPIC_LIVELINESS_QOS for finite lease_duration,
    a non-Connext Micro writer must set its liveliness kind to
    DDS_MANUAL_BY_TOPIC_LIVELINESS_QOS as well in order for
    Requested-Offered (RxO) semantics to be compatible.
    */

    /* LAB #3 - Add a DW listener to alert for mismatched QoS */
    dw_listener.on_offered_incompatible_qos =
            myModule_msgTypePublisher_on_offered_incompatible_qos;

    dw_listener.on_publication_matched =
            myModule_msgTypePublisher_on_publication_matched;
    
    /* LAB #3 -- Change status mask to include */        
    datawriter = DDS_Publisher_create_datawriter(publisher, 
                                                 application->topic, 
                                                 &dw_qos,
                                                 &dw_listener,
                                                 DDS_PUBLICATION_MATCHED_STATUS | 
                                                 DDS_OFFERED_INCOMPATIBLE_QOS_STATUS);

    if (datawriter == NULL)
    {
        printf("datawriter == NULL\n");
        goto done;
    }

    retcode = Application_enable(application);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to enable application\n");
        goto done;
    }

    hw_datawriter = myModule_msgTypeDataWriter_narrow(datawriter);

    for (i = 0; (application->count > 0 && i < application->count) ||
    (application->count == 0); ++i)
    {
        /* TODO set sample attributes here */

        /* LAB #1 -- add some values to the sample we are writing, just so they
         * are't empty
         */
        sample->id = 9017;
        sample->name = "Don Gochenour";
        sample->value1 = i;

        retcode = myModule_msgTypeDataWriter_write(hw_datawriter, sample, &DDS_HANDLE_NIL);
        if (retcode != DDS_RETCODE_OK)
        {
            printf("Failed to write sample\n");
        } 
        else
        {
            printf("Written sample %d\n",(i+1));
        } 

        OSAPI_Thread_sleep(application->sleep_time);
    }

    done:

    Application_delete(application);

    DDS_DataWriterQos_finalize(&dw_qos);

    if (sample != NULL)
    {
        myModule_msgType_delete(sample);
    }

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

    return publisher_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#elif defined(RTI_VXWORKS)
int
publisher_main(void)
{
    /* Explicitly configure args below */
    DDS_Long i = 0;
    DDS_Long domain_id = 44;
    char *peer = "10.10.30.101";
    char *udp_intf = NULL;
    DDS_Long sleep_time = 1000;
    DDS_Long count = 0;

    return publisher_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#endif
