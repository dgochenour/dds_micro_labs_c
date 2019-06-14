/*
WARNING: THIS FILE IS AUTO-GENERATED. DO NOT MODIFY.

This file was generated from quickstart.idl using "rtiddsgen".
The rtiddsgen tool is part of the RTI Data Distribution Service distribution.
For more information, type 'rtiddsgen -help' at a command shell
or consult the RTI Data Distribution Service manual.
*/

#ifndef quickstart_214727424_h
#define quickstart_214727424_h

#ifndef rti_me_cpp_hxx
#include "rti_me_cpp.hxx"
#endif

#include "dds_c/dds_c_typecode.h"

#include "dds_cpp/dds_cpp_flat_data.hxx"

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

extern "C" {

    extern const char *DimensionTYPENAME;

}

struct DimensionSeq;
#ifndef NDDS_STANDALONE_TYPE
class DimensionTypeSupport;
class DimensionDataWriter;
class DimensionDataReader;
#endif
class NDDSUSERDllExport DimensionConstOffset 
: public rti::flat::FinalOffset<DimensionConstOffset> {
  public:
    enum { required_alignment = 2 };

    static rti::flat::offset_t serialized_size(rti::flat::offset_t initial_position)
    {
        static const rti::flat::offset_t sizes[] = {4, 4, 4, 4};
        return sizes[initial_position % 4];
    }

    // Null offset
    DimensionConstOffset()
    {
    }

    // Constructor is for internal use only
    DimensionConstOffset(
        const rti::flat::SampleBase *sample, 
        rti::flat::offset_t offset)
        : rti::flat::FinalOffset<DimensionConstOffset>(const_cast<rti::flat::SampleBase *>(sample), offset)
    {
    }

    DDS_UnsignedShort width() const; 
    DDS_UnsignedShort height() const; 
};
class NDDSUSERDllExport DimensionOffset 
: public rti::flat::FinalOffset<DimensionOffset> {
  public:
    typedef DimensionConstOffset ConstOffset;

    enum { required_alignment = 2 };

    static rti::flat::offset_t serialized_size(rti::flat::offset_t initial_position)
    {
        static const rti::flat::offset_t sizes[] = {4, 4, 4, 4};
        return sizes[initial_position % 4];
    }

    // Null offset
    DimensionOffset()
    {
    }

    // Constructor is for internal use only
    DimensionOffset(
        rti::flat::SampleBase *sample, 
        rti::flat::offset_t offset)
        : rti::flat::FinalOffset<DimensionOffset>(sample, offset)
    {
    }

    // Const accessors
    DDS_UnsignedShort width() const; 
    DDS_UnsignedShort height() const; 

    // Modifiers
    bool width(DDS_UnsignedShort value);
    bool height(DDS_UnsignedShort value);
};

class Dimension : public rti::flat::Sample<DimensionOffset> {
  public:
    typedef rti::flat::Sample<DimensionOffset> Base;
    typedef struct DimensionSeq Seq;
    typedef DimensionTypeSupport TypeSupport;
    typedef DimensionDataWriter DataWriter;
    typedef DimensionDataReader DataReader;

    static Dimension * create_data();
};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* Dimension_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Dimension_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Dimension_get_sample_access_info(void);
#endif

#define REDA_SEQUENCE_USER_API
#define T Dimension
#define TSeq DimensionSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>
#define REDA_SEQUENCE_USER_API
#define T Dimension
#define TSeq DimensionSeq
#define REDA_SEQUENCE_EXCLUDE_STRUCT
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

NDDSUSERDllExport extern Dimension*
Dimension_create();

NDDSUSERDllExport extern void
Dimension_delete(Dimension* sample);

NDDSUSERDllExport
RTIBool Dimension_initialize(
    Dimension* self);

NDDSUSERDllExport
RTIBool Dimension_initialize_ex(
    Dimension* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Dimension_initialize_w_params(
    Dimension* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool Dimension_finalize(
    Dimension* self);

NDDSUSERDllExport
RTIBool Dimension_finalize_w_return(
    Dimension* self);

NDDSUSERDllExport
void Dimension_finalize_ex(
    Dimension* self,RTIBool deletePointers);

NDDSUSERDllExport
void Dimension_finalize_w_params(
    Dimension* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Dimension_finalize_optional_members(
    Dimension* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Dimension_copy(
    Dimension* dst,
    const Dimension* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern "C" {

    extern const char *DimensionPlainHelperTYPENAME;

}

struct DimensionPlainHelperSeq;
#ifndef NDDS_STANDALONE_TYPE
class DimensionPlainHelperTypeSupport;
class DimensionPlainHelperDataWriter;
class DimensionPlainHelperDataReader;
#endif
class DimensionPlainHelper 
{
  public:
    typedef struct DimensionPlainHelperSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef DimensionPlainHelperTypeSupport TypeSupport;
    typedef DimensionPlainHelperDataWriter DataWriter;
    typedef DimensionPlainHelperDataReader DataReader;
    #endif

    DDS_UnsignedShort   width ;
    DDS_UnsignedShort   height ;

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* DimensionPlainHelper_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *DimensionPlainHelper_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *DimensionPlainHelper_get_sample_access_info(void);
#endif

#define REDA_SEQUENCE_USER_API
#define T DimensionPlainHelper
#define TSeq DimensionPlainHelperSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>
#define REDA_SEQUENCE_USER_API
#define T DimensionPlainHelper
#define TSeq DimensionPlainHelperSeq
#define REDA_SEQUENCE_EXCLUDE_STRUCT
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

NDDSUSERDllExport extern DimensionPlainHelper*
DimensionPlainHelper_create();

NDDSUSERDllExport extern void
DimensionPlainHelper_delete(DimensionPlainHelper* sample);

NDDSUSERDllExport
RTIBool DimensionPlainHelper_initialize(
    DimensionPlainHelper* self);

NDDSUSERDllExport
RTIBool DimensionPlainHelper_initialize_ex(
    DimensionPlainHelper* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool DimensionPlainHelper_initialize_w_params(
    DimensionPlainHelper* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool DimensionPlainHelper_finalize(
    DimensionPlainHelper* self);

NDDSUSERDllExport
RTIBool DimensionPlainHelper_finalize_w_return(
    DimensionPlainHelper* self);

NDDSUSERDllExport
void DimensionPlainHelper_finalize_ex(
    DimensionPlainHelper* self,RTIBool deletePointers);

NDDSUSERDllExport
void DimensionPlainHelper_finalize_w_params(
    DimensionPlainHelper* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void DimensionPlainHelper_finalize_optional_members(
    DimensionPlainHelper* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool DimensionPlainHelper_copy(
    DimensionPlainHelper* dst,
    const DimensionPlainHelper* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern "C" {

    extern const char *ImageTYPENAME;

}

struct ImageSeq;
#ifndef NDDS_STANDALONE_TYPE
class ImageTypeSupport;
class ImageDataWriter;
class ImageDataReader;
#endif
class NDDSUSERDllExport ImageConstOffset 
: public rti::flat::FinalOffset<ImageConstOffset> {
  public:
    enum { required_alignment = 4 };

    static rti::flat::offset_t serialized_size(rti::flat::offset_t initial_position)
    {
        static const rti::flat::offset_t sizes[] = {30000012, 30000012, 30000012, 30000012};
        return sizes[initial_position % 4];
    }

    // Null offset
    ImageConstOffset()
    {
    }

    // Constructor is for internal use only
    ImageConstOffset(
        const rti::flat::SampleBase *sample, 
        rti::flat::offset_t offset)
        : rti::flat::FinalOffset<ImageConstOffset>(const_cast<rti::flat::SampleBase *>(sample), offset)
    {
    }

    DDS_LongLong timestamp() const; 
    Dimension::ConstOffset dimension() const; 
    const rti::flat::PrimitiveArrayOffset<DDS_Octet, (30000000)> img_data() const; 
};
class NDDSUSERDllExport ImageOffset 
: public rti::flat::FinalOffset<ImageOffset> {
  public:
    typedef ImageConstOffset ConstOffset;

    enum { required_alignment = 4 };

    static rti::flat::offset_t serialized_size(rti::flat::offset_t initial_position)
    {
        static const rti::flat::offset_t sizes[] = {30000012, 30000012, 30000012, 30000012};
        return sizes[initial_position % 4];
    }

    // Null offset
    ImageOffset()
    {
    }

    // Constructor is for internal use only
    ImageOffset(
        rti::flat::SampleBase *sample, 
        rti::flat::offset_t offset)
        : rti::flat::FinalOffset<ImageOffset>(sample, offset)
    {
    }

    // Const accessors
    DDS_LongLong timestamp() const; 
    Dimension::ConstOffset dimension() const; 
    const rti::flat::PrimitiveArrayOffset<DDS_Octet, (30000000)> img_data() const; 

    // Modifiers
    bool timestamp(DDS_LongLong value);
    Dimension::Offset dimension(); 
    rti::flat::PrimitiveArrayOffset<DDS_Octet, (30000000)> img_data(); 
};

class Image : public rti::flat::Sample<ImageOffset> {
  public:
    typedef rti::flat::Sample<ImageOffset> Base;
    typedef struct ImageSeq Seq;
    typedef ImageTypeSupport TypeSupport;
    typedef ImageDataWriter DataWriter;
    typedef ImageDataReader DataReader;

    static Image * create_data();
};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* Image_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *Image_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *Image_get_sample_access_info(void);
#endif

#define REDA_SEQUENCE_USER_API
#define T Image
#define TSeq ImageSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>
#define REDA_SEQUENCE_USER_API
#define T Image
#define TSeq ImageSeq
#define REDA_SEQUENCE_EXCLUDE_STRUCT
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

NDDSUSERDllExport extern Image*
Image_create();

NDDSUSERDllExport extern void
Image_delete(Image* sample);

NDDSUSERDllExport
RTIBool Image_initialize(
    Image* self);

NDDSUSERDllExport
RTIBool Image_initialize_ex(
    Image* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool Image_initialize_w_params(
    Image* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool Image_finalize(
    Image* self);

NDDSUSERDllExport
RTIBool Image_finalize_w_return(
    Image* self);

NDDSUSERDllExport
void Image_finalize_ex(
    Image* self,RTIBool deletePointers);

NDDSUSERDllExport
void Image_finalize_w_params(
    Image* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void Image_finalize_optional_members(
    Image* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool Image_copy(
    Image* dst,
    const Image* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

extern "C" {

    extern const char *ImagePlainHelperTYPENAME;

}

struct ImagePlainHelperSeq;
#ifndef NDDS_STANDALONE_TYPE
class ImagePlainHelperTypeSupport;
class ImagePlainHelperDataWriter;
class ImagePlainHelperDataReader;
#endif
class ImagePlainHelper 
{
  public:
    typedef struct ImagePlainHelperSeq Seq;
    #ifndef NDDS_STANDALONE_TYPE
    typedef ImagePlainHelperTypeSupport TypeSupport;
    typedef ImagePlainHelperDataWriter DataWriter;
    typedef ImagePlainHelperDataReader DataReader;
    #endif

    DDS_LongLong   timestamp ;
    DimensionPlainHelper   dimension ;
    DDS_Octet   img_data [30000000];

};
#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, start exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport __declspec(dllexport)
#endif

#ifndef NDDS_STANDALONE_TYPE
NDDSUSERDllExport DDS_TypeCode* ImagePlainHelper_get_typecode(void); /* Type code */
NDDSUSERDllExport RTIXCdrTypePlugin *ImagePlainHelper_get_type_plugin_info(void);
NDDSUSERDllExport RTIXCdrSampleAccessInfo *ImagePlainHelper_get_sample_access_info(void);
#endif

#define REDA_SEQUENCE_USER_API
#define T ImagePlainHelper
#define TSeq ImagePlainHelperSeq
#define REDA_SEQUENCE_EXCLUDE_C_METHODS
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>
#define REDA_SEQUENCE_USER_API
#define T ImagePlainHelper
#define TSeq ImagePlainHelperSeq
#define REDA_SEQUENCE_EXCLUDE_STRUCT
#define REDA_SEQUENCE_USER_CPP
#include <reda/reda_sequence_decl.h>

NDDSUSERDllExport extern ImagePlainHelper*
ImagePlainHelper_create();

NDDSUSERDllExport extern void
ImagePlainHelper_delete(ImagePlainHelper* sample);

NDDSUSERDllExport
RTIBool ImagePlainHelper_initialize(
    ImagePlainHelper* self);

NDDSUSERDllExport
RTIBool ImagePlainHelper_initialize_ex(
    ImagePlainHelper* self,RTIBool allocatePointers,RTIBool allocateMemory);

NDDSUSERDllExport
RTIBool ImagePlainHelper_initialize_w_params(
    ImagePlainHelper* self,
    const struct DDS_TypeAllocationParams_t * allocParams);  

NDDSUSERDllExport
RTIBool ImagePlainHelper_finalize(
    ImagePlainHelper* self);

NDDSUSERDllExport
RTIBool ImagePlainHelper_finalize_w_return(
    ImagePlainHelper* self);

NDDSUSERDllExport
void ImagePlainHelper_finalize_ex(
    ImagePlainHelper* self,RTIBool deletePointers);

NDDSUSERDllExport
void ImagePlainHelper_finalize_w_params(
    ImagePlainHelper* self,
    const struct DDS_TypeDeallocationParams_t * deallocParams);

NDDSUSERDllExport
void ImagePlainHelper_finalize_optional_members(
    ImagePlainHelper* self, RTIBool deletePointers);  

NDDSUSERDllExport
RTIBool ImagePlainHelper_copy(
    ImagePlainHelper* dst,
    const ImagePlainHelper* src);

#if (defined(RTI_WIN32) || defined (RTI_WINCE) || defined(RTI_INTIME)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols.
*/
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#ifndef NDDS_STANDALONE_TYPE
namespace rti { 
    namespace xcdr {
        template <>
        struct type_code<Dimension> {
            static const RTIXCdrTypeCode * get();
        };

        template <>
        struct type_programs<Dimension::Base> {
            static RTIXCdrInterpreterPrograms * get();
        };
        template <>
        struct type_code<DimensionPlainHelper> {
            static const RTIXCdrTypeCode * get();
        };

        template <>
        struct type_code<Image> {
            static const RTIXCdrTypeCode * get();
        };

        template <>
        struct type_programs<Image::Base> {
            static RTIXCdrInterpreterPrograms * get();
        };
        template <>
        struct type_code<ImagePlainHelper> {
            static const RTIXCdrTypeCode * get();
        };

    } 
}

namespace rti { namespace flat {

        template <>
        struct flat_type_traits<Dimension> {
            typedef DimensionPlainHelper plain_type;
            typedef DimensionOffset offset;
        };

        template <>
        struct flat_type_traits<DimensionOffset> {
            typedef Dimension flat_type;
            typedef DimensionPlainHelper plain_type;
        };

        template <>
        struct flat_type_traits<DimensionConstOffset> 
        : flat_type_traits<DimensionOffset> {
        };

        template <>
        struct flat_type_traits<Image> {
            typedef ImagePlainHelper plain_type;
            typedef ImageOffset offset;
        };

        template <>
        struct flat_type_traits<ImageOffset> {
            typedef Image flat_type;
            typedef ImagePlainHelper plain_type;
        };

        template <>
        struct flat_type_traits<ImageConstOffset> 
        : flat_type_traits<ImageOffset> {
        };

    } } // namespace rti::flat

#include "rti/flat/FlatSampleImpl.hpp"
#endif

#if (defined(RTI_WIN32) || defined(RTI_WINCE)) && defined(NDDS_USER_DLL_EXPORT)
/* If the code is building on Windows, stop exporting symbols. */
#undef NDDSUSERDllExport
#define NDDSUSERDllExport
#endif

#endif /* quickstart */

