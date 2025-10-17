#include "data-structures/array/array.h"
#include "data-structures/hashmap/hashmap.h"
#include "linq/linq.h"
#include <stdio.h>

struct Person {
  int Age;
  int ID;
};

struct Person *new_Person(int id, int age) {
  struct Person *p = malloc(sizeof(struct Person));
  p->Age = age;
  p->ID = id;
  return p;
}

void PrintPersonData(void *person) {
  struct Person *per = (struct Person *)person;

  printf("|person| id: %d, age: %d\n", per->ID, per->Age);
}

void PrintKeyValuePairData(void *kvp) {
  KeyValuePair *kv = (KeyValuePair *)kvp;

  printf("key: %s, ", (char *)kv->key);
  PrintPersonData(kv->value);
}

int main() {
  HashMap *hashmap = new_HashMap(sizeof(char *), sizeof(struct Person));
  for (int i = 0; i < 10; i++) {
    struct Person *p = new_Person(1, 18);
    HashMapAddItem(hashmap, (void *)"nihha", (void *)p);
  }
  LinqForEach(hashmap->keyValuePairs, PrintKeyValuePairData);

  return 0;
}
