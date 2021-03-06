// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_message_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_message_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3008000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3008000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_message_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_message_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_message_2eproto;
class RequestMessage;
class RequestMessageDefaultTypeInternal;
extern RequestMessageDefaultTypeInternal _RequestMessage_default_instance_;
class ResponseMessage;
class ResponseMessageDefaultTypeInternal;
extern ResponseMessageDefaultTypeInternal _ResponseMessage_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::RequestMessage* Arena::CreateMaybeMessage<::RequestMessage>(Arena*);
template<> ::ResponseMessage* Arena::CreateMaybeMessage<::ResponseMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class RequestMessage :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:RequestMessage) */ {
 public:
  RequestMessage();
  virtual ~RequestMessage();

  RequestMessage(const RequestMessage& from);
  RequestMessage(RequestMessage&& from) noexcept
    : RequestMessage() {
    *this = ::std::move(from);
  }

  inline RequestMessage& operator=(const RequestMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline RequestMessage& operator=(RequestMessage&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const RequestMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const RequestMessage* internal_default_instance() {
    return reinterpret_cast<const RequestMessage*>(
               &_RequestMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(RequestMessage* other);
  friend void swap(RequestMessage& a, RequestMessage& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline RequestMessage* New() const final {
    return CreateMaybeMessage<RequestMessage>(nullptr);
  }

  RequestMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<RequestMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const RequestMessage& from);
  void MergeFrom(const RequestMessage& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(RequestMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "RequestMessage";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_message_2eproto);
    return ::descriptor_table_message_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes client_ = 2;
  void clear_client_();
  static const int kClientFieldNumber = 2;
  const std::string& client_() const;
  void set_client_(const std::string& value);
  void set_client_(std::string&& value);
  void set_client_(const char* value);
  void set_client_(const void* value, size_t size);
  std::string* mutable_client_();
  std::string* release_client_();
  void set_allocated_client_(std::string* client_);

  // bytes server_ = 3;
  void clear_server_();
  static const int kServerFieldNumber = 3;
  const std::string& server_() const;
  void set_server_(const std::string& value);
  void set_server_(std::string&& value);
  void set_server_(const char* value);
  void set_server_(const void* value, size_t size);
  std::string* mutable_server_();
  std::string* release_server_();
  void set_allocated_server_(std::string* server_);

  // bytes sign_ = 4;
  void clear_sign_();
  static const int kSignFieldNumber = 4;
  const std::string& sign_() const;
  void set_sign_(const std::string& value);
  void set_sign_(std::string&& value);
  void set_sign_(const char* value);
  void set_sign_(const void* value, size_t size);
  std::string* mutable_sign_();
  std::string* release_sign_();
  void set_allocated_sign_(std::string* sign_);

  // bytes data_ = 5;
  void clear_data_();
  static const int kDataFieldNumber = 5;
  const std::string& data_() const;
  void set_data_(const std::string& value);
  void set_data_(std::string&& value);
  void set_data_(const char* value);
  void set_data_(const void* value, size_t size);
  std::string* mutable_data_();
  std::string* release_data_();
  void set_allocated_data_(std::string* data_);

  // int32 type_ = 1;
  void clear_type_();
  static const int kTypeFieldNumber = 1;
  ::PROTOBUF_NAMESPACE_ID::int32 type_() const;
  void set_type_(::PROTOBUF_NAMESPACE_ID::int32 value);

  // @@protoc_insertion_point(class_scope:RequestMessage)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr client__;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr server__;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr sign__;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data__;
  ::PROTOBUF_NAMESPACE_ID::int32 type__;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_message_2eproto;
};
// -------------------------------------------------------------------

class ResponseMessage :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ResponseMessage) */ {
 public:
  ResponseMessage();
  virtual ~ResponseMessage();

  ResponseMessage(const ResponseMessage& from);
  ResponseMessage(ResponseMessage&& from) noexcept
    : ResponseMessage() {
    *this = ::std::move(from);
  }

  inline ResponseMessage& operator=(const ResponseMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline ResponseMessage& operator=(ResponseMessage&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ResponseMessage& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ResponseMessage* internal_default_instance() {
    return reinterpret_cast<const ResponseMessage*>(
               &_ResponseMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(ResponseMessage* other);
  friend void swap(ResponseMessage& a, ResponseMessage& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ResponseMessage* New() const final {
    return CreateMaybeMessage<ResponseMessage>(nullptr);
  }

  ResponseMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ResponseMessage>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ResponseMessage& from);
  void MergeFrom(const ResponseMessage& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ResponseMessage* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ResponseMessage";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_message_2eproto);
    return ::descriptor_table_message_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // bytes client_ = 3;
  void clear_client_();
  static const int kClientFieldNumber = 3;
  const std::string& client_() const;
  void set_client_(const std::string& value);
  void set_client_(std::string&& value);
  void set_client_(const char* value);
  void set_client_(const void* value, size_t size);
  std::string* mutable_client_();
  std::string* release_client_();
  void set_allocated_client_(std::string* client_);

  // bytes server_ = 4;
  void clear_server_();
  static const int kServerFieldNumber = 4;
  const std::string& server_() const;
  void set_server_(const std::string& value);
  void set_server_(std::string&& value);
  void set_server_(const char* value);
  void set_server_(const void* value, size_t size);
  std::string* mutable_server_();
  std::string* release_server_();
  void set_allocated_server_(std::string* server_);

  // bytes data_ = 5;
  void clear_data_();
  static const int kDataFieldNumber = 5;
  const std::string& data_() const;
  void set_data_(const std::string& value);
  void set_data_(std::string&& value);
  void set_data_(const char* value);
  void set_data_(const void* value, size_t size);
  std::string* mutable_data_();
  std::string* release_data_();
  void set_allocated_data_(std::string* data_);

  // int32 status_ = 1;
  void clear_status_();
  static const int kStatusFieldNumber = 1;
  ::PROTOBUF_NAMESPACE_ID::int32 status_() const;
  void set_status_(::PROTOBUF_NAMESPACE_ID::int32 value);

  // int32 key_ = 2;
  void clear_key_();
  static const int kKeyFieldNumber = 2;
  ::PROTOBUF_NAMESPACE_ID::int32 key_() const;
  void set_key_(::PROTOBUF_NAMESPACE_ID::int32 value);

  // @@protoc_insertion_point(class_scope:ResponseMessage)
 private:
  class HasBitSetters;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr client__;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr server__;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr data__;
  ::PROTOBUF_NAMESPACE_ID::int32 status__;
  ::PROTOBUF_NAMESPACE_ID::int32 key__;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_message_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// RequestMessage

// int32 type_ = 1;
inline void RequestMessage::clear_type_() {
  type__ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 RequestMessage::type_() const {
  // @@protoc_insertion_point(field_get:RequestMessage.type_)
  return type__;
}
inline void RequestMessage::set_type_(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  type__ = value;
  // @@protoc_insertion_point(field_set:RequestMessage.type_)
}

// bytes client_ = 2;
inline void RequestMessage::clear_client_() {
  client__.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& RequestMessage::client_() const {
  // @@protoc_insertion_point(field_get:RequestMessage.client_)
  return client__.GetNoArena();
}
inline void RequestMessage::set_client_(const std::string& value) {
  
  client__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:RequestMessage.client_)
}
inline void RequestMessage::set_client_(std::string&& value) {
  
  client__.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:RequestMessage.client_)
}
inline void RequestMessage::set_client_(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  client__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:RequestMessage.client_)
}
inline void RequestMessage::set_client_(const void* value, size_t size) {
  
  client__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:RequestMessage.client_)
}
inline std::string* RequestMessage::mutable_client_() {
  
  // @@protoc_insertion_point(field_mutable:RequestMessage.client_)
  return client__.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* RequestMessage::release_client_() {
  // @@protoc_insertion_point(field_release:RequestMessage.client_)
  
  return client__.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void RequestMessage::set_allocated_client_(std::string* client_) {
  if (client_ != nullptr) {
    
  } else {
    
  }
  client__.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), client_);
  // @@protoc_insertion_point(field_set_allocated:RequestMessage.client_)
}

// bytes server_ = 3;
inline void RequestMessage::clear_server_() {
  server__.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& RequestMessage::server_() const {
  // @@protoc_insertion_point(field_get:RequestMessage.server_)
  return server__.GetNoArena();
}
inline void RequestMessage::set_server_(const std::string& value) {
  
  server__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:RequestMessage.server_)
}
inline void RequestMessage::set_server_(std::string&& value) {
  
  server__.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:RequestMessage.server_)
}
inline void RequestMessage::set_server_(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  server__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:RequestMessage.server_)
}
inline void RequestMessage::set_server_(const void* value, size_t size) {
  
  server__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:RequestMessage.server_)
}
inline std::string* RequestMessage::mutable_server_() {
  
  // @@protoc_insertion_point(field_mutable:RequestMessage.server_)
  return server__.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* RequestMessage::release_server_() {
  // @@protoc_insertion_point(field_release:RequestMessage.server_)
  
  return server__.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void RequestMessage::set_allocated_server_(std::string* server_) {
  if (server_ != nullptr) {
    
  } else {
    
  }
  server__.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), server_);
  // @@protoc_insertion_point(field_set_allocated:RequestMessage.server_)
}

// bytes sign_ = 4;
inline void RequestMessage::clear_sign_() {
  sign__.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& RequestMessage::sign_() const {
  // @@protoc_insertion_point(field_get:RequestMessage.sign_)
  return sign__.GetNoArena();
}
inline void RequestMessage::set_sign_(const std::string& value) {
  
  sign__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:RequestMessage.sign_)
}
inline void RequestMessage::set_sign_(std::string&& value) {
  
  sign__.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:RequestMessage.sign_)
}
inline void RequestMessage::set_sign_(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  sign__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:RequestMessage.sign_)
}
inline void RequestMessage::set_sign_(const void* value, size_t size) {
  
  sign__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:RequestMessage.sign_)
}
inline std::string* RequestMessage::mutable_sign_() {
  
  // @@protoc_insertion_point(field_mutable:RequestMessage.sign_)
  return sign__.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* RequestMessage::release_sign_() {
  // @@protoc_insertion_point(field_release:RequestMessage.sign_)
  
  return sign__.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void RequestMessage::set_allocated_sign_(std::string* sign_) {
  if (sign_ != nullptr) {
    
  } else {
    
  }
  sign__.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), sign_);
  // @@protoc_insertion_point(field_set_allocated:RequestMessage.sign_)
}

// bytes data_ = 5;
inline void RequestMessage::clear_data_() {
  data__.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& RequestMessage::data_() const {
  // @@protoc_insertion_point(field_get:RequestMessage.data_)
  return data__.GetNoArena();
}
inline void RequestMessage::set_data_(const std::string& value) {
  
  data__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:RequestMessage.data_)
}
inline void RequestMessage::set_data_(std::string&& value) {
  
  data__.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:RequestMessage.data_)
}
inline void RequestMessage::set_data_(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  data__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:RequestMessage.data_)
}
inline void RequestMessage::set_data_(const void* value, size_t size) {
  
  data__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:RequestMessage.data_)
}
inline std::string* RequestMessage::mutable_data_() {
  
  // @@protoc_insertion_point(field_mutable:RequestMessage.data_)
  return data__.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* RequestMessage::release_data_() {
  // @@protoc_insertion_point(field_release:RequestMessage.data_)
  
  return data__.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void RequestMessage::set_allocated_data_(std::string* data_) {
  if (data_ != nullptr) {
    
  } else {
    
  }
  data__.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), data_);
  // @@protoc_insertion_point(field_set_allocated:RequestMessage.data_)
}

// -------------------------------------------------------------------

// ResponseMessage

// int32 status_ = 1;
inline void ResponseMessage::clear_status_() {
  status__ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ResponseMessage::status_() const {
  // @@protoc_insertion_point(field_get:ResponseMessage.status_)
  return status__;
}
inline void ResponseMessage::set_status_(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  status__ = value;
  // @@protoc_insertion_point(field_set:ResponseMessage.status_)
}

// int32 key_ = 2;
inline void ResponseMessage::clear_key_() {
  key__ = 0;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ResponseMessage::key_() const {
  // @@protoc_insertion_point(field_get:ResponseMessage.key_)
  return key__;
}
inline void ResponseMessage::set_key_(::PROTOBUF_NAMESPACE_ID::int32 value) {
  
  key__ = value;
  // @@protoc_insertion_point(field_set:ResponseMessage.key_)
}

// bytes client_ = 3;
inline void ResponseMessage::clear_client_() {
  client__.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& ResponseMessage::client_() const {
  // @@protoc_insertion_point(field_get:ResponseMessage.client_)
  return client__.GetNoArena();
}
inline void ResponseMessage::set_client_(const std::string& value) {
  
  client__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ResponseMessage.client_)
}
inline void ResponseMessage::set_client_(std::string&& value) {
  
  client__.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ResponseMessage.client_)
}
inline void ResponseMessage::set_client_(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  client__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ResponseMessage.client_)
}
inline void ResponseMessage::set_client_(const void* value, size_t size) {
  
  client__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ResponseMessage.client_)
}
inline std::string* ResponseMessage::mutable_client_() {
  
  // @@protoc_insertion_point(field_mutable:ResponseMessage.client_)
  return client__.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ResponseMessage::release_client_() {
  // @@protoc_insertion_point(field_release:ResponseMessage.client_)
  
  return client__.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ResponseMessage::set_allocated_client_(std::string* client_) {
  if (client_ != nullptr) {
    
  } else {
    
  }
  client__.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), client_);
  // @@protoc_insertion_point(field_set_allocated:ResponseMessage.client_)
}

// bytes server_ = 4;
inline void ResponseMessage::clear_server_() {
  server__.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& ResponseMessage::server_() const {
  // @@protoc_insertion_point(field_get:ResponseMessage.server_)
  return server__.GetNoArena();
}
inline void ResponseMessage::set_server_(const std::string& value) {
  
  server__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ResponseMessage.server_)
}
inline void ResponseMessage::set_server_(std::string&& value) {
  
  server__.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ResponseMessage.server_)
}
inline void ResponseMessage::set_server_(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  server__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ResponseMessage.server_)
}
inline void ResponseMessage::set_server_(const void* value, size_t size) {
  
  server__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ResponseMessage.server_)
}
inline std::string* ResponseMessage::mutable_server_() {
  
  // @@protoc_insertion_point(field_mutable:ResponseMessage.server_)
  return server__.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ResponseMessage::release_server_() {
  // @@protoc_insertion_point(field_release:ResponseMessage.server_)
  
  return server__.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ResponseMessage::set_allocated_server_(std::string* server_) {
  if (server_ != nullptr) {
    
  } else {
    
  }
  server__.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), server_);
  // @@protoc_insertion_point(field_set_allocated:ResponseMessage.server_)
}

// bytes data_ = 5;
inline void ResponseMessage::clear_data_() {
  data__.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline const std::string& ResponseMessage::data_() const {
  // @@protoc_insertion_point(field_get:ResponseMessage.data_)
  return data__.GetNoArena();
}
inline void ResponseMessage::set_data_(const std::string& value) {
  
  data__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:ResponseMessage.data_)
}
inline void ResponseMessage::set_data_(std::string&& value) {
  
  data__.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:ResponseMessage.data_)
}
inline void ResponseMessage::set_data_(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  data__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:ResponseMessage.data_)
}
inline void ResponseMessage::set_data_(const void* value, size_t size) {
  
  data__.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:ResponseMessage.data_)
}
inline std::string* ResponseMessage::mutable_data_() {
  
  // @@protoc_insertion_point(field_mutable:ResponseMessage.data_)
  return data__.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ResponseMessage::release_data_() {
  // @@protoc_insertion_point(field_release:ResponseMessage.data_)
  
  return data__.ReleaseNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ResponseMessage::set_allocated_data_(std::string* data_) {
  if (data_ != nullptr) {
    
  } else {
    
  }
  data__.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), data_);
  // @@protoc_insertion_point(field_set_allocated:ResponseMessage.data_)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_message_2eproto
