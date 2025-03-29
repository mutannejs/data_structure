#!/bin/bash

gcc -o run adjacency_matrix.test.c -std=c99 -Wall -ltinfo
./run