#include "linq.h"
#include <string.h>

void LinqForEach(Array *array, void (*action)(void *)) {
  for (int i = 0; i < array->count; i++) {
    action(ArrayGetItemByIndex(array, i));
  }
}

Array *LinqFilter(Array *array, int (*predicate)(void *)) {
  Array *res = new_Array(array->itemSize);
  for (int i = 0; i < array->count; i++) {
    if (predicate(array->items[i])) {
      ArrayAddItem(res, array->items[i]);
    }
  }

  return res;
}
