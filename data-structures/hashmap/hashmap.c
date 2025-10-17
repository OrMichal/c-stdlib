#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>

HashMap *new_HashMap(size_t keySize, size_t valueSize) {
  Array *pairs = new_Array(keySize + valueSize);
  size_t pairsSize = pairs->itemSize * pairs->size;
  HashMap *hashmap = malloc(sizeof(HashMap));

  hashmap->keySize = keySize;
  hashmap->valueSize = valueSize;
  hashmap->keyValuePairs = pairs;

  return hashmap;
}

KeyValuePair *new_KeyValuePair(HashMap *hashmap, void *key, void *value) {
  size_t pairSize = hashmap->keySize + hashmap->valueSize + sizeof(int);
  KeyValuePair *pair = malloc(pairSize);
  if (!pair) {
    printf("Could not initialize KeyValuePair");
    exit(1);
  }

  pair->key = key;
  pair->value = value;
  pair->size = pairSize;

  return pair;
}

int HashMapAddItem(HashMap *hashmap, void *key, void *value) {
  KeyValuePair *pair = new_KeyValuePair(hashmap, key, value);
  ArrayAddItem(hashmap->keyValuePairs, (void *)pair);

  return 0;
}
