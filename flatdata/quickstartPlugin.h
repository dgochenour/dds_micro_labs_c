/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from quickstart.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#ifndef quickstartPlugin_214727424_h
#define quickstartPlugin_214727424_h

#include "quickstart.h"

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

struct DimensionTypePlugin;

NDDSUSERDllExport extern RTI_BOOL
DimensionTypePlugin_delete(struct DDS_TypePlugin *self);

NDDSUSERDllExport extern struct DDS_TypePlugin*
DimensionWriterTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataWriter *writer,
    struct DDS_DataWriterQos *qos,
    struct DDS_TypePluginProperty *property);

NDDSUSERDllExport extern struct DDS_TypePlugin*
DimensionReaderTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataReader *reader,
    struct DDS_DataReaderQos *qos,
    struct DDS_TypePluginProperty *property);

NDDSUSERDllExport extern struct DDS_TypePluginI*
DimensionTypePlugin_get(void);
NDDSUSERDllExport extern const char*
DimensionTypePlugin_get_default_type_name(void);
NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
DimensionI_get_key_kind();
/* --------------------------------------------------------------------------
Untyped interfaces to the typed sample management functions
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL
DimensionPlugin_create_sample(
    struct DDS_TypePlugin *plugin, void **sample);

#ifndef RTI_CERT
NDDSUSERDllExport extern RTI_BOOL 
DimensionPlugin_delete_sample(
    struct DDS_TypePlugin *plugin, void *sample);
#endif

NDDSUSERDllExport extern RTI_BOOL 
DimensionPlugin_copy_sample(
    struct DDS_TypePlugin *plugin, void *dst, const void *src);

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL 
Dimension_cdr_serialize(struct DDS_TypePlugin *plugin, 
struct CDR_Stream_t *stream, 
const void *void_sample,
DDS_InstanceHandle_t *destination);

NDDSUSERDllExport extern RTI_BOOL 
Dimension_cdr_deserialize(struct DDS_TypePlugin *plugin,
void *void_sample,
struct CDR_Stream_t *stream,
DDS_InstanceHandle_t *source); 

NDDSUSERDllExport extern RTI_UINT32
Dimension_get_serialized_sample_size(
    struct DDS_TypePlugin *plugin,
    RTI_UINT32 current_alignment);
/* Unkeyed type key serialization equivalent to sample serialization */
#define Dimension_cdr_serialize_key Dimension_cdr_serialize
#define Dimension_cdr_deserialize_key Dimension_cdr_deserialize
#define Dimension_get_serialized_key_size Dimension_get_serialized_sample_size

struct DimensionPlainHelperTypePlugin;

NDDSUSERDllExport extern RTI_BOOL
DimensionPlainHelperTypePlugin_delete(struct DDS_TypePlugin *self);

NDDSUSERDllExport extern struct DDS_TypePlugin*
DimensionPlainHelperWriterTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataWriter *writer,
    struct DDS_DataWriterQos *qos,
    struct DDS_TypePluginProperty *property);

NDDSUSERDllExport extern struct DDS_TypePlugin*
DimensionPlainHelperReaderTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataReader *reader,
    struct DDS_DataReaderQos *qos,
    struct DDS_TypePluginProperty *property);

NDDSUSERDllExport extern struct DDS_TypePluginI*
DimensionPlainHelperTypePlugin_get(void);
NDDSUSERDllExport extern const char*
DimensionPlainHelperTypePlugin_get_default_type_name(void);
NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
DimensionPlainHelperI_get_key_kind();
/* --------------------------------------------------------------------------
Untyped interfaces to the typed sample management functions
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL
DimensionPlainHelperPlugin_create_sample(
    struct DDS_TypePlugin *plugin, void **sample);

#ifndef RTI_CERT
NDDSUSERDllExport extern RTI_BOOL 
DimensionPlainHelperPlugin_delete_sample(
    struct DDS_TypePlugin *plugin, void *sample);
#endif

NDDSUSERDllExport extern RTI_BOOL 
DimensionPlainHelperPlugin_copy_sample(
    struct DDS_TypePlugin *plugin, void *dst, const void *src);

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL 
DimensionPlainHelper_cdr_serialize(struct DDS_TypePlugin *plugin, 
struct CDR_Stream_t *stream, 
const void *void_sample,
DDS_InstanceHandle_t *destination);

NDDSUSERDllExport extern RTI_BOOL 
DimensionPlainHelper_cdr_deserialize(struct DDS_TypePlugin *plugin,
void *void_sample,
struct CDR_Stream_t *stream,
DDS_InstanceHandle_t *source); 

NDDSUSERDllExport extern RTI_UINT32
DimensionPlainHelper_get_serialized_sample_size(
    struct DDS_TypePlugin *plugin,
    RTI_UINT32 current_alignment);
/* Unkeyed type key serialization equivalent to sample serialization */
#define DimensionPlainHelper_cdr_serialize_key DimensionPlainHelper_cdr_serialize
#define DimensionPlainHelper_cdr_deserialize_key DimensionPlainHelper_cdr_deserialize
#define DimensionPlainHelper_get_serialized_key_size DimensionPlainHelper_get_serialized_sample_size

struct ImageTypePlugin;

NDDSUSERDllExport extern RTI_BOOL
ImageTypePlugin_delete(struct DDS_TypePlugin *self);

NDDSUSERDllExport extern struct DDS_TypePlugin*
ImageWriterTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataWriter *writer,
    struct DDS_DataWriterQos *qos,
    struct DDS_TypePluginProperty *property);

NDDSUSERDllExport extern struct DDS_TypePlugin*
ImageReaderTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataReader *reader,
    struct DDS_DataReaderQos *qos,
    struct DDS_TypePluginProperty *property);

NDDSUSERDllExport extern struct DDS_TypePluginI*
ImageTypePlugin_get(void);
NDDSUSERDllExport extern const char*
ImageTypePlugin_get_default_type_name(void);
NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
ImageI_get_key_kind();
/* --------------------------------------------------------------------------
Untyped interfaces to the typed sample management functions
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL
ImagePlugin_create_sample(
    struct DDS_TypePlugin *plugin, void **sample);

#ifndef RTI_CERT
NDDSUSERDllExport extern RTI_BOOL 
ImagePlugin_delete_sample(
    struct DDS_TypePlugin *plugin, void *sample);
#endif

NDDSUSERDllExport extern RTI_BOOL 
ImagePlugin_copy_sample(
    struct DDS_TypePlugin *plugin, void *dst, const void *src);

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL 
Image_cdr_serialize(struct DDS_TypePlugin *plugin, 
struct CDR_Stream_t *stream, 
const void *void_sample,
DDS_InstanceHandle_t *destination);

NDDSUSERDllExport extern RTI_BOOL 
Image_cdr_deserialize(struct DDS_TypePlugin *plugin,
void *void_sample,
struct CDR_Stream_t *stream,
DDS_InstanceHandle_t *source); 

NDDSUSERDllExport extern RTI_UINT32
Image_get_serialized_sample_size(
    struct DDS_TypePlugin *plugin,
    RTI_UINT32 current_alignment);
/* Unkeyed type key serialization equivalent to sample serialization */
#define Image_cdr_serialize_key Image_cdr_serialize
#define Image_cdr_deserialize_key Image_cdr_deserialize
#define Image_get_serialized_key_size Image_get_serialized_sample_size

struct ImagePlainHelperTypePlugin;

NDDSUSERDllExport extern RTI_BOOL
ImagePlainHelperTypePlugin_delete(struct DDS_TypePlugin *self);

NDDSUSERDllExport extern struct DDS_TypePlugin*
ImagePlainHelperWriterTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataWriter *writer,
    struct DDS_DataWriterQos *qos,
    struct DDS_TypePluginProperty *property);

NDDSUSERDllExport extern struct DDS_TypePlugin*
ImagePlainHelperReaderTypePlugin_create(
    DDS_DomainParticipant *participant,
    struct DDS_DomainParticipantQos *dp_qos,
    DDS_DataReader *reader,
    struct DDS_DataReaderQos *qos,
    struct DDS_TypePluginProperty *property);

NDDSUSERDllExport extern struct DDS_TypePluginI*
ImagePlainHelperTypePlugin_get(void);
NDDSUSERDllExport extern const char*
ImagePlainHelperTypePlugin_get_default_type_name(void);
NDDSUSERDllExport extern NDDS_TypePluginKeyKind 
ImagePlainHelperI_get_key_kind();
/* --------------------------------------------------------------------------
Untyped interfaces to the typed sample management functions
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL
ImagePlainHelperPlugin_create_sample(
    struct DDS_TypePlugin *plugin, void **sample);

#ifndef RTI_CERT
NDDSUSERDllExport extern RTI_BOOL 
ImagePlainHelperPlugin_delete_sample(
    struct DDS_TypePlugin *plugin, void *sample);
#endif

NDDSUSERDllExport extern RTI_BOOL 
ImagePlainHelperPlugin_copy_sample(
    struct DDS_TypePlugin *plugin, void *dst, const void *src);

/* --------------------------------------------------------------------------
(De)Serialize functions:
* -------------------------------------------------------------------------- */
NDDSUSERDllExport extern RTI_BOOL 
ImagePlainHelper_cdr_serialize(struct DDS_TypePlugin *plugin, 
struct CDR_Stream_t *stream, 
const void *void_sample,
DDS_InstanceHandle_t *destination);

NDDSUSERDllExport extern RTI_BOOL 
ImagePlainHelper_cdr_deserialize(struct DDS_TypePlugin *plugin,
void *void_sample,
struct CDR_Stream_t *stream,
DDS_InstanceHandle_t *source); 

NDDSUSERDllExport extern RTI_UINT32
ImagePlainHelper_get_serialized_sample_size(
    struct DDS_TypePlugin *plugin,
    RTI_UINT32 current_alignment);
/* Unkeyed type key serialization equivalent to sample serialization */
#define ImagePlainHelper_cdr_serialize_key ImagePlainHelper_cdr_serialize
#define ImagePlainHelper_cdr_deserialize_key ImagePlainHelper_cdr_deserialize
#define ImagePlainHelper_get_serialized_key_size ImagePlainHelper_get_serialized_sample_size

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* quickstartPlugin_214727424_h */

