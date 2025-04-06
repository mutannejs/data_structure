#!/bin/bash

if [ ! -d build/ ]; then
  mkdir build
fi

gcc -o build/am.run tests/adjacency_matrix.test.c -std=c99 -Wall -ltinfo
./build/am.run

gcc -o build/im.run tests/incidence_matrix.test.c -std=c99 -Wall -ltinfo
./build/im.run
