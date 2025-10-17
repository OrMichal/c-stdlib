#ifndef hashmap_h
#define hashmap_h

#include "../array/array.h"

typedef struct {
  void *key;
  void *value;
  int size;
} KeyValuePair;

typedef struct {
  size_t keySize;
  size_t valueSize;
  Array *keyValuePairs;
} HashMap;

HashMap *new_HashMap(size_t keySize, size_t valueSize);
KeyValuePair *new_KeyValuePair(HashMap *hashmap, void *key, void *value);
int HashMapAddItem(HashMap *hashmap, void *key, void *value);

#endif
