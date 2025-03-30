#!/bin/bash

gcc -o am.run adjacency_matrix.test.c -std=c99 -Wall -ltinfo
./am.run

gcc -o im.run incidence_matrix.test.c -std=c99 -Wall -ltinfo
./im.run