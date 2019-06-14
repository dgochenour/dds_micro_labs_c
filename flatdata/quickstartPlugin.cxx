/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from quickstart.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "quickstart.h"
#include "reda/reda_bufferpool.h"
#include "xcdr/xcdr_interpreter.h"
#include "dds_c/dds_c_xcdr_type_plugin.h"
#include "quickstartPlugin.h"
#include "quickstartSupport.h"

/*** SOURCE_BEGIN ***/
#ifndef UNUSED_ARG
#define UNUSED_ARG(x) (void)(x)
#endif

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
Typed-endpoint support for C++:
* -------------------------------------------------------------------------- */

void* 
DimensionPlugin_create_typed_datawriter(void *writer)
{
    /* This function is only called from DDS_Publisher_create_datawriter
    * so writer is guaranteed to have a valid (i.e. non-NULL) value 
    */
    DDSDataWriter *cpp_writer = 
    new DimensionDataWriter((DDS_DataWriter*)writer);

    return cpp_writer;   
}

#ifndef RTI_CERT
void 
DimensionPlugin_delete_typed_datawriter(void *wrapper)
{
    /* This function is only called from DDS_Publisher_create_datawriter
    * and DDS_Publisher_delete_datawriter so wrapper is guaranteed to have
    * a valid (i.e. non-NULL) value 
    */
    DDSDataWriter_impl *cpp_writer = (DDSDataWriter_impl *) wrapper;

    DimensionDataWriter *t_writer = 
    static_cast<DimensionDataWriter *>(cpp_writer);

    delete t_writer;
}
#endif

void* 
DimensionPlugin_create_typed_datareader(void *reader)
{
    /* This function is only called from DDS_Subscriber_create_datareader
    * so reader is guaranteed to have a valid (i.e. non-NULL) value 
    */
    DDSDataReader *cpp_reader = 
    new DimensionDataReader((DDS_DataReader*)reader);

    return cpp_reader;      
}

#ifndef RTI_CERT
void
DimensionPlugin_delete_typed_datareader(void *wrapper)
{
    /* This function is only called from DDS_Subscriber_create_datareader
    * and DDS_Subscriber_delete_datareader so wrapper is guaranteed to have
    * a valid (i.e. non-NULL) value 
    */
    DDSDataReader_impl *cpp_reader = (DDSDataReader_impl *) wrapper;

    DimensionDataReader *t_reader = 
    static_cast<DimensionDataReader *>(cpp_reader);

    delete t_reader;
}
#endif

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
DimensionPlugin_create_sample(struct DDS_TypePlugin *plugin,
void **sample)
{
    UNUSED_ARG(plugin);

    *sample = Dimension::create_data();    
    return (*sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
DimensionPlugin_delete_sample(struct DDS_TypePlugin *plugin, 
void *sample)
{
    UNUSED_ARG(plugin);

    /* Dimension_delete() is a void function
    *  which expects (sample != NULL). Since 
    * DimensionPlugin_delete_sample
    * is an internal function, sample is assumed to be a valid pointer 
    */ 
    DimensionTypeSupport::delete_data((Dimension*)sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
DimensionPlugin_copy_sample(struct DDS_TypePlugin *plugin, 
void *dst, 
const void *src)
{
    UNUSED_ARG(plugin);

    return Dimension_copy(
        (Dimension*)dst,
        (const Dimension*)src);
}
/* --------------------------------------------------------------------------
*  Type Dimension Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation DimensionEncapsulationKind[] =
{ 
    {
        DDS_ENCAPSULATION_ID_CDR_LE,
        DDS_ENCAPSULATION_ID_CDR_BE,
        0
    }
};

NDDSCDREncapsulation DimensionV2EncapsulationKind[] =
{ 
    {

        DDS_ENCAPSULATION_ID_XCDR2_F_LE,
        DDS_ENCAPSULATION_ID_XCDR2_F_BE,
        0

    }
};

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
DimensionTypePlugin_initialize_sample(struct DDS_TypePlugin *plugin, void *buffer)
{

    UNUSED_ARG(plugin);
    Dimension* tdata = (Dimension*) buffer;
    struct RTIXCdrInterpreterPrograms *programs =
    rti::xcdr::type_programs<Dimension::Base>::get();
    UNUSED_ARG(plugin);
    if (!RTIXCdrFlatData_initializeSample(
        (char *)tdata->get_root_buffer(),
        Dimension::Offset::serialized_size(0),
        programs))
    {
        return RTI_FALSE;
    }
    return RTI_TRUE;

}

RTI_PRIVATE RTI_UINT32 
Dimension_get_user_sample_size(
    struct DDS_TypePlugin *tp)
{

    if (!tp->is_max_serialized_size_set)
    {
        RTI_UINT32 serialized_size = XCDRv2_StreamPlugin_get_serialized_sample_size(tp, NULL, 0) + RTI_XCDR_ENCAPSULATION_HEADER_SIZE;
        tp->is_max_serialized_size_set = RTI_TRUE;
        tp->max_serialized_size = serialized_size;
        return serialized_size;
    }
    else
    {
        return tp->max_serialized_size;
    }

}

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
Dimension_cdr_initialize(void *init_config, void *buffer)
{
    struct DDS_TypePluginDefault *plugin = (struct DDS_TypePluginDefault*)init_config;
    void *sample;
    struct DDS_TypePluginSampleHolder *sh = (struct DDS_TypePluginSampleHolder*)buffer;

    if (!DimensionPlugin_create_sample(&plugin->_parent,&sample))
    {
        return RTI_FALSE;
    }

    sh->sample = sample;

    return RTI_TRUE;
}

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
Dimension_cdr_finalize(void *finalize_config, void *buffer)
{
    struct DDS_TypePluginDefault *plugin = (struct DDS_TypePluginDefault*)finalize_config;
    struct DDS_TypePluginSampleHolder *sh = (struct DDS_TypePluginSampleHolder*)buffer;

    if (!DimensionPlugin_delete_sample(&plugin->_parent,sh->sample))
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_PRIVATE struct DDS_TypeMemoryPlugin*
DimensionXTypesHeapPlugin_create(struct DDS_TypePlugin *tp,
DDS_DomainParticipant *participant,
struct DDS_DomainParticipantQos *dp_qos,
DDS_TypePluginMode_T endpoint_mode,
DDS_TypePluginEndpoint *endpoint,
DDS_TypePluginEndpointQos *qos)
{
    return DDS_XTypesHeapPlugin_create(
        tp,
        participant,
        dp_qos,
        endpoint_mode,
        endpoint,
        qos,
        NULL,
        NULL,
        Dimension_cdr_initialize,
        Dimension_cdr_finalize,
        XCDRv2_StreamPlugin_get_serialized_sample_size(tp, NULL, 0) + RTI_XCDR_ENCAPSULATION_HEADER_SIZE,
        RTI_TRUE
        );
}

RTI_PRIVATE struct DDS_TypeMemoryI Dimension_fv_XTypesHeapPluginI =
{
    RTI_MEMORY_MANAGER_HEAP_MANAGED,
    RTI_MEMORY_TYPE_HEAP,
    DDS_XTypesHeapPlugin_create_sample,
    #ifndef RTI_CERT
    DDS_XTypesHeapPlugin_delete_sample,
    #else
    NULL,
    #endif
    NULL, /* get_address */
    NULL, /* return_address */
    NULL,
    DDS_XTypesHeapPlugin_get_sample_state,
    DDS_XTypesHeapPlugin_set_sample_state,
    DDS_XTypesHeapPlugin_is_owner,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    DimensionXTypesHeapPlugin_create,
    DDS_XTypesHeapPlugin_delete
};	

RTI_PRIVATE DDS_Boolean 
Dimension_on_type_registered(struct DDS_TypeImpl* type_impl)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    struct RTIXCdrInterpreterProgramsGenProperty programProperty =
    RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;

    programProperty.resolveAlias = RTI_XCDR_TRUE;
    programProperty.inlineStruct = RTI_XCDR_TRUE;
    programProperty.optimizeEnum = RTI_XCDR_TRUE;

    programs = RTIXCdrInterpreterPrograms_new(
        (RTIXCdrTypeCode *)DimensionPlainHelper_get_typecode(),
        &programProperty,
        RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN
        );

    if (programs == NULL)
    {
        return DDS_BOOLEAN_FALSE;
    }

    {
        DimensionPlainHelper* plain_helper = NULL;
        OSAPI_Heap_allocate_struct(&plain_helper, DimensionPlainHelper);
        DimensionPlainHelper_initialize(plain_helper);
        DDS_TypeImpl_set_sample(type_impl, plain_helper);
    }

    DDS_TypeImpl_set_programs(type_impl, programs);
    DDS_TypeImpl_set_typecode(type_impl,  Dimension_get_typecode());

    return DDS_BOOLEAN_TRUE;
}
RTI_PRIVATE DDS_Boolean 
Dimension_on_type_unregistered(struct DDS_TypeImpl* type_impl)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    programs = DDS_TypeImpl_get_programs(type_impl);

    if (programs != NULL) 
    {
        RTIXCdrInterpreterPrograms_delete(programs);
    }
    DDS_TypeImpl_set_programs(type_impl, NULL); 

    {
        DimensionPlainHelper* plain_helper = NULL;
        plain_helper = (DimensionPlainHelper*)DDS_TypeImpl_get_sample(type_impl);
        DimensionPlainHelper_finalize(plain_helper);
        OSAPI_Heap_free(plain_helper);
        DDS_TypeImpl_set_sample(type_impl, NULL);
    }

    return DDS_BOOLEAN_TRUE;   
}

RTI_PRIVATE RTI_BOOL 
Dimension_flatdata_serialize(struct DDS_TypePlugin *plugin,
struct CDR_Stream_t *stream, 
const void *void_sample,
DDS_InstanceHandle_t *destination)
{
    RTIXCdrStream xcdrStream;
    Dimension* sample = (Dimension*)void_sample;
    struct DDS_TypePluginBuffer* tp_buffer = (struct DDS_TypePluginBuffer*)stream->start_ptr;
    Dimension *flat_data_ptr = const_cast<Dimension *>(sample);
    UNUSED_ARG(plugin);
    UNUSED_ARG(destination);

    flat_data_ptr->initialize_stream(xcdrStream, 0, flat_data_ptr->buffer_size()); 

    /* At this point, the expection is that the encapsulation is already set. It can only
    * by either FINAL or MUTABLE. By default it is FINAL and during the creation of a mutable type
    * sets the encapsulation to MUTABLE. Appendable is not currently supported. 
    */

    /* Set the data_pbuffer to be the actual flat data sample (since it is in serialized format)
    */ 
    tp_buffer->data_pbuf.buffer = (char*)void_sample;
    tp_buffer->data_pbuf.max_length = xcdrStream._bufferLength;

    /* Increment the stream pointer to make it seem as if it was "serialized" */
    stream->buff_ptr += xcdrStream._bufferLength;

    return RTI_TRUE;
}
RTI_PRIVATE RTI_BOOL 
Dimension_flatdata_deserialize(struct DDS_TypePlugin *plugin,
void *void_sample,
struct CDR_Stream_t *stream,
DDS_InstanceHandle_t *source)
{
    RTI_UINT32 length_of_serialized_payload = 0;

    UNUSED_ARG(plugin);
    UNUSED_ARG(source);

    length_of_serialized_payload = stream->length - (RTI_UINT32)(stream->buff_ptr - stream->real_buff);

    /* Because we deserialize the encapsulation (and thus advancing the stream)
    * we need to subtract 4 bytes (encapsulation + encapsulation options)
    * from the current position.
    */

    OSAPI_Memory_copy(void_sample, stream->buff_ptr - 4, length_of_serialized_payload + 4);

    stream->buff_ptr += length_of_serialized_payload;

    return RTI_TRUE; 
}

RTI_PRIVATE struct DDS_TypeEncapsulationI Dimension_fv_XCDRv2FlatDataPluginI =
{
    DDS_XCDR2_DATA_REPRESENTATION,
    NULL,
    DimensionV2EncapsulationKind,
    RTI_MEMORY_TYPE_HEAP,
    RTI_MEMORY_MANAGER_HEAP_MANAGED,
    NULL,
    NULL,
    XCDR_GenericStreamPlugin_get_buffer,
    XCDR_GenericStreamPlugin_return_buffer,
    XCDR_GenericStreamPlugin_get_sample,

    XCDR_GenericStreamPlugin_return_sample,
    Dimension_flatdata_serialize,
    Dimension_flatdata_deserialize,
    XCDRv2_StreamPlugin_get_serialized_sample_size,
    XCDRv2_StreamPlugin_create,
    XCDRv2_StreamPlugin_delete,
};

RTI_PRIVATE struct DDS_TypeEncapsulationI *Dimension_fv_WirePlugins[] =
{
    &Dimension_fv_XCDRv2FlatDataPluginI,
    NULL
};

RTI_PRIVATE struct DDS_TypeMemoryI *Dimension_fv_MemoryPlugins[] =
{
    &Dimension_fv_XTypesHeapPluginI,

    NULL
};

RTI_PRIVATE struct DDS_TypePlugin*
DimensionTypePlugin_create_plugin(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_TypePluginMode_T endpoint_mode,
    DDS_TypePluginEndpoint *endpoint,
    DDS_TypePluginEndpointQos *qos,
    struct DDS_TypePluginProperty *const property);
RTI_PRIVATE RTI_BOOL
DimensionTypePlugin_delete_plugin(struct DDS_TypePlugin *plugin);

RTI_PRIVATE struct DDS_TypePluginI Dimension_fv_TypePluginI =
{
    /**************************************************************************
    *                   Type information functions
    **************************************************************************/

    NULL,                       /* DDS_TypeCode_t* */
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */

    NDDS_TYPEPLUGIN_EH_LOCATION_SAMPLE,
    Dimension_get_user_sample_size,   
    RTI_MEMORY_TYPE_HEAP,
    NULL,
    DimensionPlugin_copy_sample,

    DimensionTypePlugin_initialize_sample,

    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    Dimension_fv_MemoryPlugins,
    Dimension_fv_WirePlugins,

    /**************************************************************************
    *       Helper APIs to create language binding wrapper Functions
    **************************************************************************/

    DimensionPlugin_create_typed_datawriter,
    #ifndef RTI_CERT
    DimensionPlugin_delete_typed_datawriter,
    #else
    NULL,
    #endif
    DimensionPlugin_create_typed_datareader,
    #ifndef RTI_CERT
    DimensionPlugin_delete_typed_datareader,
    #else
    NULL,
    #endif
    DimensionTypePlugin_create_plugin,
    DimensionTypePlugin_delete_plugin,
    Dimension_on_type_registered,
    Dimension_on_type_unregistered,

};

/* --------------------------------------------------------------------------
*  Type Dimension Plugin Methods
* -------------------------------------------------------------------------- */

struct DDS_TypePluginI*
DimensionTypePlugin_get(void) 
{ 
    return &Dimension_fv_TypePluginI;
} 

RTI_PRIVATE struct DDS_TypePlugin*
DimensionTypePlugin_create_plugin(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_TypePluginMode_T endpoint_mode,
    DDS_TypePluginEndpoint *endpoint,
    DDS_TypePluginEndpointQos *qos,
    struct DDS_TypePluginProperty *const property)
{
    return DDS_TypePluginDefault_create(&Dimension_fv_TypePluginI,
    participant,dp_qos,
    endpoint_mode,endpoint,qos,
    property);
}

RTI_PRIVATE RTI_BOOL
DimensionTypePlugin_delete_plugin(struct DDS_TypePlugin *plugin)
{
    return DDS_TypePluginDefault_delete(plugin);
}

struct DDS_TypePlugin*
DimensionWriterTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataWriter *writer,
    struct DDS_DataWriterQos *qos,
    struct DDS_TypePluginProperty *property)
{
    return DDS_TypePlugin_create_w_intf(
        &Dimension_fv_TypePluginI,
        participant,dp_qos,
        DDS_TYPEPLUGIN_MODE_WRITER,
        (DDS_TypePluginEndpoint*)writer,
        (DDS_TypePluginEndpointQos*)qos,
        property);
}

struct DDS_TypePlugin*
DimensionReaderTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataReader *reader,
    struct DDS_DataReaderQos *qos,
    struct DDS_TypePluginProperty *property)
{
    return DDS_TypePlugin_create_w_intf(
        &Dimension_fv_TypePluginI,
        participant,dp_qos,
        DDS_TYPEPLUGIN_MODE_READER,
        (DDS_TypePluginEndpoint*)reader,
        (DDS_TypePluginEndpointQos*)qos,
        property);
}

const char*
DimensionTypePlugin_get_default_type_name(void) 
{ 
    return DimensionTYPENAME;
} 

NDDS_TypePluginKeyKind 
DimensionI_get_key_kind(void)
{
    return Dimension_fv_TypePluginI.key_kind;
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
Typed-endpoint support for C++:
* -------------------------------------------------------------------------- */

void* 
DimensionPlainHelperPlugin_create_typed_datawriter(void *writer)
{
    /* This function is only called from DDS_Publisher_create_datawriter
    * so writer is guaranteed to have a valid (i.e. non-NULL) value 
    */
    DDSDataWriter *cpp_writer = 
    new DimensionPlainHelperDataWriter((DDS_DataWriter*)writer);

    return cpp_writer;   
}

#ifndef RTI_CERT
void 
DimensionPlainHelperPlugin_delete_typed_datawriter(void *wrapper)
{
    /* This function is only called from DDS_Publisher_create_datawriter
    * and DDS_Publisher_delete_datawriter so wrapper is guaranteed to have
    * a valid (i.e. non-NULL) value 
    */
    DDSDataWriter_impl *cpp_writer = (DDSDataWriter_impl *) wrapper;

    DimensionPlainHelperDataWriter *t_writer = 
    static_cast<DimensionPlainHelperDataWriter *>(cpp_writer);

    delete t_writer;
}
#endif

void* 
DimensionPlainHelperPlugin_create_typed_datareader(void *reader)
{
    /* This function is only called from DDS_Subscriber_create_datareader
    * so reader is guaranteed to have a valid (i.e. non-NULL) value 
    */
    DDSDataReader *cpp_reader = 
    new DimensionPlainHelperDataReader((DDS_DataReader*)reader);

    return cpp_reader;      
}

#ifndef RTI_CERT
void
DimensionPlainHelperPlugin_delete_typed_datareader(void *wrapper)
{
    /* This function is only called from DDS_Subscriber_create_datareader
    * and DDS_Subscriber_delete_datareader so wrapper is guaranteed to have
    * a valid (i.e. non-NULL) value 
    */
    DDSDataReader_impl *cpp_reader = (DDSDataReader_impl *) wrapper;

    DimensionPlainHelperDataReader *t_reader = 
    static_cast<DimensionPlainHelperDataReader *>(cpp_reader);

    delete t_reader;
}
#endif

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
DimensionPlainHelperPlugin_create_sample(struct DDS_TypePlugin *plugin,
void **sample)
{
    UNUSED_ARG(plugin);

    *sample = (void *) DimensionPlainHelper_create();
    return (*sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
DimensionPlainHelperPlugin_delete_sample(struct DDS_TypePlugin *plugin, 
void *sample)
{
    UNUSED_ARG(plugin);

    DimensionPlainHelper_delete((DimensionPlainHelper *) sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
DimensionPlainHelperPlugin_copy_sample(struct DDS_TypePlugin *plugin, 
void *dst, 
const void *src)
{
    UNUSED_ARG(plugin);

    return DimensionPlainHelper_copy(
        (DimensionPlainHelper*)dst,
        (const DimensionPlainHelper*)src);
}
/* --------------------------------------------------------------------------
*  Type DimensionPlainHelper Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation DimensionPlainHelperEncapsulationKind[] =
{ 
    {
        DDS_ENCAPSULATION_ID_CDR_LE,
        DDS_ENCAPSULATION_ID_CDR_BE,
        0
    }
};

NDDSCDREncapsulation DimensionPlainHelperV2EncapsulationKind[] =
{ 
    {

        DDS_ENCAPSULATION_ID_XCDR2_F_LE,
        DDS_ENCAPSULATION_ID_XCDR2_F_BE,
        0

    }
};

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
DimensionPlainHelperTypePlugin_initialize_sample(struct DDS_TypePlugin *plugin, void *buffer)
{
    UNUSED_ARG(plugin);
    return DimensionPlainHelper_initialize((DimensionPlainHelper*)buffer);
}

RTI_PRIVATE RTI_UINT32 
DimensionPlainHelper_get_user_sample_size(
    struct DDS_TypePlugin *tp)
{
    UNUSED_ARG(tp);        
    return sizeof(DimensionPlainHelper);
}

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
DimensionPlainHelper_cdr_initialize(void *init_config, void *buffer)
{
    struct DDS_TypePluginDefault *plugin = (struct DDS_TypePluginDefault*)init_config;
    void *sample;
    struct DDS_TypePluginSampleHolder *sh = (struct DDS_TypePluginSampleHolder*)buffer;

    if (!DimensionPlainHelperPlugin_create_sample(&plugin->_parent,&sample))
    {
        return RTI_FALSE;
    }

    sh->sample = sample;

    return RTI_TRUE;
}

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
DimensionPlainHelper_cdr_finalize(void *finalize_config, void *buffer)
{
    struct DDS_TypePluginDefault *plugin = (struct DDS_TypePluginDefault*)finalize_config;
    struct DDS_TypePluginSampleHolder *sh = (struct DDS_TypePluginSampleHolder*)buffer;

    if (!DimensionPlainHelperPlugin_delete_sample(&plugin->_parent,sh->sample))
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_PRIVATE void 
DimensionPlainHelperTypePlugin_return_sample(
    struct DDS_TypePlugin *tp,
    struct DDS_TypePluginSampleHolder *sample)
{
    DimensionPlainHelper_finalize_optional_members((DimensionPlainHelper*)sample->sample, RTI_FALSE);
    XCDR_GenericStreamPlugin_return_sample(tp, sample);
}

RTI_PRIVATE struct DDS_TypeMemoryPlugin*
DimensionPlainHelperXTypesHeapPlugin_create(struct DDS_TypePlugin *tp,
DDS_DomainParticipant *participant,
struct DDS_DomainParticipantQos *dp_qos,
DDS_TypePluginMode_T endpoint_mode,
DDS_TypePluginEndpoint *endpoint,
DDS_TypePluginEndpointQos *qos)
{
    return DDS_XTypesHeapPlugin_create(
        tp,
        participant,
        dp_qos,
        endpoint_mode,
        endpoint,
        qos,
        NULL,
        NULL,
        DimensionPlainHelper_cdr_initialize,
        DimensionPlainHelper_cdr_finalize,
        sizeof(DimensionPlainHelper),
        RTI_FALSE
        );
}

RTI_PRIVATE struct DDS_TypeMemoryI DimensionPlainHelper_fv_XTypesHeapPluginI =
{
    RTI_MEMORY_MANAGER_HEAP,
    RTI_MEMORY_TYPE_HEAP,
    DimensionPlainHelperPlugin_create_sample,
    #ifndef RTI_CERT
    DimensionPlainHelperPlugin_delete_sample,
    #else
    NULL,
    #endif
    NULL, /* get_address */
    NULL, /* return_address */
    NULL,
    DDS_XTypesHeapPlugin_get_sample_state,
    DDS_XTypesHeapPlugin_set_sample_state,
    DDS_XTypesHeapPlugin_is_owner,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    DimensionPlainHelperXTypesHeapPlugin_create,
    DDS_XTypesHeapPlugin_delete
};	

RTI_PRIVATE DDS_Boolean 
DimensionPlainHelper_on_type_registered(struct DDS_TypeImpl* type_impl)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    struct RTIXCdrInterpreterProgramsGenProperty programProperty =
    RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;

    programProperty.resolveAlias = RTI_XCDR_TRUE;
    programProperty.inlineStruct = RTI_XCDR_TRUE;
    programProperty.optimizeEnum = RTI_XCDR_TRUE;

    programs = RTIXCdrInterpreterPrograms_new(
        (RTIXCdrTypeCode *)DimensionPlainHelper_get_typecode(),
        &programProperty,
        RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN
        );

    if (programs == NULL)
    {
        return DDS_BOOLEAN_FALSE;
    }

    DDS_TypeImpl_set_programs(type_impl, programs);
    DDS_TypeImpl_set_typecode(type_impl,  DimensionPlainHelper_get_typecode());

    return DDS_BOOLEAN_TRUE;
}
RTI_PRIVATE DDS_Boolean 
DimensionPlainHelper_on_type_unregistered(struct DDS_TypeImpl* type_impl)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    programs = DDS_TypeImpl_get_programs(type_impl);

    if (programs != NULL) 
    {
        RTIXCdrInterpreterPrograms_delete(programs);
    }
    DDS_TypeImpl_set_programs(type_impl, NULL); 

    return DDS_BOOLEAN_TRUE;   
}

RTI_PRIVATE struct DDS_TypeEncapsulationI DimensionPlainHelper_fv_XCDRv2PluginI =
{
    DDS_XCDR2_DATA_REPRESENTATION,
    NULL,
    DimensionPlainHelperV2EncapsulationKind,
    RTI_MEMORY_TYPE_HEAP,
    RTI_MEMORY_MANAGER_HEAP,
    NULL,
    NULL,
    XCDR_GenericStreamPlugin_get_buffer,
    XCDR_GenericStreamPlugin_return_buffer,
    XCDR_GenericStreamPlugin_get_sample,

    DimensionPlainHelperTypePlugin_return_sample,   
    XCDR_GenericStreamPlugin_serialize,
    XCDR_GenericStreamPlugin_deserialize,
    XCDRv2_StreamPlugin_get_serialized_sample_size,
    XCDRv2_StreamPlugin_create,
    XCDRv2_StreamPlugin_delete,
};

RTI_PRIVATE struct DDS_TypeEncapsulationI *DimensionPlainHelper_fv_WirePlugins[] =
{
    &DimensionPlainHelper_fv_XCDRv2PluginI,
    NULL
};

RTI_PRIVATE struct DDS_TypeMemoryI *DimensionPlainHelper_fv_MemoryPlugins[] =
{
    &DimensionPlainHelper_fv_XTypesHeapPluginI,

    NULL
};

RTI_PRIVATE struct DDS_TypePlugin*
DimensionPlainHelperTypePlugin_create_plugin(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_TypePluginMode_T endpoint_mode,
    DDS_TypePluginEndpoint *endpoint,
    DDS_TypePluginEndpointQos *qos,
    struct DDS_TypePluginProperty *const property);
RTI_PRIVATE RTI_BOOL
DimensionPlainHelperTypePlugin_delete_plugin(struct DDS_TypePlugin *plugin);

RTI_PRIVATE struct DDS_TypePluginI DimensionPlainHelper_fv_TypePluginI =
{
    /**************************************************************************
    *                   Type information functions
    **************************************************************************/

    NULL,                       /* DDS_TypeCode_t* */
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */

    NDDS_TYPEPLUGIN_EH_LOCATION_PAYLOAD,
    DimensionPlainHelper_get_user_sample_size,   
    RTI_MEMORY_TYPE_HEAP,
    NULL,
    DimensionPlainHelperPlugin_copy_sample,

    DimensionPlainHelperTypePlugin_initialize_sample,

    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    DimensionPlainHelper_fv_MemoryPlugins,
    DimensionPlainHelper_fv_WirePlugins,

    /**************************************************************************
    *       Helper APIs to create language binding wrapper Functions
    **************************************************************************/

    DimensionPlainHelperPlugin_create_typed_datawriter,
    #ifndef RTI_CERT
    DimensionPlainHelperPlugin_delete_typed_datawriter,
    #else
    NULL,
    #endif
    DimensionPlainHelperPlugin_create_typed_datareader,
    #ifndef RTI_CERT
    DimensionPlainHelperPlugin_delete_typed_datareader,
    #else
    NULL,
    #endif
    DimensionPlainHelperTypePlugin_create_plugin,
    DimensionPlainHelperTypePlugin_delete_plugin,
    DimensionPlainHelper_on_type_registered,
    DimensionPlainHelper_on_type_unregistered,

};

/* --------------------------------------------------------------------------
*  Type DimensionPlainHelper Plugin Methods
* -------------------------------------------------------------------------- */

struct DDS_TypePluginI*
DimensionPlainHelperTypePlugin_get(void) 
{ 
    return &DimensionPlainHelper_fv_TypePluginI;
} 

RTI_PRIVATE struct DDS_TypePlugin*
DimensionPlainHelperTypePlugin_create_plugin(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_TypePluginMode_T endpoint_mode,
    DDS_TypePluginEndpoint *endpoint,
    DDS_TypePluginEndpointQos *qos,
    struct DDS_TypePluginProperty *const property)
{
    return DDS_TypePluginDefault_create(&DimensionPlainHelper_fv_TypePluginI,
    participant,dp_qos,
    endpoint_mode,endpoint,qos,
    property);
}

RTI_PRIVATE RTI_BOOL
DimensionPlainHelperTypePlugin_delete_plugin(struct DDS_TypePlugin *plugin)
{
    return DDS_TypePluginDefault_delete(plugin);
}

struct DDS_TypePlugin*
DimensionPlainHelperWriterTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataWriter *writer,
    struct DDS_DataWriterQos *qos,
    struct DDS_TypePluginProperty *property)
{
    return DDS_TypePlugin_create_w_intf(
        &DimensionPlainHelper_fv_TypePluginI,
        participant,dp_qos,
        DDS_TYPEPLUGIN_MODE_WRITER,
        (DDS_TypePluginEndpoint*)writer,
        (DDS_TypePluginEndpointQos*)qos,
        property);
}

struct DDS_TypePlugin*
DimensionPlainHelperReaderTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataReader *reader,
    struct DDS_DataReaderQos *qos,
    struct DDS_TypePluginProperty *property)
{
    return DDS_TypePlugin_create_w_intf(
        &DimensionPlainHelper_fv_TypePluginI,
        participant,dp_qos,
        DDS_TYPEPLUGIN_MODE_READER,
        (DDS_TypePluginEndpoint*)reader,
        (DDS_TypePluginEndpointQos*)qos,
        property);
}

const char*
DimensionPlainHelperTypePlugin_get_default_type_name(void) 
{ 
    return DimensionPlainHelperTYPENAME;
} 

NDDS_TypePluginKeyKind 
DimensionPlainHelperI_get_key_kind(void)
{
    return DimensionPlainHelper_fv_TypePluginI.key_kind;
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
Typed-endpoint support for C++:
* -------------------------------------------------------------------------- */

void* 
ImagePlugin_create_typed_datawriter(void *writer)
{
    /* This function is only called from DDS_Publisher_create_datawriter
    * so writer is guaranteed to have a valid (i.e. non-NULL) value 
    */
    DDSDataWriter *cpp_writer = 
    new ImageDataWriter((DDS_DataWriter*)writer);

    return cpp_writer;   
}

#ifndef RTI_CERT
void 
ImagePlugin_delete_typed_datawriter(void *wrapper)
{
    /* This function is only called from DDS_Publisher_create_datawriter
    * and DDS_Publisher_delete_datawriter so wrapper is guaranteed to have
    * a valid (i.e. non-NULL) value 
    */
    DDSDataWriter_impl *cpp_writer = (DDSDataWriter_impl *) wrapper;

    ImageDataWriter *t_writer = 
    static_cast<ImageDataWriter *>(cpp_writer);

    delete t_writer;
}
#endif

void* 
ImagePlugin_create_typed_datareader(void *reader)
{
    /* This function is only called from DDS_Subscriber_create_datareader
    * so reader is guaranteed to have a valid (i.e. non-NULL) value 
    */
    DDSDataReader *cpp_reader = 
    new ImageDataReader((DDS_DataReader*)reader);

    return cpp_reader;      
}

#ifndef RTI_CERT
void
ImagePlugin_delete_typed_datareader(void *wrapper)
{
    /* This function is only called from DDS_Subscriber_create_datareader
    * and DDS_Subscriber_delete_datareader so wrapper is guaranteed to have
    * a valid (i.e. non-NULL) value 
    */
    DDSDataReader_impl *cpp_reader = (DDSDataReader_impl *) wrapper;

    ImageDataReader *t_reader = 
    static_cast<ImageDataReader *>(cpp_reader);

    delete t_reader;
}
#endif

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
ImagePlugin_create_sample(struct DDS_TypePlugin *plugin,
void **sample)
{
    UNUSED_ARG(plugin);

    *sample = Image::create_data();    
    return (*sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
ImagePlugin_delete_sample(struct DDS_TypePlugin *plugin, 
void *sample)
{
    UNUSED_ARG(plugin);

    /* Image_delete() is a void function
    *  which expects (sample != NULL). Since 
    * ImagePlugin_delete_sample
    * is an internal function, sample is assumed to be a valid pointer 
    */ 
    ImageTypeSupport::delete_data((Image*)sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
ImagePlugin_copy_sample(struct DDS_TypePlugin *plugin, 
void *dst, 
const void *src)
{
    UNUSED_ARG(plugin);

    return Image_copy(
        (Image*)dst,
        (const Image*)src);
}
/* --------------------------------------------------------------------------
*  Type Image Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation ImageEncapsulationKind[] =
{ 
    {
        DDS_ENCAPSULATION_ID_CDR_LE,
        DDS_ENCAPSULATION_ID_CDR_BE,
        0
    }
};

NDDSCDREncapsulation ImageV2EncapsulationKind[] =
{ 
    {

        DDS_ENCAPSULATION_ID_XCDR2_F_LE,
        DDS_ENCAPSULATION_ID_XCDR2_F_BE,
        0

    }
};

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
ImageTypePlugin_initialize_sample(struct DDS_TypePlugin *plugin, void *buffer)
{

    UNUSED_ARG(plugin);
    Image* tdata = (Image*) buffer;
    struct RTIXCdrInterpreterPrograms *programs =
    rti::xcdr::type_programs<Image::Base>::get();
    UNUSED_ARG(plugin);
    if (!RTIXCdrFlatData_initializeSample(
        (char *)tdata->get_root_buffer(),
        Image::Offset::serialized_size(0),
        programs))
    {
        return RTI_FALSE;
    }
    return RTI_TRUE;

}

RTI_PRIVATE RTI_UINT32 
Image_get_user_sample_size(
    struct DDS_TypePlugin *tp)
{

    if (!tp->is_max_serialized_size_set)
    {
        RTI_UINT32 serialized_size = XCDRv2_StreamPlugin_get_serialized_sample_size(tp, NULL, 0) + RTI_XCDR_ENCAPSULATION_HEADER_SIZE;
        tp->is_max_serialized_size_set = RTI_TRUE;
        tp->max_serialized_size = serialized_size;
        return serialized_size;
    }
    else
    {
        return tp->max_serialized_size;
    }

}

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
Image_cdr_initialize(void *init_config, void *buffer)
{
    struct DDS_TypePluginDefault *plugin = (struct DDS_TypePluginDefault*)init_config;
    void *sample;
    struct DDS_TypePluginSampleHolder *sh = (struct DDS_TypePluginSampleHolder*)buffer;

    if (!ImagePlugin_create_sample(&plugin->_parent,&sample))
    {
        return RTI_FALSE;
    }

    sh->sample = sample;

    return RTI_TRUE;
}

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
Image_cdr_finalize(void *finalize_config, void *buffer)
{
    struct DDS_TypePluginDefault *plugin = (struct DDS_TypePluginDefault*)finalize_config;
    struct DDS_TypePluginSampleHolder *sh = (struct DDS_TypePluginSampleHolder*)buffer;

    if (!ImagePlugin_delete_sample(&plugin->_parent,sh->sample))
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_PRIVATE struct DDS_TypeMemoryPlugin*
ImageXTypesHeapPlugin_create(struct DDS_TypePlugin *tp,
DDS_DomainParticipant *participant,
struct DDS_DomainParticipantQos *dp_qos,
DDS_TypePluginMode_T endpoint_mode,
DDS_TypePluginEndpoint *endpoint,
DDS_TypePluginEndpointQos *qos)
{
    return DDS_XTypesHeapPlugin_create(
        tp,
        participant,
        dp_qos,
        endpoint_mode,
        endpoint,
        qos,
        NULL,
        NULL,
        Image_cdr_initialize,
        Image_cdr_finalize,
        XCDRv2_StreamPlugin_get_serialized_sample_size(tp, NULL, 0) + RTI_XCDR_ENCAPSULATION_HEADER_SIZE,
        RTI_TRUE
        );
}

RTI_PRIVATE struct DDS_TypeMemoryI Image_fv_XTypesHeapPluginI =
{
    RTI_MEMORY_MANAGER_HEAP_MANAGED,
    RTI_MEMORY_TYPE_HEAP,
    DDS_XTypesHeapPlugin_create_sample,
    #ifndef RTI_CERT
    DDS_XTypesHeapPlugin_delete_sample,
    #else
    NULL,
    #endif
    NULL, /* get_address */
    NULL, /* return_address */
    NULL,
    DDS_XTypesHeapPlugin_get_sample_state,
    DDS_XTypesHeapPlugin_set_sample_state,
    DDS_XTypesHeapPlugin_is_owner,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    ImageXTypesHeapPlugin_create,
    DDS_XTypesHeapPlugin_delete
};	

RTI_PRIVATE DDS_Boolean 
Image_on_type_registered(struct DDS_TypeImpl* type_impl)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    struct RTIXCdrInterpreterProgramsGenProperty programProperty =
    RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;

    programProperty.resolveAlias = RTI_XCDR_TRUE;
    programProperty.inlineStruct = RTI_XCDR_TRUE;
    programProperty.optimizeEnum = RTI_XCDR_TRUE;

    programs = RTIXCdrInterpreterPrograms_new(
        (RTIXCdrTypeCode *)ImagePlainHelper_get_typecode(),
        &programProperty,
        RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN
        );

    if (programs == NULL)
    {
        return DDS_BOOLEAN_FALSE;
    }

    {
        ImagePlainHelper* plain_helper = NULL;
        OSAPI_Heap_allocate_struct(&plain_helper, ImagePlainHelper);
        ImagePlainHelper_initialize(plain_helper);
        DDS_TypeImpl_set_sample(type_impl, plain_helper);
    }

    DDS_TypeImpl_set_programs(type_impl, programs);
    DDS_TypeImpl_set_typecode(type_impl,  Image_get_typecode());

    return DDS_BOOLEAN_TRUE;
}
RTI_PRIVATE DDS_Boolean 
Image_on_type_unregistered(struct DDS_TypeImpl* type_impl)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    programs = DDS_TypeImpl_get_programs(type_impl);

    if (programs != NULL) 
    {
        RTIXCdrInterpreterPrograms_delete(programs);
    }
    DDS_TypeImpl_set_programs(type_impl, NULL); 

    {
        ImagePlainHelper* plain_helper = NULL;
        plain_helper = (ImagePlainHelper*)DDS_TypeImpl_get_sample(type_impl);
        ImagePlainHelper_finalize(plain_helper);
        OSAPI_Heap_free(plain_helper);
        DDS_TypeImpl_set_sample(type_impl, NULL);
    }

    return DDS_BOOLEAN_TRUE;   
}

RTI_PRIVATE RTI_BOOL 
Image_flatdata_serialize(struct DDS_TypePlugin *plugin,
struct CDR_Stream_t *stream, 
const void *void_sample,
DDS_InstanceHandle_t *destination)
{
    RTIXCdrStream xcdrStream;
    Image* sample = (Image*)void_sample;
    struct DDS_TypePluginBuffer* tp_buffer = (struct DDS_TypePluginBuffer*)stream->start_ptr;
    Image *flat_data_ptr = const_cast<Image *>(sample);
    UNUSED_ARG(plugin);
    UNUSED_ARG(destination);

    flat_data_ptr->initialize_stream(xcdrStream, 0, flat_data_ptr->buffer_size()); 

    /* At this point, the expection is that the encapsulation is already set. It can only
    * by either FINAL or MUTABLE. By default it is FINAL and during the creation of a mutable type
    * sets the encapsulation to MUTABLE. Appendable is not currently supported. 
    */

    /* Set the data_pbuffer to be the actual flat data sample (since it is in serialized format)
    */ 
    tp_buffer->data_pbuf.buffer = (char*)void_sample;
    tp_buffer->data_pbuf.max_length = xcdrStream._bufferLength;

    /* Increment the stream pointer to make it seem as if it was "serialized" */
    stream->buff_ptr += xcdrStream._bufferLength;

    return RTI_TRUE;
}
RTI_PRIVATE RTI_BOOL 
Image_flatdata_deserialize(struct DDS_TypePlugin *plugin,
void *void_sample,
struct CDR_Stream_t *stream,
DDS_InstanceHandle_t *source)
{
    RTI_UINT32 length_of_serialized_payload = 0;

    UNUSED_ARG(plugin);
    UNUSED_ARG(source);

    length_of_serialized_payload = stream->length - (RTI_UINT32)(stream->buff_ptr - stream->real_buff);

    /* Because we deserialize the encapsulation (and thus advancing the stream)
    * we need to subtract 4 bytes (encapsulation + encapsulation options)
    * from the current position.
    */

    OSAPI_Memory_copy(void_sample, stream->buff_ptr - 4, length_of_serialized_payload + 4);

    stream->buff_ptr += length_of_serialized_payload;

    return RTI_TRUE; 
}

RTI_PRIVATE struct DDS_TypeEncapsulationI Image_fv_XCDRv2FlatDataPluginI =
{
    DDS_XCDR2_DATA_REPRESENTATION,
    NULL,
    ImageV2EncapsulationKind,
    RTI_MEMORY_TYPE_HEAP,
    RTI_MEMORY_MANAGER_HEAP_MANAGED,
    NULL,
    NULL,
    XCDR_GenericStreamPlugin_get_buffer,
    XCDR_GenericStreamPlugin_return_buffer,
    XCDR_GenericStreamPlugin_get_sample,

    XCDR_GenericStreamPlugin_return_sample,
    Image_flatdata_serialize,
    Image_flatdata_deserialize,
    XCDRv2_StreamPlugin_get_serialized_sample_size,
    XCDRv2_StreamPlugin_create,
    XCDRv2_StreamPlugin_delete,
};

RTI_PRIVATE struct DDS_TypeEncapsulationI *Image_fv_WirePlugins[] =
{
    &Image_fv_XCDRv2FlatDataPluginI,
    NULL
};

RTI_PRIVATE struct DDS_TypeMemoryI *Image_fv_MemoryPlugins[] =
{
    &Image_fv_XTypesHeapPluginI,

    NULL
};

RTI_PRIVATE struct DDS_TypePlugin*
ImageTypePlugin_create_plugin(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_TypePluginMode_T endpoint_mode,
    DDS_TypePluginEndpoint *endpoint,
    DDS_TypePluginEndpointQos *qos,
    struct DDS_TypePluginProperty *const property);
RTI_PRIVATE RTI_BOOL
ImageTypePlugin_delete_plugin(struct DDS_TypePlugin *plugin);

RTI_PRIVATE struct DDS_TypePluginI Image_fv_TypePluginI =
{
    /**************************************************************************
    *                   Type information functions
    **************************************************************************/

    NULL,                       /* DDS_TypeCode_t* */
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */

    NDDS_TYPEPLUGIN_EH_LOCATION_SAMPLE,
    Image_get_user_sample_size,   
    RTI_MEMORY_TYPE_HEAP,
    NULL,
    ImagePlugin_copy_sample,

    ImageTypePlugin_initialize_sample,

    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    Image_fv_MemoryPlugins,
    Image_fv_WirePlugins,

    /**************************************************************************
    *       Helper APIs to create language binding wrapper Functions
    **************************************************************************/

    ImagePlugin_create_typed_datawriter,
    #ifndef RTI_CERT
    ImagePlugin_delete_typed_datawriter,
    #else
    NULL,
    #endif
    ImagePlugin_create_typed_datareader,
    #ifndef RTI_CERT
    ImagePlugin_delete_typed_datareader,
    #else
    NULL,
    #endif
    ImageTypePlugin_create_plugin,
    ImageTypePlugin_delete_plugin,
    Image_on_type_registered,
    Image_on_type_unregistered,

};

/* --------------------------------------------------------------------------
*  Type Image Plugin Methods
* -------------------------------------------------------------------------- */

struct DDS_TypePluginI*
ImageTypePlugin_get(void) 
{ 
    return &Image_fv_TypePluginI;
} 

RTI_PRIVATE struct DDS_TypePlugin*
ImageTypePlugin_create_plugin(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_TypePluginMode_T endpoint_mode,
    DDS_TypePluginEndpoint *endpoint,
    DDS_TypePluginEndpointQos *qos,
    struct DDS_TypePluginProperty *const property)
{
    return DDS_TypePluginDefault_create(&Image_fv_TypePluginI,
    participant,dp_qos,
    endpoint_mode,endpoint,qos,
    property);
}

RTI_PRIVATE RTI_BOOL
ImageTypePlugin_delete_plugin(struct DDS_TypePlugin *plugin)
{
    return DDS_TypePluginDefault_delete(plugin);
}

struct DDS_TypePlugin*
ImageWriterTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataWriter *writer,
    struct DDS_DataWriterQos *qos,
    struct DDS_TypePluginProperty *property)
{
    return DDS_TypePlugin_create_w_intf(
        &Image_fv_TypePluginI,
        participant,dp_qos,
        DDS_TYPEPLUGIN_MODE_WRITER,
        (DDS_TypePluginEndpoint*)writer,
        (DDS_TypePluginEndpointQos*)qos,
        property);
}

struct DDS_TypePlugin*
ImageReaderTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataReader *reader,
    struct DDS_DataReaderQos *qos,
    struct DDS_TypePluginProperty *property)
{
    return DDS_TypePlugin_create_w_intf(
        &Image_fv_TypePluginI,
        participant,dp_qos,
        DDS_TYPEPLUGIN_MODE_READER,
        (DDS_TypePluginEndpoint*)reader,
        (DDS_TypePluginEndpointQos*)qos,
        property);
}

const char*
ImageTypePlugin_get_default_type_name(void) 
{ 
    return ImageTYPENAME;
} 

NDDS_TypePluginKeyKind 
ImageI_get_key_kind(void)
{
    return Image_fv_TypePluginI.key_kind;
}

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */

/* --------------------------------------------------------------------------
Typed-endpoint support for C++:
* -------------------------------------------------------------------------- */

void* 
ImagePlainHelperPlugin_create_typed_datawriter(void *writer)
{
    /* This function is only called from DDS_Publisher_create_datawriter
    * so writer is guaranteed to have a valid (i.e. non-NULL) value 
    */
    DDSDataWriter *cpp_writer = 
    new ImagePlainHelperDataWriter((DDS_DataWriter*)writer);

    return cpp_writer;   
}

#ifndef RTI_CERT
void 
ImagePlainHelperPlugin_delete_typed_datawriter(void *wrapper)
{
    /* This function is only called from DDS_Publisher_create_datawriter
    * and DDS_Publisher_delete_datawriter so wrapper is guaranteed to have
    * a valid (i.e. non-NULL) value 
    */
    DDSDataWriter_impl *cpp_writer = (DDSDataWriter_impl *) wrapper;

    ImagePlainHelperDataWriter *t_writer = 
    static_cast<ImagePlainHelperDataWriter *>(cpp_writer);

    delete t_writer;
}
#endif

void* 
ImagePlainHelperPlugin_create_typed_datareader(void *reader)
{
    /* This function is only called from DDS_Subscriber_create_datareader
    * so reader is guaranteed to have a valid (i.e. non-NULL) value 
    */
    DDSDataReader *cpp_reader = 
    new ImagePlainHelperDataReader((DDS_DataReader*)reader);

    return cpp_reader;      
}

#ifndef RTI_CERT
void
ImagePlainHelperPlugin_delete_typed_datareader(void *wrapper)
{
    /* This function is only called from DDS_Subscriber_create_datareader
    * and DDS_Subscriber_delete_datareader so wrapper is guaranteed to have
    * a valid (i.e. non-NULL) value 
    */
    DDSDataReader_impl *cpp_reader = (DDSDataReader_impl *) wrapper;

    ImagePlainHelperDataReader *t_reader = 
    static_cast<ImagePlainHelperDataReader *>(cpp_reader);

    delete t_reader;
}
#endif

/* --------------------------------------------------------------------------
*  Sample Support functions:
* -------------------------------------------------------------------------- */
RTI_BOOL
ImagePlainHelperPlugin_create_sample(struct DDS_TypePlugin *plugin,
void **sample)
{
    UNUSED_ARG(plugin);

    *sample = (void *) ImagePlainHelper_create();
    return (*sample != NULL);
}

#ifndef RTI_CERT
RTI_BOOL
ImagePlainHelperPlugin_delete_sample(struct DDS_TypePlugin *plugin, 
void *sample)
{
    UNUSED_ARG(plugin);

    ImagePlainHelper_delete((ImagePlainHelper *) sample);
    return RTI_TRUE;
}
#endif

RTI_BOOL 
ImagePlainHelperPlugin_copy_sample(struct DDS_TypePlugin *plugin, 
void *dst, 
const void *src)
{
    UNUSED_ARG(plugin);

    return ImagePlainHelper_copy(
        (ImagePlainHelper*)dst,
        (const ImagePlainHelper*)src);
}
/* --------------------------------------------------------------------------
*  Type ImagePlainHelper Plugin Instantiation
* -------------------------------------------------------------------------- */

NDDSCDREncapsulation ImagePlainHelperEncapsulationKind[] =
{ 
    {
        DDS_ENCAPSULATION_ID_CDR_LE,
        DDS_ENCAPSULATION_ID_CDR_BE,
        0
    }
};

NDDSCDREncapsulation ImagePlainHelperV2EncapsulationKind[] =
{ 
    {

        DDS_ENCAPSULATION_ID_XCDR2_F_LE,
        DDS_ENCAPSULATION_ID_XCDR2_F_BE,
        0

    }
};

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
ImagePlainHelperTypePlugin_initialize_sample(struct DDS_TypePlugin *plugin, void *buffer)
{
    UNUSED_ARG(plugin);
    return ImagePlainHelper_initialize((ImagePlainHelper*)buffer);
}

RTI_PRIVATE RTI_UINT32 
ImagePlainHelper_get_user_sample_size(
    struct DDS_TypePlugin *tp)
{
    UNUSED_ARG(tp);        
    return sizeof(ImagePlainHelper);
}

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
ImagePlainHelper_cdr_initialize(void *init_config, void *buffer)
{
    struct DDS_TypePluginDefault *plugin = (struct DDS_TypePluginDefault*)init_config;
    void *sample;
    struct DDS_TypePluginSampleHolder *sh = (struct DDS_TypePluginSampleHolder*)buffer;

    if (!ImagePlainHelperPlugin_create_sample(&plugin->_parent,&sample))
    {
        return RTI_FALSE;
    }

    sh->sample = sample;

    return RTI_TRUE;
}

MUST_CHECK_RETURN RTI_PRIVATE RTI_BOOL
ImagePlainHelper_cdr_finalize(void *finalize_config, void *buffer)
{
    struct DDS_TypePluginDefault *plugin = (struct DDS_TypePluginDefault*)finalize_config;
    struct DDS_TypePluginSampleHolder *sh = (struct DDS_TypePluginSampleHolder*)buffer;

    if (!ImagePlainHelperPlugin_delete_sample(&plugin->_parent,sh->sample))
    {
        return RTI_FALSE;
    }

    return RTI_TRUE;
}

RTI_PRIVATE void 
ImagePlainHelperTypePlugin_return_sample(
    struct DDS_TypePlugin *tp,
    struct DDS_TypePluginSampleHolder *sample)
{
    ImagePlainHelper_finalize_optional_members((ImagePlainHelper*)sample->sample, RTI_FALSE);
    XCDR_GenericStreamPlugin_return_sample(tp, sample);
}

RTI_PRIVATE struct DDS_TypeMemoryPlugin*
ImagePlainHelperXTypesHeapPlugin_create(struct DDS_TypePlugin *tp,
DDS_DomainParticipant *participant,
struct DDS_DomainParticipantQos *dp_qos,
DDS_TypePluginMode_T endpoint_mode,
DDS_TypePluginEndpoint *endpoint,
DDS_TypePluginEndpointQos *qos)
{
    return DDS_XTypesHeapPlugin_create(
        tp,
        participant,
        dp_qos,
        endpoint_mode,
        endpoint,
        qos,
        NULL,
        NULL,
        ImagePlainHelper_cdr_initialize,
        ImagePlainHelper_cdr_finalize,
        sizeof(ImagePlainHelper),
        RTI_FALSE
        );
}

RTI_PRIVATE struct DDS_TypeMemoryI ImagePlainHelper_fv_XTypesHeapPluginI =
{
    RTI_MEMORY_MANAGER_HEAP,
    RTI_MEMORY_TYPE_HEAP,
    ImagePlainHelperPlugin_create_sample,
    #ifndef RTI_CERT
    ImagePlainHelperPlugin_delete_sample,
    #else
    NULL,
    #endif
    NULL, /* get_address */
    NULL, /* return_address */
    NULL,
    DDS_XTypesHeapPlugin_get_sample_state,
    DDS_XTypesHeapPlugin_set_sample_state,
    DDS_XTypesHeapPlugin_is_owner,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    ImagePlainHelperXTypesHeapPlugin_create,
    DDS_XTypesHeapPlugin_delete
};	

RTI_PRIVATE DDS_Boolean 
ImagePlainHelper_on_type_registered(struct DDS_TypeImpl* type_impl)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    struct RTIXCdrInterpreterProgramsGenProperty programProperty =
    RTIXCdrInterpreterProgramsGenProperty_INITIALIZER;

    programProperty.resolveAlias = RTI_XCDR_TRUE;
    programProperty.inlineStruct = RTI_XCDR_TRUE;
    programProperty.optimizeEnum = RTI_XCDR_TRUE;

    programs = RTIXCdrInterpreterPrograms_new(
        (RTIXCdrTypeCode *)ImagePlainHelper_get_typecode(),
        &programProperty,
        RTI_XCDR_PROGRAM_MASK_TYPEPLUGIN
        );

    if (programs == NULL)
    {
        return DDS_BOOLEAN_FALSE;
    }

    DDS_TypeImpl_set_programs(type_impl, programs);
    DDS_TypeImpl_set_typecode(type_impl,  ImagePlainHelper_get_typecode());

    return DDS_BOOLEAN_TRUE;
}
RTI_PRIVATE DDS_Boolean 
ImagePlainHelper_on_type_unregistered(struct DDS_TypeImpl* type_impl)
{
    struct RTIXCdrInterpreterPrograms *programs = NULL;
    programs = DDS_TypeImpl_get_programs(type_impl);

    if (programs != NULL) 
    {
        RTIXCdrInterpreterPrograms_delete(programs);
    }
    DDS_TypeImpl_set_programs(type_impl, NULL); 

    return DDS_BOOLEAN_TRUE;   
}

RTI_PRIVATE struct DDS_TypeEncapsulationI ImagePlainHelper_fv_XCDRv2PluginI =
{
    DDS_XCDR2_DATA_REPRESENTATION,
    NULL,
    ImagePlainHelperV2EncapsulationKind,
    RTI_MEMORY_TYPE_HEAP,
    RTI_MEMORY_MANAGER_HEAP,
    NULL,
    NULL,
    XCDR_GenericStreamPlugin_get_buffer,
    XCDR_GenericStreamPlugin_return_buffer,
    XCDR_GenericStreamPlugin_get_sample,

    ImagePlainHelperTypePlugin_return_sample,   
    XCDR_GenericStreamPlugin_serialize,
    XCDR_GenericStreamPlugin_deserialize,
    XCDRv2_StreamPlugin_get_serialized_sample_size,
    XCDRv2_StreamPlugin_create,
    XCDRv2_StreamPlugin_delete,
};

RTI_PRIVATE struct DDS_TypeEncapsulationI *ImagePlainHelper_fv_WirePlugins[] =
{
    &ImagePlainHelper_fv_XCDRv2PluginI,
    NULL
};

RTI_PRIVATE struct DDS_TypeMemoryI *ImagePlainHelper_fv_MemoryPlugins[] =
{
    &ImagePlainHelper_fv_XTypesHeapPluginI,

    NULL
};

RTI_PRIVATE struct DDS_TypePlugin*
ImagePlainHelperTypePlugin_create_plugin(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_TypePluginMode_T endpoint_mode,
    DDS_TypePluginEndpoint *endpoint,
    DDS_TypePluginEndpointQos *qos,
    struct DDS_TypePluginProperty *const property);
RTI_PRIVATE RTI_BOOL
ImagePlainHelperTypePlugin_delete_plugin(struct DDS_TypePlugin *plugin);

RTI_PRIVATE struct DDS_TypePluginI ImagePlainHelper_fv_TypePluginI =
{
    /**************************************************************************
    *                   Type information functions
    **************************************************************************/

    NULL,                       /* DDS_TypeCode_t* */
    NDDS_TYPEPLUGIN_NO_KEY,     /* NDDS_TypePluginKeyKind */

    NDDS_TYPEPLUGIN_EH_LOCATION_PAYLOAD,
    ImagePlainHelper_get_user_sample_size,   
    RTI_MEMORY_TYPE_HEAP,
    NULL,
    ImagePlainHelperPlugin_copy_sample,

    ImagePlainHelperTypePlugin_initialize_sample,

    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    ImagePlainHelper_fv_MemoryPlugins,
    ImagePlainHelper_fv_WirePlugins,

    /**************************************************************************
    *       Helper APIs to create language binding wrapper Functions
    **************************************************************************/

    ImagePlainHelperPlugin_create_typed_datawriter,
    #ifndef RTI_CERT
    ImagePlainHelperPlugin_delete_typed_datawriter,
    #else
    NULL,
    #endif
    ImagePlainHelperPlugin_create_typed_datareader,
    #ifndef RTI_CERT
    ImagePlainHelperPlugin_delete_typed_datareader,
    #else
    NULL,
    #endif
    ImagePlainHelperTypePlugin_create_plugin,
    ImagePlainHelperTypePlugin_delete_plugin,
    ImagePlainHelper_on_type_registered,
    ImagePlainHelper_on_type_unregistered,

};

/* --------------------------------------------------------------------------
*  Type ImagePlainHelper Plugin Methods
* -------------------------------------------------------------------------- */

struct DDS_TypePluginI*
ImagePlainHelperTypePlugin_get(void) 
{ 
    return &ImagePlainHelper_fv_TypePluginI;
} 

RTI_PRIVATE struct DDS_TypePlugin*
ImagePlainHelperTypePlugin_create_plugin(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_TypePluginMode_T endpoint_mode,
    DDS_TypePluginEndpoint *endpoint,
    DDS_TypePluginEndpointQos *qos,
    struct DDS_TypePluginProperty *const property)
{
    return DDS_TypePluginDefault_create(&ImagePlainHelper_fv_TypePluginI,
    participant,dp_qos,
    endpoint_mode,endpoint,qos,
    property);
}

RTI_PRIVATE RTI_BOOL
ImagePlainHelperTypePlugin_delete_plugin(struct DDS_TypePlugin *plugin)
{
    return DDS_TypePluginDefault_delete(plugin);
}

struct DDS_TypePlugin*
ImagePlainHelperWriterTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataWriter *writer,
    struct DDS_DataWriterQos *qos,
    struct DDS_TypePluginProperty *property)
{
    return DDS_TypePlugin_create_w_intf(
        &ImagePlainHelper_fv_TypePluginI,
        participant,dp_qos,
        DDS_TYPEPLUGIN_MODE_WRITER,
        (DDS_TypePluginEndpoint*)writer,
        (DDS_TypePluginEndpointQos*)qos,
        property);
}

struct DDS_TypePlugin*
ImagePlainHelperReaderTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataReader *reader,
    struct DDS_DataReaderQos *qos,
    struct DDS_TypePluginProperty *property)
{
    return DDS_TypePlugin_create_w_intf(
        &ImagePlainHelper_fv_TypePluginI,
        participant,dp_qos,
        DDS_TYPEPLUGIN_MODE_READER,
        (DDS_TypePluginEndpoint*)reader,
        (DDS_TypePluginEndpointQos*)qos,
        property);
}

const char*
ImagePlainHelperTypePlugin_get_default_type_name(void) 
{ 
    return ImagePlainHelperTYPENAME;
} 

NDDS_TypePluginKeyKind 
ImagePlainHelperI_get_key_kind(void)
{
    return ImagePlainHelper_fv_TypePluginI.key_kind;
}

