#include <stdlib.h>
#include <stdio.h>
#include <term.h>
#include <unistd.h>
#include "./assert_functions.c"

typedef void (*test_function)();

struct test_suite_struct {
  int number_tests;
  test_function* tests;
};

typedef struct test_suite_struct test_suite;


int resultTest;


test_suite initTestSuite (test_function[]);

int executeTests (test_suite);

void newTest (char* testName);

void endTest ();

// int assertIntEqual (int, int);

// int assertIntMatrixAllEqualZero (int num_rows, int num_columns, int** received);

// int assertIntMatrix (int num_rows, int num_columns, int** received, int expected[4][4]);
