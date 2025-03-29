#include <stdlib.h>
#include <stdio.h>

typedef int (*test_function)();

struct test_suite_struct {
  int number_tests;
  test_function* tests;
};

typedef struct test_suite_struct test_suite;

test_suite initTestSuite (test_function[]);

int executeTests (test_suite);

int assertIntEqual (int, int);

int assertIntMatrixAllEqualZero (int num_rows, int num_columns, int** received);

int assertIntMatrix (int num_rows, int num_columns, int** received, int expected[4][4]);