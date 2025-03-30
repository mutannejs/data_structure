#include <stdlib.h>
#include <stdio.h>
#include <term.h>
#include <unistd.h>
#include "./assert_functions.c"
#include "./mock.c"

typedef void (*test_function)();

struct test_suite_struct {
  int number_tests;
  test_function* tests;
  char* name;
};

typedef struct test_suite_struct test_suite;


int resultTest;


test_suite initTestSuite (test_function[], char* name);

int executeTests (test_suite);

void newTest (char* testName);

void endTest ();
