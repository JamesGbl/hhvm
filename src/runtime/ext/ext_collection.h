/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010- Facebook, Inc. (http://www.facebook.com)         |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef __EXT_COLLECTION_H__
#define __EXT_COLLECTION_H__

// >>>>>> Generated by idl.php. Do NOT modify. <<<<<<

#include <runtime/base/base_includes.h>
#include <system/lib/systemlib.h>

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// class Vector

FORWARD_DECLARE_CLASS_BUILTIN(Vector);
class c_Vector : public ExtObjectDataFlags<ObjectData::VectorAttrInit|
                                           ObjectData::UseGet|
                                           ObjectData::UseSet|
                                           ObjectData::UseIsset|
                                           ObjectData::UseUnset>,
                 public Sweepable {
 public:
  DECLARE_CLASS(Vector, Vector, ObjectData)
  friend class c_VectorIterator;
  friend class c_Map;
  friend class c_StableMap;
  friend class ArrayIter;

  public: c_Vector(const ObjectStaticCallbacks *cb = &cw_Vector);
  public: ~c_Vector();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t___destruct();
  DECLARE_METHOD_INVOKE_HELPERS(__destruct);
  public: Object t_add(CVarRef val);
  DECLARE_METHOD_INVOKE_HELPERS(add);
  public: Object t_append(CVarRef val);
  DECLARE_METHOD_INVOKE_HELPERS(append);
  public: Variant t_pop();
  DECLARE_METHOD_INVOKE_HELPERS(pop);
  public: void t_resize(CVarRef sz, CVarRef value);
  DECLARE_METHOD_INVOKE_HELPERS(resize);
  public: Object t_clear();
  DECLARE_METHOD_INVOKE_HELPERS(clear);
  public: bool t_isempty();
  DECLARE_METHOD_INVOKE_HELPERS(isempty);
  public: int64 t_count();
  DECLARE_METHOD_INVOKE_HELPERS(count);
  public: Variant t_at(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(at);
  public: Variant t_get(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(get);
  public: Object t_put(CVarRef key, CVarRef value);
  DECLARE_METHOD_INVOKE_HELPERS(put);
  public: bool t_contains(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(contains);
  public: Array t_toarray();
  DECLARE_METHOD_INVOKE_HELPERS(toarray);
  public: void t_sort(CVarRef col = null);
  DECLARE_METHOD_INVOKE_HELPERS(sort);
  public: void t_reverse();
  DECLARE_METHOD_INVOKE_HELPERS(reverse);
  public: void t_splice(CVarRef offset, CVarRef len = null,
                        CVarRef replacement = null);
  DECLARE_METHOD_INVOKE_HELPERS(splice);
  public: int64 t_linearsearch(CVarRef search_value);
  DECLARE_METHOD_INVOKE_HELPERS(linearsearch);
  public: void t_shuffle();
  DECLARE_METHOD_INVOKE_HELPERS(shuffle);
  public: Object t_getiterator();
  DECLARE_METHOD_INVOKE_HELPERS(getiterator);
  public: String t___tostring();
  DECLARE_METHOD_INVOKE_HELPERS(__tostring);
  public: Variant t___get(Variant name);
  DECLARE_METHOD_INVOKE_HELPERS(__get);
  public: Variant t___set(Variant name, Variant value);
  DECLARE_METHOD_INVOKE_HELPERS(__set);
  public: bool t___isset(Variant name);
  DECLARE_METHOD_INVOKE_HELPERS(__isset);
  public: Variant t___unset(Variant name);
  DECLARE_METHOD_INVOKE_HELPERS(__unset);
  public: static Variant ti_fromarray(const char* cls, CVarRef arr);
  public: static Variant t_fromarray(CVarRef arr) {
    return ti_fromarray("vector", arr);
  }
  DECLARE_METHOD_INVOKE_HELPERS(fromarray);
  public: static Variant ti_fromvector(const char* cls, CVarRef vec);
  public: static Variant t_fromvector(CVarRef vec) {
    return ti_fromvector("vector", vec);
  }
  DECLARE_METHOD_INVOKE_HELPERS(fromvector);
  public: static Variant ti_slice(const char* cls, CVarRef vec, CVarRef offset,
                                  CVarRef len = null);
  public: static Variant t_slice(CVarRef vec, CVarRef offset,
                                 CVarRef len = null) {
    return ti_slice("vector", vec, offset, len);
  }
  DECLARE_METHOD_INVOKE_HELPERS(slice);

  public: TypedValue* at(int64 key) {
    if (UNLIKELY((unsigned long long)key >= (unsigned long long)m_size)) {
      Object e(SystemLib::AllocOutOfBoundsExceptionObject(
        "Key is out of bounds"));
      throw e;
      return NULL;
    }
    return &m_data[key];
  }
  public: TypedValue* get(int64 key) {
    if ((unsigned long long)key >= (unsigned long long)m_size) {
      return NULL;
    }
    return &m_data[key];
  }
  public: void put(int64 key, TypedValue* val) {
    ASSERT(val->m_type != KindOfRef);
    if (UNLIKELY((unsigned long long)key >= (unsigned long long)m_size)) {
      Object e(SystemLib::AllocOutOfBoundsExceptionObject(
        "Key is out of bounds"));
      throw e;
      return;
    }
    if (IS_REFCOUNTED_TYPE(val->m_type)) {
      TV_INCREF(val);
    }
    TypedValue* tv = &m_data[key];
    tvRefcountedDecRef(tv);
    tv->m_data.num = val->m_data.num;
    tv->m_type = val->m_type;
  }
  public: void add(TypedValue* val) {
    ASSERT(val->m_type != KindOfRef);
    ++m_versionNumber;
    if (m_capacity <= m_size) {
      grow();
    }
    if (IS_REFCOUNTED_TYPE(val->m_type)) {
      TV_INCREF(val);
    }
    TypedValue* tv = &m_data[m_size];
    tv->m_data.num = val->m_data.num;
    tv->m_type = val->m_type;
    tv->_count = 0;
    ++m_size;
  }
  public: ObjectData* clone();

  public: void resize(int64 sz, TypedValue* val);
  public: bool contains(int64 key) {
    return ((unsigned long long)key < (unsigned long long)m_size);
  }
  public: int getVersionNumber() {
    return m_versionNumber;
  }
  
  public: static TypedValue* OffsetGet(ObjectData* obj, TypedValue* key);
  public: static void OffsetSet(ObjectData* obj, TypedValue* key,
                                TypedValue* val);
  public: static bool OffsetIsset(ObjectData* obj, TypedValue* key);
  public: static bool OffsetEmpty(ObjectData* obj, TypedValue* key);
  public: static bool OffsetContains(ObjectData* obj, TypedValue* key);
  public: static void OffsetUnset(ObjectData* obj, TypedValue* key);
  public: static void OffsetAppend(ObjectData* obj, TypedValue* val);

  // implemented by HPHP
  public: c_Vector *create();

 private:
  void grow();
  static void throwBadKeyType();

  TypedValue* m_data;
  int m_size;
  int m_capacity;
  int m_versionNumber;
};

///////////////////////////////////////////////////////////////////////////////
// class VectorIterator

FORWARD_DECLARE_CLASS_BUILTIN(VectorIterator);
class c_VectorIterator : public ExtObjectData {
 public:
  DECLARE_CLASS(VectorIterator, VectorIterator, ObjectData)
  friend class c_Vector;

  // need to implement
  public: c_VectorIterator(const ObjectStaticCallbacks *cb = &cw_VectorIterator);
  public: ~c_VectorIterator();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t_current();
  DECLARE_METHOD_INVOKE_HELPERS(current);
  public: Variant t_key();
  DECLARE_METHOD_INVOKE_HELPERS(key);
  public: bool t_valid();
  DECLARE_METHOD_INVOKE_HELPERS(valid);
  public: void t_next();
  DECLARE_METHOD_INVOKE_HELPERS(next);
  public: void t_rewind();
  DECLARE_METHOD_INVOKE_HELPERS(rewind);

  // implemented by HPHP
  public: c_VectorIterator *create();

 private:
  SmartPtr<c_Vector> m_obj;
  ssize_t m_pos;
  int m_versionNumber;
};

///////////////////////////////////////////////////////////////////////////////
// class Map

FORWARD_DECLARE_CLASS_BUILTIN(Map);
class c_Map : public ExtObjectDataFlags<ObjectData::MapAttrInit|
                                        ObjectData::UseGet|
                                        ObjectData::UseSet|
                                        ObjectData::UseIsset|
                                        ObjectData::UseUnset>,
              public Sweepable {
 public:
  DECLARE_CLASS(Map, Map, ObjectData)
  friend class c_MapIterator;
  friend class c_Vector;
  friend class c_StableMap;
  friend class ArrayIter;

  public: static const int32 KindOfTombstone = -1;

  public: c_Map(const ObjectStaticCallbacks *cb = &cw_Map);
  public: ~c_Map();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t___destruct();
  DECLARE_METHOD_INVOKE_HELPERS(__destruct);
  public: Object t_clear();
  DECLARE_METHOD_INVOKE_HELPERS(clear);
  public: bool t_isempty();
  DECLARE_METHOD_INVOKE_HELPERS(isempty);
  public: int64 t_count();
  DECLARE_METHOD_INVOKE_HELPERS(count);
  public: Variant t_at(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(at);
  public: Variant t_get(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(get);
  public: Object t_put(CVarRef key, CVarRef value);
  DECLARE_METHOD_INVOKE_HELPERS(put);
  public: bool t_contains(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(contains);
  public: Object t_remove(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(remove);
  public: Object t_discard(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(discard);
  public: Array t_toarray();
  DECLARE_METHOD_INVOKE_HELPERS(toarray);
  public: Array t_copyasarray();
  DECLARE_METHOD_INVOKE_HELPERS(copyasarray);
  public: Array t_tokeysarray();
  DECLARE_METHOD_INVOKE_HELPERS(tokeysarray);
  public: Object t_values();
  DECLARE_METHOD_INVOKE_HELPERS(values);
  public: Array t_tovaluesarray();
  DECLARE_METHOD_INVOKE_HELPERS(tovaluesarray);
  public: Object t_updatefromarray(CVarRef arr);
  DECLARE_METHOD_INVOKE_HELPERS(updatefromarray);
  public: Object t_updatefromiterable(CVarRef it);
  DECLARE_METHOD_INVOKE_HELPERS(updatefromiterable);
  public: Object t_differencebykey(CVarRef it);
  DECLARE_METHOD_INVOKE_HELPERS(differencebykey);
  public: Object t_getiterator();
  DECLARE_METHOD_INVOKE_HELPERS(getiterator);
  public: String t___tostring();
  DECLARE_METHOD_INVOKE_HELPERS(__tostring);
  public: Variant t___get(Variant name);
  DECLARE_METHOD_INVOKE_HELPERS(__get);
  public: Variant t___set(Variant name, Variant value);
  DECLARE_METHOD_INVOKE_HELPERS(__set);
  public: bool t___isset(Variant name);
  DECLARE_METHOD_INVOKE_HELPERS(__isset);
  public: Variant t___unset(Variant name);
  DECLARE_METHOD_INVOKE_HELPERS(__unset);
  public: static Variant ti_fromarray(const char* cls, CVarRef arr);
  public: static Variant t_fromarray(CVarRef arr) {
    return ti_fromarray("map", arr);
  }
  DECLARE_METHOD_INVOKE_HELPERS(fromarray);
  public: static Variant ti_fromiterable(const char* cls, CVarRef vec);
  public: static Variant t_fromiterable(CVarRef vec) {
    return ti_fromiterable("map", vec);
  }
  DECLARE_METHOD_INVOKE_HELPERS(fromiterable);

  public: static void throwOOB() ATTRIBUTE_COLD;

  public: TypedValue* at(int64 key) {
    Bucket* p = find(key);
    if (LIKELY(p != NULL)) return (TypedValue*)&p->data;
    throwOOB();
    return NULL;
  }
  public: TypedValue* get(int64 key) {
    Bucket* p = find(key);
    if (p) return (TypedValue*)&p->data;
    return NULL;
  }
  public: TypedValue* at(StringData* key) {
    Bucket* p = find(key->data(), key->size(), key->hash());
    if (LIKELY(p != NULL)) return (TypedValue*)&p->data;
    throwOOB();
    return NULL;
  }
  public: TypedValue* get(StringData* key) {
    Bucket* p = find(key->data(), key->size(), key->hash());
    if (p) return (TypedValue*)&p->data;
    return NULL;
  }
  public: void put(int64 key, TypedValue* val) {
    ASSERT(val->m_type != KindOfRef);
    update(key, val);
  }
  public: void put(StringData* key, TypedValue* val) {
    ASSERT(val->m_type != KindOfRef);
    update(key, val);
  }
  public: void remove(int64 key) {
    ++m_versionNumber;
    erase(find(key));
  }
  public: void remove(StringData* key) {
    ++m_versionNumber;
    erase(find(key->data(), key->size(), key->hash()));
  }
  public: bool contains(int64 key) {
    return find(key);
  }
  public: bool contains(StringData* key) {
    return find(key->data(), key->size(), key->hash());
  }
  public: int getVersionNumber() {
    return m_versionNumber;
  }

  public: static TypedValue* OffsetGet(ObjectData* obj, TypedValue* key);
  public: static void OffsetSet(ObjectData* obj, TypedValue* key,
                                TypedValue* val);
  public: static bool OffsetIsset(ObjectData* obj, TypedValue* key);
  public: static bool OffsetEmpty(ObjectData* obj, TypedValue* key);
  public: static bool OffsetContains(ObjectData* obj, TypedValue* key);
  public: static void OffsetUnset(ObjectData* obj, TypedValue* key);
  public: static void OffsetAppend(ObjectData* obj, TypedValue* val);

  public: ObjectData* clone();

  // implemented by HPHP
  public: c_Map *create();

public:
  class Bucket {
  public:
    /**
     * Buckets are 24 bytes and we allocate Buckets continguously in memory
     * without any padding, so some Buckets span multiple cache lines. We
     * access data._count, data.m_type, and ikey/skey during hash lookup, so we
     * intentionally put the data field first so that data._count, data.m_type,
     * and ikey/skey are all next to each other, which means that they will be
     * on the same cache line for 87.5% of the buckets.
     *
     * The key is either a string pointer or an int value, and the _count
     * field in data is used to discriminate the key type. _count = 0 means
     * int, nonzero values contain 31 bits of a string's hashcode. It is
     * critical that when we return &data to clients, that they not read or
     * write the _count field.
     */
    TypedValue   data;
    union {
      int64      ikey;
      StringData *skey;
    };
    // set the top bit for string hashes to make sure the hash
    // value is never zero. hash value 0 corresponds to integer key.
    static inline int32 encodeHash(int32 h) {
      return (h | 0x80000000);
    }
    inline bool hasStrKey() const { return data._count != 0; }
    inline bool hasIntKey() const { return data._count == 0; }
    inline void setStrKey(StringData* k, int64 h) {
      skey = k;
      skey->incRefCount();
      data._count = encodeHash(h);
    }
    inline void setIntKey(int64 k) {
      ikey = k;
      data._count = 0;
    }
    inline int64 hashKey() const {
      return data._count == 0 ? ikey : data._count;
    }
    inline int32 hash() const {
      return data._count;
    }
    bool validValue() {
      return (intptr_t(data.m_type) > 0);
    }
    bool empty() {
      return data.m_type == KindOfUninit;
    }
    bool tombstone() {
      return data.m_type == KindOfTombstone;
    }
    void dump();
  };

private:
  /**
   * Map uses a power of two for the table size and quadratic probing to
   * resolve hash collisions.
   *
   * When an element is removed from the table, a marker called a "tombstone"
   * is left behind in the slot that the element used to occupy. The tombstone
   * will remain in that slot until either (a) the table is resized, or (b) a
   * new element is inserted into that slot.
   *
   * To ensure that hash lookups are efficient, Map keeps the load factor
   * of the table below 75%. If adding a new element causes the load to
   * increase to 75% or greater, we grow the table to lower the load. Note
   * that tombstones count towards load.
   *
   * To ensure that iteration performance is efficient, Map keeps the ratio
   * of # elements / # slots to be at least 18.75%. If removing an element
   * causes the ratio to drop below 18.75%, we shrink the table to increase
   * the ratio.
   *
   * When a Map has never had any removals performed, the load factor is
   * guaranteed to be between 37.5% and 75% (as long as the Map has at least
   * 2 elements).
   */

  Bucket*          m_data;
  uint             m_size;
  uint             m_load;
  uint             m_nLastSlot;
  int              m_versionNumber;

  uintptr_t numSlots() {
    return m_nLastSlot + 1;
  }

  // The maximum load factor is 75%.
  uintptr_t computeMaxLoad() {
    uintptr_t n = numSlots();
    return (n - (n >> 2));
  }

  // When the map is not empty, the minimum allowed ratio
  // of # elements / # slots is 18.75%.
  uintptr_t computeMinElements() {
    uintptr_t n = numSlots();
    return ((n >> 3) + ((n+8) >> 4));
  }

  // We use this funny-looking helper to make g++ use lea and shl
  // instructions instead of imul when indexing into m_data
  Bucket* fetchBucket(Bucket* data, intptr_t slot) const {
    ASSERT(sizeof(Bucket) == 24);
    ASSERT(sizeof(int64) == 8);
    ASSERT(slot >= 0 && slot <= m_nLastSlot);
    intptr_t index = slot + (slot<<1);
    int64_t* ptr = (int64_t*)data;
    return (Bucket*)(&ptr[index]);
  }

  Bucket* fetchBucket(intptr_t slot) const {
    return fetchBucket(m_data, slot);
  }

  Bucket* find(int64 h) const;
  Bucket* find(const char* k, int len, int64 prehash) const;
  Bucket* findForInsert(int64 h) const;
  Bucket* findForInsert(const char* k, int len, int64 prehash) const;

  bool update(int64 h, TypedValue* data);
  bool update(StringData* key, TypedValue* data);
  void erase(Bucket* prev);

  void resize();
  void deleteBuckets();

  ssize_t iter_begin() const;
  ssize_t iter_next(ssize_t prev) const;
  ssize_t iter_prev(ssize_t prev) const;
  Variant iter_key(ssize_t pos) const;
  Variant iter_value(ssize_t pos) const;

  static void throwBadKeyType();
};

///////////////////////////////////////////////////////////////////////////////
// class MapIterator

FORWARD_DECLARE_CLASS_BUILTIN(MapIterator);
class c_MapIterator : public ExtObjectData {
 public:
  DECLARE_CLASS(MapIterator, MapIterator, ObjectData)
  friend class c_Map;

  // need to implement
  public: c_MapIterator(const ObjectStaticCallbacks *cb = &cw_MapIterator);
  public: ~c_MapIterator();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t_current();
  DECLARE_METHOD_INVOKE_HELPERS(current);
  public: Variant t_key();
  DECLARE_METHOD_INVOKE_HELPERS(key);
  public: bool t_valid();
  DECLARE_METHOD_INVOKE_HELPERS(valid);
  public: void t_next();
  DECLARE_METHOD_INVOKE_HELPERS(next);
  public: void t_rewind();
  DECLARE_METHOD_INVOKE_HELPERS(rewind);

  // implemented by HPHP
  public: c_MapIterator *create();

 private:
  SmartPtr<c_Map> m_obj;
  ssize_t m_pos;
  int m_versionNumber;
};

///////////////////////////////////////////////////////////////////////////////
// class StableMap

FORWARD_DECLARE_CLASS_BUILTIN(StableMap);
class c_StableMap : public ExtObjectDataFlags<ObjectData::StableMapAttrInit|
                                              ObjectData::UseGet|
                                              ObjectData::UseSet|
                                              ObjectData::UseIsset|
                                              ObjectData::UseUnset>,
                    public Sweepable {
 public:
  DECLARE_CLASS(StableMap, StableMap, ObjectData)
  friend class c_StableMapIterator;
  friend class c_Vector;
  friend class c_Map;
  friend class ArrayIter;

  public: c_StableMap(const ObjectStaticCallbacks *cb = &cw_StableMap);
  public: ~c_StableMap();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t___destruct();
  DECLARE_METHOD_INVOKE_HELPERS(__destruct);
  public: Object t_clear();
  DECLARE_METHOD_INVOKE_HELPERS(clear);
  public: bool t_isempty();
  DECLARE_METHOD_INVOKE_HELPERS(isempty);
  public: int64 t_count();
  DECLARE_METHOD_INVOKE_HELPERS(count);
  public: Variant t_at(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(at);
  public: Variant t_get(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(get);
  public: Object t_put(CVarRef key, CVarRef value);
  DECLARE_METHOD_INVOKE_HELPERS(put);
  public: bool t_contains(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(contains);
  public: Object t_remove(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(remove);
  public: Object t_discard(CVarRef key);
  DECLARE_METHOD_INVOKE_HELPERS(discard);
  public: Array t_toarray();
  DECLARE_METHOD_INVOKE_HELPERS(toarray);
  public: Array t_copyasarray();
  DECLARE_METHOD_INVOKE_HELPERS(copyasarray);
  public: Array t_tokeysarray();
  DECLARE_METHOD_INVOKE_HELPERS(tokeysarray);
  public: Object t_values();
  DECLARE_METHOD_INVOKE_HELPERS(values);
  public: Array t_tovaluesarray();
  DECLARE_METHOD_INVOKE_HELPERS(tovaluesarray);
  public: Object t_updatefromarray(CVarRef arr);
  DECLARE_METHOD_INVOKE_HELPERS(updatefromarray);
  public: Object t_updatefromiterable(CVarRef it);
  DECLARE_METHOD_INVOKE_HELPERS(updatefromiterable);
  public: Object t_differencebykey(CVarRef it);
  DECLARE_METHOD_INVOKE_HELPERS(differencebykey);
  public: Object t_getiterator();
  DECLARE_METHOD_INVOKE_HELPERS(getiterator);
  public: String t___tostring();
  DECLARE_METHOD_INVOKE_HELPERS(__tostring);
  public: Variant t___get(Variant name);
  DECLARE_METHOD_INVOKE_HELPERS(__get);
  public: Variant t___set(Variant name, Variant value);
  DECLARE_METHOD_INVOKE_HELPERS(__set);
  public: bool t___isset(Variant name);
  DECLARE_METHOD_INVOKE_HELPERS(__isset);
  public: Variant t___unset(Variant name);
  DECLARE_METHOD_INVOKE_HELPERS(__unset);
  public: static Variant ti_fromarray(const char* cls, CVarRef arr);
  public: static Variant t_fromarray(CVarRef arr) {
    return ti_fromarray("map", arr);
  }
  DECLARE_METHOD_INVOKE_HELPERS(fromarray);
  public: static Variant ti_fromiterable(const char* cls, CVarRef vec);
  public: static Variant t_fromiterable(CVarRef vec) {
    return ti_fromiterable("map", vec);
  }
  DECLARE_METHOD_INVOKE_HELPERS(fromiterable);

  public: TypedValue* at(int64 key) {
    Bucket* p = find(key);
    if (LIKELY(p != NULL)) return (TypedValue*)&p->data;
    Object e(SystemLib::AllocOutOfBoundsExceptionObject(
      "Attempted to subscript a non-key"));
    throw e;
    return NULL;
  }
  public: TypedValue* at(StringData* key) {
    Bucket* p = find(key->data(), key->size(), key->hash());
    if (LIKELY(p != NULL)) return (TypedValue*)&p->data;
    Object e(SystemLib::AllocOutOfBoundsExceptionObject(
      "Attempted to subscript a non-key"));
    throw e;
    return NULL;
  }
  public: TypedValue* get(int64 key) {
    Bucket* p = find(key);
    if (p != NULL) return (TypedValue*)&p->data;
    return NULL;
  }
  public: TypedValue* get(StringData* key) {
    Bucket* p = find(key->data(), key->size(), key->hash());
    if (p != NULL) return (TypedValue*)&p->data;
    return NULL;
  }
  public: void put(int64 key, TypedValue* val) {
    update(key, tvAsCVarRef(val));
  }
  public: void put(StringData* key, TypedValue* val) {
    update(key, tvAsCVarRef(val));
  }
  public: void remove(int64 key) {
    ++m_versionNumber;
    erase(findForErase(key));
  }
  public: void remove(StringData* key) {
    ++m_versionNumber;
    erase(findForErase(key->data(), key->size(), key->hash()));
  }
  public: bool contains(int64 key) {
    return find(key);
  }
  public: bool contains(StringData* key) {
    return find(key->data(), key->size(), key->hash());
  }
  public: int getVersionNumber() {
    return m_versionNumber;
  }

  public: static TypedValue* OffsetGet(ObjectData* obj, TypedValue* key);
  public: static void OffsetSet(ObjectData* obj, TypedValue* key,
                                TypedValue* val);
  public: static bool OffsetIsset(ObjectData* obj, TypedValue* key);
  public: static bool OffsetEmpty(ObjectData* obj, TypedValue* key);
  public: static bool OffsetContains(ObjectData* obj, TypedValue* key);
  public: static void OffsetUnset(ObjectData* obj, TypedValue* key);
  public: static void OffsetAppend(ObjectData* obj, TypedValue* val);

  public: ObjectData* clone();

  // implemented by HPHP
  public: c_StableMap *create();

public:
  class Bucket {
  public:
    Bucket() :
      ikey(0), pListNext(NULL), pListLast(NULL), pNext(NULL) {
      data._count = 0;
    }
    Bucket(Variant::NoInit d) :
      data(d), ikey(0), pListNext(NULL), pListLast(NULL), pNext(NULL) {
      data._count = 0;
    }
    Bucket(CVarRef d) :
      data(d), ikey(0), pListNext(NULL), pListLast(NULL), pNext(NULL) {
      data._count = 0;
    }
    // set the top bit for string hashes to make sure the hash
    // value is never zero. hash value 0 corresponds to integer key.
    static inline int32 encodeHash(int32 h) {
      return (h | 0x80000000);
    }
    // These special constructors do not setup all the member fields.
    // They cannot be used along but must be with the following special
    // MapImpl constructor
    Bucket(StringData *k, CVarRef d) : data(d), skey(k) {
      ASSERT(k->isStatic());
      data._count = encodeHash(k->getPrecomputedHash());
    }
    Bucket(int64 k, CVarRef d) : data(d), ikey(k) {
      data._count = 0;
    }
    ~Bucket();

    /* The key is either a string pointer or an int value, and the _count
     * field in data is used to discriminate the key type. _count = 0 means
     * int, nonzero values contain 31 bits of a string's hashcode.
     * It is critical that when we return &data to clients, that they not
     * read or write the _count field! */
    Variant data;
    union {
      int64 ikey;
      StringData* skey;
    };
    Bucket* pListNext;
    Bucket* pListLast;
    Bucket* pNext;

    inline bool hasStrKey() const { return data._count != 0; }
    inline bool hasIntKey() const { return data._count == 0; }
    inline void setStrKey(StringData* k, int64 h) {
      skey = k;
      skey->incRefCount();
      data._count = encodeHash(h);
    }
    inline void setIntKey(int64 k) {
      ikey = k;
      data._count = 0;
    }
    inline int64 hashKey() const {
      return data._count == 0 ? ikey : data._count;
    }
    inline int32 hash() const {
      return data._count;
    }

    /**
     * Memory allocator methods.
     */
    DECLARE_SMART_ALLOCATION_NOCALLBACKS(Bucket);
    void dump();
  };

private:
  uint             m_size;
  uint             m_nTableSize;
  uint             m_nTableMask;
  int              m_versionNumber;
  Bucket*          m_pListHead;
  Bucket*          m_pListTail;
  Bucket**         m_arBuckets;

  Bucket* find(int64 h) const;
  Bucket* find(const char* k, int len, int64 prehash) const;
  Bucket** findForErase(int64 h) const;
  Bucket** findForErase(const char* k, int len, int64 prehash) const;

  bool update(int64 h, CVarRef data);
  bool update(StringData* key, CVarRef data);
  void erase(Bucket** prev);

  void resize();
  void deleteBuckets();

  ssize_t iter_begin() const;
  ssize_t iter_next(ssize_t prev) const;
  ssize_t iter_prev(ssize_t prev) const;
  Variant iter_key(ssize_t pos) const;
  Variant iter_value(ssize_t pos) const;

  static void throwBadKeyType();
};

///////////////////////////////////////////////////////////////////////////////
// class StableMapIterator

FORWARD_DECLARE_CLASS_BUILTIN(StableMapIterator);
class c_StableMapIterator : public ExtObjectData {
 public:
  DECLARE_CLASS(StableMapIterator, StableMapIterator, ObjectData)
  friend class c_StableMap;

  // need to implement
  public: c_StableMapIterator(const ObjectStaticCallbacks *cb = &cw_StableMapIterator);
  public: ~c_StableMapIterator();
  public: void t___construct();
  DECLARE_METHOD_INVOKE_HELPERS(__construct);
  public: Variant t_current();
  DECLARE_METHOD_INVOKE_HELPERS(current);
  public: Variant t_key();
  DECLARE_METHOD_INVOKE_HELPERS(key);
  public: bool t_valid();
  DECLARE_METHOD_INVOKE_HELPERS(valid);
  public: void t_next();
  DECLARE_METHOD_INVOKE_HELPERS(next);
  public: void t_rewind();
  DECLARE_METHOD_INVOKE_HELPERS(rewind);

  // implemented by HPHP
  public: c_StableMapIterator *create();

 private:
  SmartPtr<c_StableMap> m_obj;
  ssize_t m_pos;
  int m_versionNumber;
};

///////////////////////////////////////////////////////////////////////////////

// Helpers for hhvm

inline TypedValue* collectionGet(ObjectData* obj, TypedValue* key) {
  ASSERT(key->m_type != KindOfRef);
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    return c_Vector::OffsetGet(obj, key);
  } else if (ct == Collection::MapType) {
    return c_Map::OffsetGet(obj, key);
  } else if (ct == Collection::StableMapType) {
    return c_StableMap::OffsetGet(obj, key);
  } else {
    ASSERT(false);
    return NULL;
  }
}

inline void collectionSet(ObjectData* obj, TypedValue* key, TypedValue* val) {
  ASSERT(key->m_type != KindOfRef);
  ASSERT(val->m_type != KindOfRef);
  ASSERT(val->m_type != KindOfUninit);
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    c_Vector::OffsetSet(obj, key, val);
  } else if (ct == Collection::MapType) {
    c_Map::OffsetSet(obj, key, val);
  } else if (ct == Collection::StableMapType) {
    c_StableMap::OffsetSet(obj, key, val);
  } else {
    ASSERT(false);
  }
}

inline bool collectionIsset(ObjectData* obj, TypedValue* key) {
  ASSERT(key->m_type != KindOfRef);
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    return c_Vector::OffsetIsset(obj, key);
  } else if (ct == Collection::MapType) {
    return c_Map::OffsetIsset(obj, key);
  } else if (ct == Collection::StableMapType) {
    return c_StableMap::OffsetIsset(obj, key);
  } else {
    ASSERT(false);
    return false;
  }
}

inline bool collectionEmpty(ObjectData* obj, TypedValue* key) {
  ASSERT(key->m_type != KindOfRef);
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    return c_Vector::OffsetEmpty(obj, key);
  } else if (ct == Collection::MapType) {
    return c_Map::OffsetEmpty(obj, key);
  } else if (ct == Collection::StableMapType) {
    return c_StableMap::OffsetEmpty(obj, key);
  } else {
    ASSERT(false);
    return true;
  }
}

inline void collectionUnset(ObjectData* obj, TypedValue* key) {
  ASSERT(key->m_type != KindOfRef);
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    c_Vector::OffsetUnset(obj, key);
  } else if (ct == Collection::MapType) {
    c_Map::OffsetUnset(obj, key);
  } else if (ct == Collection::StableMapType) {
    c_StableMap::OffsetUnset(obj, key);
  } else {
    ASSERT(false);
  }
}

inline void collectionAppend(ObjectData* obj, TypedValue* val) {
  ASSERT(val->m_type != KindOfRef);
  ASSERT(val->m_type != KindOfUninit);
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    c_Vector::OffsetAppend(obj, val);
  } else if (ct == Collection::MapType) {
    c_Map::OffsetAppend(obj, val);
  } else if (ct == Collection::StableMapType) {
    c_StableMap::OffsetAppend(obj, val);
  } else {
    ASSERT(false);
  }
}

// Helpers for hphpc

inline Variant& collectionOffsetGet(ObjectData* obj, int64 offset) {
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    c_Vector* vec = static_cast<c_Vector*>(obj);
    return *(Variant*)(vec->at(offset));
  } else if (ct == Collection::MapType) {
    c_Map* mp = static_cast<c_Map*>(obj);
    return *(Variant*)(mp->at(offset));
  } else if (ct == Collection::StableMapType) {
    c_StableMap* smp = static_cast<c_StableMap*>(obj);
    return *(Variant*)(smp->at(offset));
  } else {
    ASSERT(false);
    return *(Variant*)(NULL);
  }
}

inline Variant& collectionOffsetGet(ObjectData* obj, CStrRef offset) {
  StringData* key = offset.get();
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    Object e(SystemLib::AllocInvalidArgumentExceptionObject(
      "Only integer keys may be used with Vectors"));
    throw e;
    return *(Variant*)(NULL);
  } else if (ct == Collection::MapType) {
    c_Map* mp = static_cast<c_Map*>(obj);
    return *(Variant*)(mp->at(key));
  } else if (ct == Collection::StableMapType) {
    c_StableMap* smp = static_cast<c_StableMap*>(obj);
    return *(Variant*)(smp->at(key));
  } else {
    ASSERT(false);
    return *(Variant*)(NULL);
  }
}

inline Variant& collectionOffsetGet(ObjectData* obj, CVarRef offset) {
  TypedValue* key = (TypedValue*)(&offset);
  if (key->m_type == KindOfRef) {
    key = key->m_data.pref->tv();
  }
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    return *(Variant*)(c_Vector::OffsetGet(obj, key));
  } else if (ct == Collection::MapType) {
    return *(Variant*)(c_Map::OffsetGet(obj, key));
  } else if (ct == Collection::StableMapType) {
    return *(Variant*)(c_StableMap::OffsetGet(obj, key));
  } else {
    ASSERT(false);
    return *(Variant*)(NULL);
  }
}

inline Variant& collectionOffsetGet(ObjectData* obj, bool offset) {
  return collectionOffsetGet(obj, Variant(offset));
}

inline Variant& collectionOffsetGet(ObjectData* obj, double offset) {
  return collectionOffsetGet(obj, Variant(offset));
}

inline Variant& collectionOffsetGet(ObjectData* obj, litstr offset) {
  return collectionOffsetGet(obj, Variant(offset));
}

inline void collectionOffsetSet(ObjectData* obj, int64 offset, CVarRef val) {
  TypedValue* tv = (TypedValue*)(&val);
  if (UNLIKELY(tv->m_type == KindOfRef)) {
    tv = tv->m_data.pref->tv();
  }
  if (UNLIKELY(tv->m_type == KindOfUninit)) {
    tv = (TypedValue*)(&init_null_variant);
  }
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    c_Vector* vec = static_cast<c_Vector*>(obj);
    vec->put(offset, tv);
  } else if (ct == Collection::MapType) {
    c_Map* mp = static_cast<c_Map*>(obj);
    mp->put(offset, tv);
  } else if (ct == Collection::StableMapType) {
    c_StableMap* smp = static_cast<c_StableMap*>(obj);
    smp->put(offset, tv);
  } else {
    ASSERT(false);
  }
}

inline void collectionOffsetSet(ObjectData* obj, CStrRef offset, CVarRef val) {
  StringData* key = offset.get();
  TypedValue* tv = (TypedValue*)(&val);
  if (UNLIKELY(tv->m_type == KindOfRef)) {
    tv = tv->m_data.pref->tv();
  }
  if (UNLIKELY(tv->m_type == KindOfUninit)) {
    tv = (TypedValue*)(&init_null_variant);
  }
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    Object e(SystemLib::AllocInvalidArgumentExceptionObject(
      "Only integer keys may be used with Vectors"));
    throw e;
  } else if (ct == Collection::MapType) {
    c_Map* mp = static_cast<c_Map*>(obj);
    mp->put(key, tv);
  } else if (ct == Collection::StableMapType) {
    c_StableMap* smp = static_cast<c_StableMap*>(obj);
    smp->put(key, tv);
  } else {
    ASSERT(false);
  }
}

inline void collectionOffsetSet(ObjectData* obj, CVarRef offset, CVarRef val) {
  TypedValue* key = (TypedValue*)(&offset);
  if (UNLIKELY(key->m_type == KindOfRef)) {
    key = key->m_data.pref->tv();
  }
  TypedValue* tv = (TypedValue*)(&val);
  if (UNLIKELY(tv->m_type == KindOfRef)) {
    tv = tv->m_data.pref->tv();
  }
  if (UNLIKELY(tv->m_type == KindOfUninit)) {
    tv = (TypedValue*)(&init_null_variant);
  }
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    c_Vector::OffsetSet(obj, key, tv);
  } else if (ct == Collection::MapType) {
    c_Map::OffsetSet(obj, key, tv);
  } else if (ct == Collection::StableMapType) {
    c_StableMap::OffsetSet(obj, key, tv);
  } else {
    ASSERT(false);
  }
}

inline void collectionOffsetSet(ObjectData* obj, bool offset, CVarRef val) {
  collectionOffsetSet(obj, Variant(offset), val);
}

inline void collectionOffsetSet(ObjectData* obj, double offset, CVarRef val) {
  collectionOffsetSet(obj, Variant(offset), val);
}

inline void collectionOffsetSet(ObjectData* obj, litstr offset, CVarRef val) {
  collectionOffsetSet(obj, Variant(offset), val);
}

inline bool collectionOffsetContains(ObjectData* obj, CVarRef offset) {
  TypedValue* key = (TypedValue*)(&offset);
  if (key->m_type == KindOfRef) {
    key = key->m_data.pref->tv();
  }
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    return c_Vector::OffsetContains(obj, key);
  } else if (ct == Collection::MapType) {
    return c_Map::OffsetContains(obj, key);
  } else if (ct == Collection::StableMapType) {
    return c_StableMap::OffsetContains(obj, key);
  } else {
    ASSERT(false);
    return false;
  }
}

inline bool collectionOffsetIsset(ObjectData* obj, CVarRef offset) {
  TypedValue* key = (TypedValue*)(&offset);
  if (key->m_type == KindOfRef) {
    key = key->m_data.pref->tv();
  }
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    return c_Vector::OffsetIsset(obj, key);
  } else if (ct == Collection::MapType) {
    return c_Map::OffsetIsset(obj, key);
  } else if (ct == Collection::StableMapType) {
    return c_StableMap::OffsetIsset(obj, key);
  } else {
    ASSERT(false);
    return false;
  }
}

inline bool collectionOffsetEmpty(ObjectData* obj, CVarRef offset) {
  TypedValue* key = (TypedValue*)(&offset);
  if (key->m_type == KindOfRef) {
    key = key->m_data.pref->tv();
  }
  int ct = obj->getCollectionType();
  if (ct == Collection::VectorType) {
    return c_Vector::OffsetEmpty(obj, key);
  } else if (ct == Collection::MapType) {
    return c_Map::OffsetEmpty(obj, key);
  } else if (ct == Collection::StableMapType) {
    return c_StableMap::OffsetEmpty(obj, key);
  } else {
    ASSERT(false);
    return true;
  }
}

inline void collectionOffsetUnset(ObjectData* obj, CVarRef offset) {
  TypedValue* key = (TypedValue*)(&offset);
  if (UNLIKELY(key->m_type == KindOfRef)) {
    key = key->m_data.pref->tv();
  }
  collectionUnset(obj, key);
}

inline void collectionOffsetAppend(ObjectData* obj, CVarRef val) {
  TypedValue* tv = (TypedValue*)(&val);
  if (UNLIKELY(tv->m_type == KindOfRef)) {
    tv = tv->m_data.pref->tv();
  }
  if (UNLIKELY(tv->m_type == KindOfUninit)) {
    tv = (TypedValue*)(&init_null_variant);
  }
  collectionAppend(obj, tv);
}

///////////////////////////////////////////////////////////////////////////////
}

#endif // __EXT_COLLECTION_H__
