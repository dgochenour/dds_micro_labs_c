/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from quickstart.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#include "quickstart.h"

#ifndef UNUSED_ARG
#define UNUSED_ARG(x) (void)(x)
#endif

#include "dds_c/dds_c_typecode.h"
/*** SOURCE_BEGIN ***/

Dimension *
Dimension_create(void)
{
    Dimension* sample;
    OSAPI_Heap_allocate_struct(&sample, Dimension);
    if (sample != NULL) {
        if (!Dimension_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}
void
Dimension_delete(Dimension*sample)
{
    if (sample != NULL) {
        /* Dimension_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        Dimension_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}

RTI_BOOL
Dimension_finalize(Dimension* sample)
{
    UNUSED_ARG(sample);
    return RTI_FALSE;
}

RTI_BOOL
Dimension_copy(Dimension* dst,const Dimension* src)
{        
    UNUSED_ARG(dst);
    UNUSED_ARG(src);
    return RTI_FALSE;
}

/* ========================================================================= */
const char *DimensionTYPENAME = "Dimension";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* Dimension_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member Dimension_g_tc_members[2]=
    {

        {
            (char *)"width",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"height",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Dimension_g_tc =
    {{
            DDS_TK_STRUCT| DDS_TK_FINAL_EXTENSIBILITY| DDS_TK_FLAT_DATA_LANGUAGE_BINDING, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Dimension", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            Dimension_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Dimension*/

    if (is_initialized) {
        return &Dimension_g_tc;
    }

    Dimension_g_tc._data._annotations._allowedDataRepresentationMask = 4;

    Dimension_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    Dimension_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

    /* Initialize the values for member annotations. */
    Dimension_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
    Dimension_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0;
    Dimension_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
    Dimension_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
    Dimension_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
    Dimension_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

    Dimension_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
    Dimension_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0;
    Dimension_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
    Dimension_g_tc_members[1]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
    Dimension_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
    Dimension_g_tc_members[1]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

    Dimension_g_tc._data._sampleAccessInfo =
    Dimension_get_sample_access_info();
    Dimension_g_tc._data._typePlugin =
    Dimension_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Dimension_g_tc;
}

RTIXCdrSampleAccessInfo *Dimension_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo Dimension_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Dimension_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Dimension_g_sampleAccessInfo;
    }

    Dimension_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) 0;
    Dimension_g_memberAccessInfos[0].bindingMemberValueOffset[1] = 
    (RTIXCdrUnsignedLong) 0;
    Dimension_g_memberAccessInfos[0].bindingMemberValueOffset[2] = 
    (RTIXCdrUnsignedLong) 0;
    Dimension_g_memberAccessInfos[0].bindingMemberValueOffset[3] = 
    (RTIXCdrUnsignedLong) 0;

    Dimension_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) 2;
    Dimension_g_memberAccessInfos[1].bindingMemberValueOffset[1] = 
    (RTIXCdrUnsignedLong) 2;
    Dimension_g_memberAccessInfos[1].bindingMemberValueOffset[2] = 
    (RTIXCdrUnsignedLong) 2;
    Dimension_g_memberAccessInfos[1].bindingMemberValueOffset[3] = 
    (RTIXCdrUnsignedLong) 2;

    Dimension_g_sampleAccessInfo.memberAccessInfos = 
    Dimension_g_memberAccessInfos;

    Dimension_g_sampleAccessInfo.typeSize[0] = (RTIXCdrUnsignedLong) 
    DimensionOffset::serialized_size(0);
    Dimension_g_sampleAccessInfo.typeSize[1] = (RTIXCdrUnsignedLong) 
    DimensionOffset::serialized_size(1);
    Dimension_g_sampleAccessInfo.typeSize[2] = (RTIXCdrUnsignedLong) 
    DimensionOffset::serialized_size(2);
    Dimension_g_sampleAccessInfo.typeSize[3] = (RTIXCdrUnsignedLong) 
    DimensionOffset::serialized_size(3);   

    Dimension_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_FLAT_DATA_CPP ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Dimension_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Dimension_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Dimension_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        NULL,
        NULL,
        NULL,
        NULL
    };

    return &Dimension_g_typePlugin;
}
#endif

Dimension * Dimension::create_data()
{
    return static_cast<Dimension *>(Base::create_data());
}

DDS_UnsignedShort DimensionConstOffset::width() const
{
    static const rti::flat::offset_t offsets[] = {0, 0, 0, 0};
    return deserialize<DDS_UnsignedShort >(offsets);
}

DDS_UnsignedShort DimensionConstOffset::height() const
{
    static const rti::flat::offset_t offsets[] = {2, 2, 2, 2};
    return deserialize<DDS_UnsignedShort >(offsets);
}

DDS_UnsignedShort DimensionOffset::width() const
{
    static const rti::flat::offset_t offsets[] = {0, 0, 0, 0};
    return deserialize<DDS_UnsignedShort >(offsets);
}

bool DimensionOffset::width(DDS_UnsignedShort value)
{
    static const rti::flat::offset_t offsets[] = {0, 0, 0, 0};
    return serialize(offsets, value);

}

DDS_UnsignedShort DimensionOffset::height() const
{
    static const rti::flat::offset_t offsets[] = {2, 2, 2, 2};
    return deserialize<DDS_UnsignedShort >(offsets);
}

bool DimensionOffset::height(DDS_UnsignedShort value)
{
    static const rti::flat::offset_t offsets[] = {2, 2, 2, 2};
    return serialize(offsets, value);

}

void Dimension_finalize_optional_members(
    Dimension* sample, RTIBool deletePointers)
{
    UNUSED_ARG(sample);
    UNUSED_ARG(deletePointers);
}

RTIBool Dimension_initialize(
    Dimension* sample)
{
    UNUSED_ARG(sample);

    return RTI_FALSE;
}

RTIBool Dimension_initialize_w_params(
    Dimension* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{
    UNUSED_ARG(sample);
    UNUSED_ARG(allocParams);

    return RTI_FALSE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Dimension' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T Dimension
#define TSeq DimensionSeq

#define T_initialize Dimension_initialize

#define T_finalize   Dimension_finalize
#define T_copy       Dimension_copy

#define FLAT_DATA_TYPE
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

#define REDA_SEQUENCE_USER_API
#define T Dimension
#define TSeq DimensionSeq
#include "dds_cpp/dds_cpp_sequence_defn.hxx"

#undef FLAT_DATA_TYPE

#undef T_copy
#undef T_finalize

#undef T_initialize

#undef TSeq
#undef T

DimensionPlainHelper *
DimensionPlainHelper_create(void)
{
    DimensionPlainHelper* sample;
    OSAPI_Heap_allocate_struct(&sample, DimensionPlainHelper);
    if (sample != NULL) {
        if (!DimensionPlainHelper_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}
void
DimensionPlainHelper_delete(DimensionPlainHelper*sample)
{
    if (sample != NULL) {
        /* DimensionPlainHelper_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        DimensionPlainHelper_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}

/* ========================================================================= */
const char *DimensionPlainHelperTYPENAME = "DimensionPlainHelper";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* DimensionPlainHelper_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode_Member DimensionPlainHelper_g_tc_members[2]=
    {

        {
            (char *)"width",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"height",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode DimensionPlainHelper_g_tc =
    {{
            DDS_TK_STRUCT| DDS_TK_FINAL_EXTENSIBILITY, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"DimensionPlainHelper", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            2, /* Number of members */
            DimensionPlainHelper_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for DimensionPlainHelper*/

    if (is_initialized) {
        return &DimensionPlainHelper_g_tc;
    }

    DimensionPlainHelper_g_tc._data._annotations._allowedDataRepresentationMask = 4;

    DimensionPlainHelper_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;
    DimensionPlainHelper_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_ushort;

    /* Initialize the values for member annotations. */
    DimensionPlainHelper_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
    DimensionPlainHelper_g_tc_members[0]._annotations._defaultValue._u.ushort_value = 0;
    DimensionPlainHelper_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
    DimensionPlainHelper_g_tc_members[0]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
    DimensionPlainHelper_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
    DimensionPlainHelper_g_tc_members[0]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

    DimensionPlainHelper_g_tc_members[1]._annotations._defaultValue._d = RTI_XCDR_TK_USHORT;
    DimensionPlainHelper_g_tc_members[1]._annotations._defaultValue._u.ushort_value = 0;
    DimensionPlainHelper_g_tc_members[1]._annotations._minValue._d = RTI_XCDR_TK_USHORT;
    DimensionPlainHelper_g_tc_members[1]._annotations._minValue._u.ushort_value = RTIXCdrUnsignedShort_MIN;
    DimensionPlainHelper_g_tc_members[1]._annotations._maxValue._d = RTI_XCDR_TK_USHORT;
    DimensionPlainHelper_g_tc_members[1]._annotations._maxValue._u.ushort_value = RTIXCdrUnsignedShort_MAX;

    DimensionPlainHelper_g_tc._data._sampleAccessInfo =
    DimensionPlainHelper_get_sample_access_info();
    DimensionPlainHelper_g_tc._data._typePlugin =
    DimensionPlainHelper_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &DimensionPlainHelper_g_tc;
}

RTIXCdrSampleAccessInfo *DimensionPlainHelper_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    DimensionPlainHelper *sample;

    static RTIXCdrMemberAccessInfo DimensionPlainHelper_g_memberAccessInfos[2] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo DimensionPlainHelper_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &DimensionPlainHelper_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        DimensionPlainHelper);
    if (sample == NULL) {
        return NULL;
    }

    DimensionPlainHelper_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->width - (char *)sample);

    DimensionPlainHelper_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->height - (char *)sample);

    DimensionPlainHelper_g_sampleAccessInfo.memberAccessInfos = 
    DimensionPlainHelper_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(DimensionPlainHelper);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            DimensionPlainHelper_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            DimensionPlainHelper_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    DimensionPlainHelper_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &DimensionPlainHelper_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *DimensionPlainHelper_get_type_plugin_info()
{
    static RTIXCdrTypePlugin DimensionPlainHelper_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        DimensionPlainHelper_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        DimensionPlainHelper_finalize_w_return,
        NULL
    };

    return &DimensionPlainHelper_g_typePlugin;
}
#endif

RTIBool DimensionPlainHelper_initialize(
    DimensionPlainHelper* sample) {
    return DimensionPlainHelper_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool DimensionPlainHelper_initialize_ex(
    DimensionPlainHelper* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return DimensionPlainHelper_initialize_w_params(
        sample,&allocParams);

}

RTIBool DimensionPlainHelper_initialize_w_params(
    DimensionPlainHelper* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->width = 0;

    sample->height = 0;

    return RTI_TRUE;
}

RTIBool DimensionPlainHelper_finalize(
    DimensionPlainHelper* sample)
{

    DimensionPlainHelper_finalize_ex(sample,RTI_TRUE);
    return RTI_TRUE;
}

RTIBool DimensionPlainHelper_finalize_w_return(
    DimensionPlainHelper* sample)
{

    DimensionPlainHelper_finalize_ex(sample,RTI_TRUE);
    return RTI_TRUE;
}

void DimensionPlainHelper_finalize_ex(
    DimensionPlainHelper* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    DimensionPlainHelper_finalize_w_params(
        sample,&deallocParams);
}

void DimensionPlainHelper_finalize_w_params(
    DimensionPlainHelper* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

}

void DimensionPlainHelper_finalize_optional_members(
    DimensionPlainHelper* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

}

RTIBool DimensionPlainHelper_copy(
    DimensionPlainHelper* dst,
    const DimensionPlainHelper* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    DDS_Primitive_copy (&dst->width, &src->width);
    DDS_Primitive_copy (&dst->height, &src->height);

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'DimensionPlainHelper' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T DimensionPlainHelper
#define TSeq DimensionPlainHelperSeq

#define T_initialize DimensionPlainHelper_initialize

#define T_finalize   DimensionPlainHelper_finalize
#define T_copy       DimensionPlainHelper_copy

#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

#define REDA_SEQUENCE_USER_API
#define T DimensionPlainHelper
#define TSeq DimensionPlainHelperSeq
#include "dds_cpp/dds_cpp_sequence_defn.hxx"

#undef T_copy
#undef T_finalize

#undef T_initialize

#undef TSeq
#undef T

Image *
Image_create(void)
{
    Image* sample;
    OSAPI_Heap_allocate_struct(&sample, Image);
    if (sample != NULL) {
        if (!Image_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}
void
Image_delete(Image*sample)
{
    if (sample != NULL) {
        /* Image_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        Image_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}

RTI_BOOL
Image_finalize(Image* sample)
{
    UNUSED_ARG(sample);
    return RTI_FALSE;
}

RTI_BOOL
Image_copy(Image* dst,const Image* src)
{        
    UNUSED_ARG(dst);
    UNUSED_ARG(src);
    return RTI_FALSE;
}

/* ========================================================================= */
const char *ImageTYPENAME = "Image";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* Image_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode Image_g_tc_img_data_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,30000000, NULL,NULL);

    static DDS_TypeCode_Member Image_g_tc_members[3]=
    {

        {
            (char *)"timestamp",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"dimension",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"img_data",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode Image_g_tc =
    {{
            DDS_TK_STRUCT| DDS_TK_FINAL_EXTENSIBILITY| DDS_TK_FLAT_DATA_LANGUAGE_BINDING, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"Image", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            Image_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for Image*/

    if (is_initialized) {
        return &Image_g_tc;
    }

    Image_g_tc._data._annotations._allowedDataRepresentationMask = 4;

    Image_g_tc_img_data_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_octet;
    Image_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_longlong;
    Image_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)Dimension_get_typecode();
    Image_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& Image_g_tc_img_data_array;

    /* Initialize the values for member annotations. */
    Image_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
    Image_g_tc_members[0]._annotations._defaultValue._u.long_long_value = 0ll;
    Image_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
    Image_g_tc_members[0]._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
    Image_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
    Image_g_tc_members[0]._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;

    Image_g_tc._data._sampleAccessInfo =
    Image_get_sample_access_info();
    Image_g_tc._data._typePlugin =
    Image_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &Image_g_tc;
}

RTIXCdrSampleAccessInfo *Image_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    static RTIXCdrMemberAccessInfo Image_g_memberAccessInfos[3] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo Image_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &Image_g_sampleAccessInfo;
    }

    Image_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) 0;
    Image_g_memberAccessInfos[0].bindingMemberValueOffset[1] = 
    (RTIXCdrUnsignedLong) 0;
    Image_g_memberAccessInfos[0].bindingMemberValueOffset[2] = 
    (RTIXCdrUnsignedLong) 0;
    Image_g_memberAccessInfos[0].bindingMemberValueOffset[3] = 
    (RTIXCdrUnsignedLong) 0;

    Image_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) 8;
    Image_g_memberAccessInfos[1].bindingMemberValueOffset[1] = 
    (RTIXCdrUnsignedLong) 8;
    Image_g_memberAccessInfos[1].bindingMemberValueOffset[2] = 
    (RTIXCdrUnsignedLong) 8;
    Image_g_memberAccessInfos[1].bindingMemberValueOffset[3] = 
    (RTIXCdrUnsignedLong) 8;

    Image_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) 12;
    Image_g_memberAccessInfos[2].bindingMemberValueOffset[1] = 
    (RTIXCdrUnsignedLong) 12;
    Image_g_memberAccessInfos[2].bindingMemberValueOffset[2] = 
    (RTIXCdrUnsignedLong) 12;
    Image_g_memberAccessInfos[2].bindingMemberValueOffset[3] = 
    (RTIXCdrUnsignedLong) 12;

    Image_g_sampleAccessInfo.memberAccessInfos = 
    Image_g_memberAccessInfos;

    Image_g_sampleAccessInfo.typeSize[0] = (RTIXCdrUnsignedLong) 
    ImageOffset::serialized_size(0);
    Image_g_sampleAccessInfo.typeSize[1] = (RTIXCdrUnsignedLong) 
    ImageOffset::serialized_size(1);
    Image_g_sampleAccessInfo.typeSize[2] = (RTIXCdrUnsignedLong) 
    ImageOffset::serialized_size(2);
    Image_g_sampleAccessInfo.typeSize[3] = (RTIXCdrUnsignedLong) 
    ImageOffset::serialized_size(3);   

    Image_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_FLAT_DATA_CPP ;

    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &Image_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *Image_get_type_plugin_info()
{
    static RTIXCdrTypePlugin Image_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        NULL,
        NULL,
        NULL,
        NULL
    };

    return &Image_g_typePlugin;
}
#endif

Image * Image::create_data()
{
    return static_cast<Image *>(Base::create_data());
}

DDS_LongLong ImageConstOffset::timestamp() const
{
    static const rti::flat::offset_t offsets[] = {0, 0, 0, 0};
    return deserialize<DDS_LongLong >(offsets);
}

Dimension::ConstOffset ImageConstOffset::dimension() const
{
    static const rti::flat::offset_t offsets[] = {8, 8, 8, 8};
    return get_member<Dimension::ConstOffset >(offsets);}

const rti::flat::PrimitiveArrayOffset<DDS_Octet, (30000000)> ImageConstOffset::img_data() const
{
    static const rti::flat::offset_t offsets[] = {12, 12, 12, 12};
    return get_member<const rti::flat::PrimitiveArrayOffset<DDS_Octet, (30000000)> >(offsets);}

DDS_LongLong ImageOffset::timestamp() const
{
    static const rti::flat::offset_t offsets[] = {0, 0, 0, 0};
    return deserialize<DDS_LongLong >(offsets);
}

bool ImageOffset::timestamp(DDS_LongLong value)
{
    static const rti::flat::offset_t offsets[] = {0, 0, 0, 0};
    return serialize(offsets, value);

}

Dimension::ConstOffset ImageOffset::dimension() const
{
    static const rti::flat::offset_t offsets[] = {8, 8, 8, 8};
    return get_member<Dimension::ConstOffset >(offsets);}

Dimension::Offset ImageOffset::dimension()
{
    static const rti::flat::offset_t offsets[] = {8, 8, 8, 8};
    return get_member<Dimension::Offset >(offsets);}

const rti::flat::PrimitiveArrayOffset<DDS_Octet, (30000000)> ImageOffset::img_data() const
{
    static const rti::flat::offset_t offsets[] = {12, 12, 12, 12};
    return get_member<const rti::flat::PrimitiveArrayOffset<DDS_Octet, (30000000)> >(offsets);}

rti::flat::PrimitiveArrayOffset<DDS_Octet, (30000000)> ImageOffset::img_data()
{
    static const rti::flat::offset_t offsets[] = {12, 12, 12, 12};
    return get_member<rti::flat::PrimitiveArrayOffset<DDS_Octet, (30000000)> >(offsets);}

void Image_finalize_optional_members(
    Image* sample, RTIBool deletePointers)
{
    UNUSED_ARG(sample);
    UNUSED_ARG(deletePointers);
}

RTIBool Image_initialize(
    Image* sample)
{
    UNUSED_ARG(sample);

    return RTI_FALSE;
}

RTIBool Image_initialize_w_params(
    Image* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{
    UNUSED_ARG(sample);
    UNUSED_ARG(allocParams);

    return RTI_FALSE;
}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'Image' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T Image
#define TSeq ImageSeq

#define T_initialize Image_initialize

#define T_finalize   Image_finalize
#define T_copy       Image_copy

#define FLAT_DATA_TYPE
#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

#define REDA_SEQUENCE_USER_API
#define T Image
#define TSeq ImageSeq
#include "dds_cpp/dds_cpp_sequence_defn.hxx"

#undef FLAT_DATA_TYPE

#undef T_copy
#undef T_finalize

#undef T_initialize

#undef TSeq
#undef T

ImagePlainHelper *
ImagePlainHelper_create(void)
{
    ImagePlainHelper* sample;
    OSAPI_Heap_allocate_struct(&sample, ImagePlainHelper);
    if (sample != NULL) {
        if (!ImagePlainHelper_initialize(sample)) {
            OSAPI_Heap_free_struct(sample);
            sample = NULL;
        }
    }
    return sample;
}
void
ImagePlainHelper_delete(ImagePlainHelper*sample)
{
    if (sample != NULL) {
        /* ImagePlainHelper_finalize() always 
        returns RTI_TRUE when called with sample != NULL */
        ImagePlainHelper_finalize(sample);
        OSAPI_Heap_free_struct(sample);
    }
}

/* ========================================================================= */
const char *ImagePlainHelperTYPENAME = "ImagePlainHelper";

#ifndef NDDS_STANDALONE_TYPE
DDS_TypeCode* ImagePlainHelper_get_typecode()
{
    static RTIBool is_initialized = RTI_FALSE;

    static DDS_TypeCode ImagePlainHelper_g_tc_img_data_array =DDS_INITIALIZE_ARRAY_TYPECODE(1,30000000, NULL,NULL);

    static DDS_TypeCode_Member ImagePlainHelper_g_tc_members[3]=
    {

        {
            (char *)"timestamp",/* Member name */
            {
                0,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"dimension",/* Member name */
            {
                1,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }, 
        {
            (char *)"img_data",/* Member name */
            {
                2,/* Representation ID */
                DDS_BOOLEAN_FALSE,/* Is a pointer? */
                -1, /* Bitfield bits */
                NULL/* Member type code is assigned later */
            },
            0, /* Ignored */
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            RTI_CDR_REQUIRED_MEMBER, /* Is a key? */
            DDS_PUBLIC_MEMBER,/* Member visibility */
            1,
            NULL, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER
        }
    };

    static DDS_TypeCode ImagePlainHelper_g_tc =
    {{
            DDS_TK_STRUCT| DDS_TK_FINAL_EXTENSIBILITY, /* Kind */
            DDS_BOOLEAN_FALSE, /* Ignored */
            -1, /*Ignored*/
            (char *)"ImagePlainHelper", /* Name */
            NULL, /* Ignored */      
            0, /* Ignored */
            0, /* Ignored */
            NULL, /* Ignored */
            3, /* Number of members */
            ImagePlainHelper_g_tc_members, /* Members */
            DDS_VM_NONE, /* Ignored */
            RTICdrTypeCodeAnnotations_INITIALIZER,
            DDS_BOOLEAN_TRUE, /* _isCopyable */
            NULL, /* _sampleAccessInfo: assigned later */
            NULL /* _typePlugin: assigned later */
        }}; /* Type code for ImagePlainHelper*/

    if (is_initialized) {
        return &ImagePlainHelper_g_tc;
    }

    ImagePlainHelper_g_tc._data._annotations._allowedDataRepresentationMask = 4;

    ImagePlainHelper_g_tc_img_data_array._data._typeCode =(RTICdrTypeCode *)&DDS_g_tc_octet;
    ImagePlainHelper_g_tc_members[0]._representation._typeCode = (RTICdrTypeCode *)&DDS_g_tc_longlong;
    ImagePlainHelper_g_tc_members[1]._representation._typeCode = (RTICdrTypeCode *)DimensionPlainHelper_get_typecode();
    ImagePlainHelper_g_tc_members[2]._representation._typeCode = (RTICdrTypeCode *)& ImagePlainHelper_g_tc_img_data_array;

    /* Initialize the values for member annotations. */
    ImagePlainHelper_g_tc_members[0]._annotations._defaultValue._d = RTI_XCDR_TK_LONGLONG;
    ImagePlainHelper_g_tc_members[0]._annotations._defaultValue._u.long_long_value = 0ll;
    ImagePlainHelper_g_tc_members[0]._annotations._minValue._d = RTI_XCDR_TK_LONGLONG;
    ImagePlainHelper_g_tc_members[0]._annotations._minValue._u.long_long_value = RTIXCdrLongLong_MIN;
    ImagePlainHelper_g_tc_members[0]._annotations._maxValue._d = RTI_XCDR_TK_LONGLONG;
    ImagePlainHelper_g_tc_members[0]._annotations._maxValue._u.long_long_value = RTIXCdrLongLong_MAX;

    ImagePlainHelper_g_tc._data._sampleAccessInfo =
    ImagePlainHelper_get_sample_access_info();
    ImagePlainHelper_g_tc._data._typePlugin =
    ImagePlainHelper_get_type_plugin_info();    

    is_initialized = RTI_TRUE;

    return &ImagePlainHelper_g_tc;
}

RTIXCdrSampleAccessInfo *ImagePlainHelper_get_sample_access_info()
{
    static RTIBool is_initialized = RTI_FALSE;

    ImagePlainHelper *sample;

    static RTIXCdrMemberAccessInfo ImagePlainHelper_g_memberAccessInfos[3] =
    {RTIXCdrMemberAccessInfo_INITIALIZER};

    static RTIXCdrSampleAccessInfo ImagePlainHelper_g_sampleAccessInfo = 
    RTIXCdrSampleAccessInfo_INITIALIZER;

    if (is_initialized) {
        return (RTIXCdrSampleAccessInfo*) &ImagePlainHelper_g_sampleAccessInfo;
    }

    RTIXCdrHeap_allocateStruct(
        &sample, 
        ImagePlainHelper);
    if (sample == NULL) {
        return NULL;
    }

    ImagePlainHelper_g_memberAccessInfos[0].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->timestamp - (char *)sample);

    ImagePlainHelper_g_memberAccessInfos[1].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->dimension - (char *)sample);

    ImagePlainHelper_g_memberAccessInfos[2].bindingMemberValueOffset[0] = 
    (RTIXCdrUnsignedLong) ((char *)&sample->img_data - (char *)sample);

    ImagePlainHelper_g_sampleAccessInfo.memberAccessInfos = 
    ImagePlainHelper_g_memberAccessInfos;

    {
        size_t candidateTypeSize = sizeof(ImagePlainHelper);

        if (candidateTypeSize > RTIXCdrUnsignedLong_MAX) {
            ImagePlainHelper_g_sampleAccessInfo.typeSize[0] =
            RTIXCdrUnsignedLong_MAX;
        } else {
            ImagePlainHelper_g_sampleAccessInfo.typeSize[0] =
            (RTIXCdrUnsignedLong) candidateTypeSize;
        }
    }

    ImagePlainHelper_g_sampleAccessInfo.languageBinding = 
    RTI_XCDR_TYPE_BINDING_CPP ;

    RTIXCdrHeap_freeStruct(sample);
    is_initialized = RTI_TRUE;
    return (RTIXCdrSampleAccessInfo*) &ImagePlainHelper_g_sampleAccessInfo;
}

RTIXCdrTypePlugin *ImagePlainHelper_get_type_plugin_info()
{
    static RTIXCdrTypePlugin ImagePlainHelper_g_typePlugin = 
    {
        NULL, /* serialize */
        NULL, /* serialize_key */
        NULL, /* deserialize_sample */
        NULL, /* deserialize_key_sample */
        NULL, /* skip */
        NULL, /* get_serialized_sample_size */
        NULL, /* get_serialized_sample_max_size_ex */
        NULL, /* get_serialized_key_max_size_ex */
        NULL, /* get_serialized_sample_min_size */
        NULL, /* serialized_sample_to_key */
        (RTIXCdrTypePluginInitializeSampleFunction) 
        ImagePlainHelper_initialize_ex,
        NULL,
        (RTIXCdrTypePluginFinalizeSampleFunction)
        ImagePlainHelper_finalize_w_return,
        NULL
    };

    return &ImagePlainHelper_g_typePlugin;
}
#endif

RTIBool ImagePlainHelper_initialize(
    ImagePlainHelper* sample) {
    return ImagePlainHelper_initialize_ex(sample,RTI_TRUE,RTI_TRUE);
}

RTIBool ImagePlainHelper_initialize_ex(
    ImagePlainHelper* sample,RTIBool allocatePointers, RTIBool allocateMemory)
{

    struct DDS_TypeAllocationParams_t allocParams =
    DDS_TYPE_ALLOCATION_PARAMS_DEFAULT;

    allocParams.allocate_pointers =  (DDS_Boolean)allocatePointers;
    allocParams.allocate_memory = (DDS_Boolean)allocateMemory;

    return ImagePlainHelper_initialize_w_params(
        sample,&allocParams);

}

RTIBool ImagePlainHelper_initialize_w_params(
    ImagePlainHelper* sample, const struct DDS_TypeAllocationParams_t * allocParams)
{

    if (sample == NULL) {
        return RTI_FALSE;
    }
    if (allocParams == NULL) {
        return RTI_FALSE;
    }

    sample->timestamp = 0ll;

    if (!DimensionPlainHelper_initialize_w_params(&sample->dimension,
    allocParams)) {
        return RTI_FALSE;
    }
    CDR_Primitive_init_array(sample->img_data, ((30000000))* CDR_OCTET_SIZE);

    return RTI_TRUE;
}

RTIBool ImagePlainHelper_finalize(
    ImagePlainHelper* sample)
{

    ImagePlainHelper_finalize_ex(sample,RTI_TRUE);
    return RTI_TRUE;
}

RTIBool ImagePlainHelper_finalize_w_return(
    ImagePlainHelper* sample)
{

    ImagePlainHelper_finalize_ex(sample,RTI_TRUE);
    return RTI_TRUE;
}

void ImagePlainHelper_finalize_ex(
    ImagePlainHelper* sample,RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParams =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;

    if (sample==NULL) {
        return;
    } 

    deallocParams.delete_pointers = (DDS_Boolean)deletePointers;

    ImagePlainHelper_finalize_w_params(
        sample,&deallocParams);
}

void ImagePlainHelper_finalize_w_params(
    ImagePlainHelper* sample,const struct DDS_TypeDeallocationParams_t * deallocParams)
{

    if (sample==NULL) {
        return;
    }

    if (deallocParams == NULL) {
        return;
    }

    DimensionPlainHelper_finalize_w_params(&sample->dimension,deallocParams);

}

void ImagePlainHelper_finalize_optional_members(
    ImagePlainHelper* sample, RTIBool deletePointers)
{
    struct DDS_TypeDeallocationParams_t deallocParamsTmp =
    DDS_TYPE_DEALLOCATION_PARAMS_DEFAULT;
    struct DDS_TypeDeallocationParams_t * deallocParams =
    &deallocParamsTmp;

    if (sample==NULL) {
        return;
    } 
    if (deallocParams) {} /* To avoid warnings */

    deallocParamsTmp.delete_pointers = (DDS_Boolean)deletePointers;
    deallocParamsTmp.delete_optional_members = DDS_BOOLEAN_TRUE;

    DimensionPlainHelper_finalize_optional_members(&sample->dimension, deallocParams->delete_pointers);
}

RTIBool ImagePlainHelper_copy(
    ImagePlainHelper* dst,
    const ImagePlainHelper* src)
{

    if (dst == NULL || src == NULL) {
        return RTI_FALSE;
    }

    DDS_Primitive_copy (&dst->timestamp, &src->timestamp);
    if (!DimensionPlainHelper_copy(
        &dst->dimension,(const DimensionPlainHelper*)&src->dimension)) {
        return RTI_FALSE;
    } 
    CDR_Primitive_copy_array(dst->img_data ,src->img_data,(30000000) * CDR_OCTET_SIZE);

    return RTI_TRUE;

}

/**
* <<IMPLEMENTATION>>
*
* Defines:  TSeq, T
*
* Configure and implement 'ImagePlainHelper' sequence class.
*/
#define REDA_SEQUENCE_USER_API
#define T ImagePlainHelper
#define TSeq ImagePlainHelperSeq

#define T_initialize ImagePlainHelper_initialize

#define T_finalize   ImagePlainHelper_finalize
#define T_copy       ImagePlainHelper_copy

#include "reda/reda_sequence_defn.h"
#undef T_copy
#undef T_finalize
#undef T_initialize

#define REDA_SEQUENCE_USER_API
#define T ImagePlainHelper
#define TSeq ImagePlainHelperSeq
#include "dds_cpp/dds_cpp_sequence_defn.hxx"

#undef T_copy
#undef T_finalize

#undef T_initialize

#undef TSeq
#undef T

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        const RTIXCdrTypeCode * type_code<Dimension>::get() 
        {
            return (const RTIXCdrTypeCode *) Dimension_get_typecode();
        }

        RTIXCdrInterpreterPrograms * type_programs<Dimension::Base>::get() 
        {
            return rti::xcdr::ProgramsSingleton<
            Dimension,
            RTI_XCDR_INITIALIZE_SAMPLE_PROGRAM,
            true, true, true
            >::get_instance();
        }

        const RTIXCdrTypeCode * type_code<DimensionPlainHelper>::get() 
        {
            return (const RTIXCdrTypeCode *) DimensionPlainHelper_get_typecode();
        }

        const RTIXCdrTypeCode * type_code<Image>::get() 
        {
            return (const RTIXCdrTypeCode *) Image_get_typecode();
        }

        RTIXCdrInterpreterPrograms * type_programs<Image::Base>::get() 
        {
            return rti::xcdr::ProgramsSingleton<
            Image,
            RTI_XCDR_INITIALIZE_SAMPLE_PROGRAM,
            true, true, true
            >::get_instance();
        }

        const RTIXCdrTypeCode * type_code<ImagePlainHelper>::get() 
        {
            return (const RTIXCdrTypeCode *) ImagePlainHelper_get_typecode();
        }

    } 
}
#endif

