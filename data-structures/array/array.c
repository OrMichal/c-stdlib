#include "array.h"
#include <stdio.h>
#include <stdlib.h>

Array *new_Array(size_t itemSize) {
  size_t len = 8;
  Array *array = malloc(sizeof(Array));
  if (!array) {
    printf("Error: could not initialize Array");
    exit(1);
  }

  array->items = malloc(itemSize * len);
  array->itemSize = itemSize;
  array->size = len;
  array->count = 0;

  return array;
}

void Resize(Array *array) {
  size_t newSize = array->size << 1;
  void **tmp = malloc(newSize * array->itemSize);
  for (int i = 0; i < (int)array->count - 1; i++) {
    tmp[i] = array->items[i];
  }

  free(array->items);
  array->items = tmp;
  array->size = newSize;
}

int ArrayAddItem(Array *array, void *item) {
  if (array->count + 1 >= array->size) {
    Resize(array);
  }

  array->items[array->count++] = item;

  return 0;
}

int ArrayRemoveItemAt(Array *array, int index) {
  if (index > array->count) {
    return 2;
  }

  free(array->items[index]);

  for (int j = index; j < array->count - 1; j++) {
    array->items[j] = array->items[j + 1];
  }

  array->count--;

  return 0;
}

void *ArrayGetItemByIndex(Array *array, int index) {
  if (index < 0 || index >= array->count)
    return NULL;

  return array->items[index];
}
