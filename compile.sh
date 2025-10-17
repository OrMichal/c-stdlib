#!/bin/bash
rm -rf ./bin/main

gcc main.c data-structures/array/array.c linq/linq.c data-structures/hashmap/hashmap.c -o ./bin/main

./bin/main
