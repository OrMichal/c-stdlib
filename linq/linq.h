#ifndef linq_h
#define linq_h

#include "../data-structures/array/array.h"

Array *LinqSelect(Array *array, int (*predicate)(void *));
void LinqForEach(Array *array, void (*action)(void *));

#endif
