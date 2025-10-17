#ifndef array_h
#define array_h

#include <stdlib.h>

typedef struct {
  size_t count;
  size_t size;
  size_t itemSize;
  void **items;
} Array;

Array *new_Array(size_t itemSize);
int ArrayAddItem(Array *array, void *item);
void *ArrayGetItemByIndex(Array *array, int index);
int ArrayRemoveItemAt(Array *array, int index);

#endif
