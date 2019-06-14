
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef rti_me_cpp_hxx
#include "rti_me_cpp.hxx"
#endif

#include "wh_sm/wh_sm_history.h"
#include "rh_sm/rh_sm_history.h"

#include "quickstart.h"
#include "quickstartSupport.h"
#include "quickstartApplication.h"

class ImageDataWriterListener : public DDSDataWriterListener
{
  public:
    ImageDataWriterListener() : DDSDataWriterListener() { }
    ~ImageDataWriterListener() { }
};

int
publisher_main_w_args(DDS_Long domain_id, char *udp_intf, char *peer,
DDS_Long sleep_time, DDS_Long count)
{
    Application *application = NULL;

    DDSPublisher *publisher = NULL;
    DDSDataWriter *datawriter = NULL;
    ImageDataWriter *hw_writer = NULL;
    DDS_DataWriterQos dw_qos;
    DDS_ReturnCode_t retcode;
    Image *sample = NULL;
    DDS_Long i;
    DDSDataWriterListener *dw_listener = NULL;

    application = new Application();
    if (application == NULL)
    {
        printf("failed Application new\n");
        goto done;
    }

    retcode = application->initialize("publisher", 
    "subscriber", 
    domain_id,
    udp_intf, 
    peer, 
    sleep_time, 
    count);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed Application initialize\n");
        goto done;
    }

    publisher = application->participant->create_publisher(
        DDS_PUBLISHER_QOS_DEFAULT,NULL,DDS_STATUS_MASK_NONE);
    if (publisher == NULL)
    {
        printf("publisher == NULL\n");
        goto done;
    }

    retcode = publisher->get_default_datawriter_qos(dw_qos);
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed get_default_datawriter_qos\n");
        goto done;
    }

    #ifdef USE_RELIABLE_QOS
    dw_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    #else
    dw_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    #endif
    dw_qos.resource_limits.max_samples = 32;
    dw_qos.resource_limits.max_samples_per_instance = 32;
    dw_qos.resource_limits.max_instances = 1;
    dw_qos.history.depth = 32;

    datawriter = publisher->create_datawriter(application->topic,
    dw_qos,NULL,DDS_STATUS_MASK_NONE);
    if (datawriter == NULL)
    {
        printf("datawriter == NULL\n");
        goto done;
    }

    retcode = application->enable();
    if (retcode != DDS_RETCODE_OK)
    {
        printf("failed to enable application\n");
        goto done;
    }

    hw_writer = ImageDataWriter::narrow(datawriter);
    if (hw_writer == NULL)
    {
        printf("failed datawriter narrow\n");
        goto done;
    }

    for (i = 0;
    (application->count > 0 && i < application->count) ||
    (application->count == 0);
    ++i)
    {

        // LAB -- get a loaned sample from the DW
        retcode = hw_writer->get_loan(sample);
        // LAB -- get the root offset 
        ImageOffset offset_root = sample->root();
        // LAB -- get an offset to the Dimension struct
        DimensionOffset offset_dimension = sample->root().dimension();
        // LAB -- get an offset to the img_data array
        rti::flat::PrimitiveArrayOffset<DDS_Octet, (30000000)> offset_img_data = sample->root().img_data();
        DDS_Octet *octet_array = rti::flat::plain_cast(offset_img_data);

        // LAB -- set some values in the sample
        offset_root.timestamp(1234);
        offset_dimension.width(1920);
        offset_dimension.height(1080);
        octet_array[0] = (DDS_Octet)22;
        octet_array[1] = (DDS_Octet)33;


        // use flat data APIs to populate flat_data final type
        if (retcode != DDS_RETCODE_OK) 
        {
            printf("Failed to get loaned sample\n");
            return -1;
        }        

        retcode = hw_writer->write(*sample, DDS_HANDLE_NIL);
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

    if (application != NULL)
    {
        delete application;
    }

    if (sample != NULL)
    {
        ImageTypeSupport::delete_data(sample);
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
            Application::help(argv[0]);
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
    char *peer = "10.10.65.104";
    char *udp_intf = NULL;
    DDS_Long sleep_time = 1000;
    DDS_Long count = 0;

    return publisher_main_w_args(domain_id, udp_intf, peer, sleep_time, count);
}
#endif
