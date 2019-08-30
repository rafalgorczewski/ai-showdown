// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: state.proto

#ifndef PROTOBUF_INCLUDED_state_2eproto
#define PROTOBUF_INCLUDED_state_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3007000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3007000 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
#include <google/protobuf/unknown_field_set.h>
#include "common.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_state_2eproto

// Internal implementation detail -- do not use these members.
struct TableStruct_state_2eproto {
  static const ::google::protobuf::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::ParseTable schema[5]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::google::protobuf::internal::FieldMetadata field_metadata[];
  static const ::google::protobuf::internal::SerializationTable serialization_table[];
  static const ::google::protobuf::uint32 offsets[];
};
void AddDescriptors_state_2eproto();
class Map;
class MapDefaultTypeInternal;
extern MapDefaultTypeInternal _Map_default_instance_;
class Projectile;
class ProjectileDefaultTypeInternal;
extern ProjectileDefaultTypeInternal _Projectile_default_instance_;
class State;
class StateDefaultTypeInternal;
extern StateDefaultTypeInternal _State_default_instance_;
class Tile;
class TileDefaultTypeInternal;
extern TileDefaultTypeInternal _Tile_default_instance_;
class Unit;
class UnitDefaultTypeInternal;
extern UnitDefaultTypeInternal _Unit_default_instance_;
namespace google {
namespace protobuf {
template<> ::Map* Arena::CreateMaybeMessage<::Map>(Arena*);
template<> ::Projectile* Arena::CreateMaybeMessage<::Projectile>(Arena*);
template<> ::State* Arena::CreateMaybeMessage<::State>(Arena*);
template<> ::Tile* Arena::CreateMaybeMessage<::Tile>(Arena*);
template<> ::Unit* Arena::CreateMaybeMessage<::Unit>(Arena*);
}  // namespace protobuf
}  // namespace google

enum Tile_Type {
  Tile_Type_FLOOR = 0,
  Tile_Type_WATER = 1,
  Tile_Type_WALL = 2,
  Tile_Type_Tile_Type_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::min(),
  Tile_Type_Tile_Type_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::max()
};
bool Tile_Type_IsValid(int value);
const Tile_Type Tile_Type_Type_MIN = Tile_Type_FLOOR;
const Tile_Type Tile_Type_Type_MAX = Tile_Type_WALL;
const int Tile_Type_Type_ARRAYSIZE = Tile_Type_Type_MAX + 1;

const ::google::protobuf::EnumDescriptor* Tile_Type_descriptor();
inline const ::std::string& Tile_Type_Name(Tile_Type value) {
  return ::google::protobuf::internal::NameOfEnum(
    Tile_Type_descriptor(), value);
}
inline bool Tile_Type_Parse(
    const ::std::string& name, Tile_Type* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Tile_Type>(
    Tile_Type_descriptor(), name, value);
}
enum Projectile_Type {
  Projectile_Type_BOMB = 0,
  Projectile_Type_Projectile_Type_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::min(),
  Projectile_Type_Projectile_Type_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::max()
};
bool Projectile_Type_IsValid(int value);
const Projectile_Type Projectile_Type_Type_MIN = Projectile_Type_BOMB;
const Projectile_Type Projectile_Type_Type_MAX = Projectile_Type_BOMB;
const int Projectile_Type_Type_ARRAYSIZE = Projectile_Type_Type_MAX + 1;

const ::google::protobuf::EnumDescriptor* Projectile_Type_descriptor();
inline const ::std::string& Projectile_Type_Name(Projectile_Type value) {
  return ::google::protobuf::internal::NameOfEnum(
    Projectile_Type_descriptor(), value);
}
inline bool Projectile_Type_Parse(
    const ::std::string& name, Projectile_Type* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Projectile_Type>(
    Projectile_Type_descriptor(), name, value);
}
enum Class {
  KNIGHT = 0,
  ARCHER = 1,
  BOMBERMAN = 2,
  Class_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::min(),
  Class_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<::google::protobuf::int32>::max()
};
bool Class_IsValid(int value);
const Class Class_MIN = KNIGHT;
const Class Class_MAX = BOMBERMAN;
const int Class_ARRAYSIZE = Class_MAX + 1;

const ::google::protobuf::EnumDescriptor* Class_descriptor();
inline const ::std::string& Class_Name(Class value) {
  return ::google::protobuf::internal::NameOfEnum(
    Class_descriptor(), value);
}
inline bool Class_Parse(
    const ::std::string& name, Class* value) {
  return ::google::protobuf::internal::ParseNamedEnum<Class>(
    Class_descriptor(), name, value);
}
// ===================================================================

class Unit final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Unit) */ {
 public:
  Unit();
  virtual ~Unit();

  Unit(const Unit& from);

  inline Unit& operator=(const Unit& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Unit(Unit&& from) noexcept
    : Unit() {
    *this = ::std::move(from);
  }

  inline Unit& operator=(Unit&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const Unit& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Unit* internal_default_instance() {
    return reinterpret_cast<const Unit*>(
               &_Unit_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void Swap(Unit* other);
  friend void swap(Unit& a, Unit& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Unit* New() const final {
    return CreateMaybeMessage<Unit>(nullptr);
  }

  Unit* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Unit>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Unit& from);
  void MergeFrom(const Unit& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Unit* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .Position position = 2;
  bool has_position() const;
  void clear_position();
  static const int kPositionFieldNumber = 2;
  const ::Position& position() const;
  ::Position* release_position();
  ::Position* mutable_position();
  void set_allocated_position(::Position* position);

  // int32 id = 1;
  void clear_id();
  static const int kIdFieldNumber = 1;
  ::google::protobuf::int32 id() const;
  void set_id(::google::protobuf::int32 value);

  // .Class class = 3;
  void clear_class_();
  static const int kClassFieldNumber = 3;
  ::Class class_() const;
  void set_class_(::Class value);

  // int32 health = 4;
  void clear_health();
  static const int kHealthFieldNumber = 4;
  ::google::protobuf::int32 health() const;
  void set_health(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Unit)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::Position* position_;
  ::google::protobuf::int32 id_;
  int class__;
  ::google::protobuf::int32 health_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_state_2eproto;
};
// -------------------------------------------------------------------

class Tile final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Tile) */ {
 public:
  Tile();
  virtual ~Tile();

  Tile(const Tile& from);

  inline Tile& operator=(const Tile& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Tile(Tile&& from) noexcept
    : Tile() {
    *this = ::std::move(from);
  }

  inline Tile& operator=(Tile&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const Tile& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Tile* internal_default_instance() {
    return reinterpret_cast<const Tile*>(
               &_Tile_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  void Swap(Tile* other);
  friend void swap(Tile& a, Tile& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Tile* New() const final {
    return CreateMaybeMessage<Tile>(nullptr);
  }

  Tile* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Tile>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Tile& from);
  void MergeFrom(const Tile& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Tile* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Tile_Type Type;
  static const Type FLOOR =
    Tile_Type_FLOOR;
  static const Type WATER =
    Tile_Type_WATER;
  static const Type WALL =
    Tile_Type_WALL;
  static inline bool Type_IsValid(int value) {
    return Tile_Type_IsValid(value);
  }
  static const Type Type_MIN =
    Tile_Type_Type_MIN;
  static const Type Type_MAX =
    Tile_Type_Type_MAX;
  static const int Type_ARRAYSIZE =
    Tile_Type_Type_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Type_descriptor() {
    return Tile_Type_descriptor();
  }
  static inline const ::std::string& Type_Name(Type value) {
    return Tile_Type_Name(value);
  }
  static inline bool Type_Parse(const ::std::string& name,
      Type* value) {
    return Tile_Type_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // .Position position = 2;
  bool has_position() const;
  void clear_position();
  static const int kPositionFieldNumber = 2;
  const ::Position& position() const;
  ::Position* release_position();
  ::Position* mutable_position();
  void set_allocated_position(::Position* position);

  // .Tile.Type type = 1;
  void clear_type();
  static const int kTypeFieldNumber = 1;
  ::Tile_Type type() const;
  void set_type(::Tile_Type value);

  // @@protoc_insertion_point(class_scope:Tile)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::Position* position_;
  int type_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_state_2eproto;
};
// -------------------------------------------------------------------

class Projectile final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Projectile) */ {
 public:
  Projectile();
  virtual ~Projectile();

  Projectile(const Projectile& from);

  inline Projectile& operator=(const Projectile& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Projectile(Projectile&& from) noexcept
    : Projectile() {
    *this = ::std::move(from);
  }

  inline Projectile& operator=(Projectile&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const Projectile& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Projectile* internal_default_instance() {
    return reinterpret_cast<const Projectile*>(
               &_Projectile_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  void Swap(Projectile* other);
  friend void swap(Projectile& a, Projectile& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Projectile* New() const final {
    return CreateMaybeMessage<Projectile>(nullptr);
  }

  Projectile* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Projectile>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Projectile& from);
  void MergeFrom(const Projectile& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Projectile* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  typedef Projectile_Type Type;
  static const Type BOMB =
    Projectile_Type_BOMB;
  static inline bool Type_IsValid(int value) {
    return Projectile_Type_IsValid(value);
  }
  static const Type Type_MIN =
    Projectile_Type_Type_MIN;
  static const Type Type_MAX =
    Projectile_Type_Type_MAX;
  static const int Type_ARRAYSIZE =
    Projectile_Type_Type_ARRAYSIZE;
  static inline const ::google::protobuf::EnumDescriptor*
  Type_descriptor() {
    return Projectile_Type_descriptor();
  }
  static inline const ::std::string& Type_Name(Type value) {
    return Projectile_Type_Name(value);
  }
  static inline bool Type_Parse(const ::std::string& name,
      Type* value) {
    return Projectile_Type_Parse(name, value);
  }

  // accessors -------------------------------------------------------

  // int32 thrown_by_unit_id = 1;
  void clear_thrown_by_unit_id();
  static const int kThrownByUnitIdFieldNumber = 1;
  ::google::protobuf::int32 thrown_by_unit_id() const;
  void set_thrown_by_unit_id(::google::protobuf::int32 value);

  // .Projectile.Type type = 2;
  void clear_type();
  static const int kTypeFieldNumber = 2;
  ::Projectile_Type type() const;
  void set_type(::Projectile_Type value);

  // @@protoc_insertion_point(class_scope:Projectile)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::int32 thrown_by_unit_id_;
  int type_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_state_2eproto;
};
// -------------------------------------------------------------------

class Map final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:Map) */ {
 public:
  Map();
  virtual ~Map();

  Map(const Map& from);

  inline Map& operator=(const Map& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  Map(Map&& from) noexcept
    : Map() {
    *this = ::std::move(from);
  }

  inline Map& operator=(Map&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const Map& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Map* internal_default_instance() {
    return reinterpret_cast<const Map*>(
               &_Map_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    3;

  void Swap(Map* other);
  friend void swap(Map& a, Map& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline Map* New() const final {
    return CreateMaybeMessage<Map>(nullptr);
  }

  Map* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<Map>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const Map& from);
  void MergeFrom(const Map& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Map* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .Tile tiles = 1;
  int tiles_size() const;
  void clear_tiles();
  static const int kTilesFieldNumber = 1;
  ::Tile* mutable_tiles(int index);
  ::google::protobuf::RepeatedPtrField< ::Tile >*
      mutable_tiles();
  const ::Tile& tiles(int index) const;
  ::Tile* add_tiles();
  const ::google::protobuf::RepeatedPtrField< ::Tile >&
      tiles() const;

  // repeated .Unit ally_units = 2;
  int ally_units_size() const;
  void clear_ally_units();
  static const int kAllyUnitsFieldNumber = 2;
  ::Unit* mutable_ally_units(int index);
  ::google::protobuf::RepeatedPtrField< ::Unit >*
      mutable_ally_units();
  const ::Unit& ally_units(int index) const;
  ::Unit* add_ally_units();
  const ::google::protobuf::RepeatedPtrField< ::Unit >&
      ally_units() const;

  // repeated .Unit enemy_units = 3;
  int enemy_units_size() const;
  void clear_enemy_units();
  static const int kEnemyUnitsFieldNumber = 3;
  ::Unit* mutable_enemy_units(int index);
  ::google::protobuf::RepeatedPtrField< ::Unit >*
      mutable_enemy_units();
  const ::Unit& enemy_units(int index) const;
  ::Unit* add_enemy_units();
  const ::google::protobuf::RepeatedPtrField< ::Unit >&
      enemy_units() const;

  // repeated .Projectile projectiles = 4;
  int projectiles_size() const;
  void clear_projectiles();
  static const int kProjectilesFieldNumber = 4;
  ::Projectile* mutable_projectiles(int index);
  ::google::protobuf::RepeatedPtrField< ::Projectile >*
      mutable_projectiles();
  const ::Projectile& projectiles(int index) const;
  ::Projectile* add_projectiles();
  const ::google::protobuf::RepeatedPtrField< ::Projectile >&
      projectiles() const;

  // @@protoc_insertion_point(class_scope:Map)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::Tile > tiles_;
  ::google::protobuf::RepeatedPtrField< ::Unit > ally_units_;
  ::google::protobuf::RepeatedPtrField< ::Unit > enemy_units_;
  ::google::protobuf::RepeatedPtrField< ::Projectile > projectiles_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_state_2eproto;
};
// -------------------------------------------------------------------

class State final :
    public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:State) */ {
 public:
  State();
  virtual ~State();

  State(const State& from);

  inline State& operator=(const State& from) {
    CopyFrom(from);
    return *this;
  }
  #if LANG_CXX11
  State(State&& from) noexcept
    : State() {
    *this = ::std::move(from);
  }

  inline State& operator=(State&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }
  #endif
  static const ::google::protobuf::Descriptor* descriptor() {
    return default_instance().GetDescriptor();
  }
  static const State& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const State* internal_default_instance() {
    return reinterpret_cast<const State*>(
               &_State_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    4;

  void Swap(State* other);
  friend void swap(State& a, State& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline State* New() const final {
    return CreateMaybeMessage<State>(nullptr);
  }

  State* New(::google::protobuf::Arena* arena) const final {
    return CreateMaybeMessage<State>(arena);
  }
  void CopyFrom(const ::google::protobuf::Message& from) final;
  void MergeFrom(const ::google::protobuf::Message& from) final;
  void CopyFrom(const State& from);
  void MergeFrom(const State& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  static const char* _InternalParse(const char* begin, const char* end, void* object, ::google::protobuf::internal::ParseContext* ctx);
  ::google::protobuf::internal::ParseFunc _ParseFunc() const final { return _InternalParse; }
  #else
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const final;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      ::google::protobuf::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(State* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // .Map map = 1;
  bool has_map() const;
  void clear_map();
  static const int kMapFieldNumber = 1;
  const ::Map& map() const;
  ::Map* release_map();
  ::Map* mutable_map();
  void set_allocated_map(::Map* map);

  // @@protoc_insertion_point(class_scope:State)
 private:
  class HasBitSetters;

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  ::Map* map_;
  mutable ::google::protobuf::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_state_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Unit

// int32 id = 1;
inline void Unit::clear_id() {
  id_ = 0;
}
inline ::google::protobuf::int32 Unit::id() const {
  // @@protoc_insertion_point(field_get:Unit.id)
  return id_;
}
inline void Unit::set_id(::google::protobuf::int32 value) {
  
  id_ = value;
  // @@protoc_insertion_point(field_set:Unit.id)
}

// .Position position = 2;
inline bool Unit::has_position() const {
  return this != internal_default_instance() && position_ != nullptr;
}
inline const ::Position& Unit::position() const {
  const ::Position* p = position_;
  // @@protoc_insertion_point(field_get:Unit.position)
  return p != nullptr ? *p : *reinterpret_cast<const ::Position*>(
      &::_Position_default_instance_);
}
inline ::Position* Unit::release_position() {
  // @@protoc_insertion_point(field_release:Unit.position)
  
  ::Position* temp = position_;
  position_ = nullptr;
  return temp;
}
inline ::Position* Unit::mutable_position() {
  
  if (position_ == nullptr) {
    auto* p = CreateMaybeMessage<::Position>(GetArenaNoVirtual());
    position_ = p;
  }
  // @@protoc_insertion_point(field_mutable:Unit.position)
  return position_;
}
inline void Unit::set_allocated_position(::Position* position) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(position_);
  }
  if (position) {
    ::google::protobuf::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      position = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, position, submessage_arena);
    }
    
  } else {
    
  }
  position_ = position;
  // @@protoc_insertion_point(field_set_allocated:Unit.position)
}

// .Class class = 3;
inline void Unit::clear_class_() {
  class__ = 0;
}
inline ::Class Unit::class_() const {
  // @@protoc_insertion_point(field_get:Unit.class)
  return static_cast< ::Class >(class__);
}
inline void Unit::set_class_(::Class value) {
  
  class__ = value;
  // @@protoc_insertion_point(field_set:Unit.class)
}

// int32 health = 4;
inline void Unit::clear_health() {
  health_ = 0;
}
inline ::google::protobuf::int32 Unit::health() const {
  // @@protoc_insertion_point(field_get:Unit.health)
  return health_;
}
inline void Unit::set_health(::google::protobuf::int32 value) {
  
  health_ = value;
  // @@protoc_insertion_point(field_set:Unit.health)
}

// -------------------------------------------------------------------

// Tile

// .Tile.Type type = 1;
inline void Tile::clear_type() {
  type_ = 0;
}
inline ::Tile_Type Tile::type() const {
  // @@protoc_insertion_point(field_get:Tile.type)
  return static_cast< ::Tile_Type >(type_);
}
inline void Tile::set_type(::Tile_Type value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:Tile.type)
}

// .Position position = 2;
inline bool Tile::has_position() const {
  return this != internal_default_instance() && position_ != nullptr;
}
inline const ::Position& Tile::position() const {
  const ::Position* p = position_;
  // @@protoc_insertion_point(field_get:Tile.position)
  return p != nullptr ? *p : *reinterpret_cast<const ::Position*>(
      &::_Position_default_instance_);
}
inline ::Position* Tile::release_position() {
  // @@protoc_insertion_point(field_release:Tile.position)
  
  ::Position* temp = position_;
  position_ = nullptr;
  return temp;
}
inline ::Position* Tile::mutable_position() {
  
  if (position_ == nullptr) {
    auto* p = CreateMaybeMessage<::Position>(GetArenaNoVirtual());
    position_ = p;
  }
  // @@protoc_insertion_point(field_mutable:Tile.position)
  return position_;
}
inline void Tile::set_allocated_position(::Position* position) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete reinterpret_cast< ::google::protobuf::MessageLite*>(position_);
  }
  if (position) {
    ::google::protobuf::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      position = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, position, submessage_arena);
    }
    
  } else {
    
  }
  position_ = position;
  // @@protoc_insertion_point(field_set_allocated:Tile.position)
}

// -------------------------------------------------------------------

// Projectile

// int32 thrown_by_unit_id = 1;
inline void Projectile::clear_thrown_by_unit_id() {
  thrown_by_unit_id_ = 0;
}
inline ::google::protobuf::int32 Projectile::thrown_by_unit_id() const {
  // @@protoc_insertion_point(field_get:Projectile.thrown_by_unit_id)
  return thrown_by_unit_id_;
}
inline void Projectile::set_thrown_by_unit_id(::google::protobuf::int32 value) {
  
  thrown_by_unit_id_ = value;
  // @@protoc_insertion_point(field_set:Projectile.thrown_by_unit_id)
}

// .Projectile.Type type = 2;
inline void Projectile::clear_type() {
  type_ = 0;
}
inline ::Projectile_Type Projectile::type() const {
  // @@protoc_insertion_point(field_get:Projectile.type)
  return static_cast< ::Projectile_Type >(type_);
}
inline void Projectile::set_type(::Projectile_Type value) {
  
  type_ = value;
  // @@protoc_insertion_point(field_set:Projectile.type)
}

// -------------------------------------------------------------------

// Map

// repeated .Tile tiles = 1;
inline int Map::tiles_size() const {
  return tiles_.size();
}
inline void Map::clear_tiles() {
  tiles_.Clear();
}
inline ::Tile* Map::mutable_tiles(int index) {
  // @@protoc_insertion_point(field_mutable:Map.tiles)
  return tiles_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::Tile >*
Map::mutable_tiles() {
  // @@protoc_insertion_point(field_mutable_list:Map.tiles)
  return &tiles_;
}
inline const ::Tile& Map::tiles(int index) const {
  // @@protoc_insertion_point(field_get:Map.tiles)
  return tiles_.Get(index);
}
inline ::Tile* Map::add_tiles() {
  // @@protoc_insertion_point(field_add:Map.tiles)
  return tiles_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Tile >&
Map::tiles() const {
  // @@protoc_insertion_point(field_list:Map.tiles)
  return tiles_;
}

// repeated .Unit ally_units = 2;
inline int Map::ally_units_size() const {
  return ally_units_.size();
}
inline void Map::clear_ally_units() {
  ally_units_.Clear();
}
inline ::Unit* Map::mutable_ally_units(int index) {
  // @@protoc_insertion_point(field_mutable:Map.ally_units)
  return ally_units_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::Unit >*
Map::mutable_ally_units() {
  // @@protoc_insertion_point(field_mutable_list:Map.ally_units)
  return &ally_units_;
}
inline const ::Unit& Map::ally_units(int index) const {
  // @@protoc_insertion_point(field_get:Map.ally_units)
  return ally_units_.Get(index);
}
inline ::Unit* Map::add_ally_units() {
  // @@protoc_insertion_point(field_add:Map.ally_units)
  return ally_units_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Unit >&
Map::ally_units() const {
  // @@protoc_insertion_point(field_list:Map.ally_units)
  return ally_units_;
}

// repeated .Unit enemy_units = 3;
inline int Map::enemy_units_size() const {
  return enemy_units_.size();
}
inline void Map::clear_enemy_units() {
  enemy_units_.Clear();
}
inline ::Unit* Map::mutable_enemy_units(int index) {
  // @@protoc_insertion_point(field_mutable:Map.enemy_units)
  return enemy_units_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::Unit >*
Map::mutable_enemy_units() {
  // @@protoc_insertion_point(field_mutable_list:Map.enemy_units)
  return &enemy_units_;
}
inline const ::Unit& Map::enemy_units(int index) const {
  // @@protoc_insertion_point(field_get:Map.enemy_units)
  return enemy_units_.Get(index);
}
inline ::Unit* Map::add_enemy_units() {
  // @@protoc_insertion_point(field_add:Map.enemy_units)
  return enemy_units_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Unit >&
Map::enemy_units() const {
  // @@protoc_insertion_point(field_list:Map.enemy_units)
  return enemy_units_;
}

// repeated .Projectile projectiles = 4;
inline int Map::projectiles_size() const {
  return projectiles_.size();
}
inline void Map::clear_projectiles() {
  projectiles_.Clear();
}
inline ::Projectile* Map::mutable_projectiles(int index) {
  // @@protoc_insertion_point(field_mutable:Map.projectiles)
  return projectiles_.Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField< ::Projectile >*
Map::mutable_projectiles() {
  // @@protoc_insertion_point(field_mutable_list:Map.projectiles)
  return &projectiles_;
}
inline const ::Projectile& Map::projectiles(int index) const {
  // @@protoc_insertion_point(field_get:Map.projectiles)
  return projectiles_.Get(index);
}
inline ::Projectile* Map::add_projectiles() {
  // @@protoc_insertion_point(field_add:Map.projectiles)
  return projectiles_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Projectile >&
Map::projectiles() const {
  // @@protoc_insertion_point(field_list:Map.projectiles)
  return projectiles_;
}

// -------------------------------------------------------------------

// State

// .Map map = 1;
inline bool State::has_map() const {
  return this != internal_default_instance() && map_ != nullptr;
}
inline void State::clear_map() {
  if (GetArenaNoVirtual() == nullptr && map_ != nullptr) {
    delete map_;
  }
  map_ = nullptr;
}
inline const ::Map& State::map() const {
  const ::Map* p = map_;
  // @@protoc_insertion_point(field_get:State.map)
  return p != nullptr ? *p : *reinterpret_cast<const ::Map*>(
      &::_Map_default_instance_);
}
inline ::Map* State::release_map() {
  // @@protoc_insertion_point(field_release:State.map)
  
  ::Map* temp = map_;
  map_ = nullptr;
  return temp;
}
inline ::Map* State::mutable_map() {
  
  if (map_ == nullptr) {
    auto* p = CreateMaybeMessage<::Map>(GetArenaNoVirtual());
    map_ = p;
  }
  // @@protoc_insertion_point(field_mutable:State.map)
  return map_;
}
inline void State::set_allocated_map(::Map* map) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == nullptr) {
    delete map_;
  }
  if (map) {
    ::google::protobuf::Arena* submessage_arena = nullptr;
    if (message_arena != submessage_arena) {
      map = ::google::protobuf::internal::GetOwnedMessage(
          message_arena, map, submessage_arena);
    }
    
  } else {
    
  }
  map_ = map;
  // @@protoc_insertion_point(field_set_allocated:State.map)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::Tile_Type> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Tile_Type>() {
  return ::Tile_Type_descriptor();
}
template <> struct is_proto_enum< ::Projectile_Type> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Projectile_Type>() {
  return ::Projectile_Type_descriptor();
}
template <> struct is_proto_enum< ::Class> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::Class>() {
  return ::Class_descriptor();
}

}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // PROTOBUF_INCLUDED_state_2eproto
