#include <term.h>
#include <stdio.h>
#include <unistd.h>
#include "./utils.c"

void printSuccess ();

void printFailed ();

void assertIntEqual (int i1, int i2);

void assertIntMatrixAllEqualZero (int n, int m, int** received);

void assertIntMatrix (int n, int m, int** received, int** expected);
