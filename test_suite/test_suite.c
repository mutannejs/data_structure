#include "./test_suite.h"

extern int resultTest;

test_suite initTestSuite (test_function tests[]) {
  test_suite suite;

  int i = 0;
  while (tests[i] != NULL) i++;

  suite.number_tests = i;
  suite.tests = tests;

  return suite;
}

int executeTests (test_suite suite) {
  int result = 1;

  setupterm(NULL, STDOUT_FILENO, NULL);
  putp(exit_attribute_mode);

  for (int i = 0; i < suite.number_tests; i++) {
    suite.tests[i]();
    result *= resultTest;
  }

  if (result) printf("\nTodos os testes obtiveram sucesso.\n");

  return result;
}

void newTest (char* testName) {
  resultTest = 1;

  printf("%s:", testName);
}

void endTest () {
  if (resultTest) {
    putp(tparm(set_a_foreground, 2));
    putp(enter_bold_mode);
    printf(" success\n");
    putp(exit_attribute_mode);
    fflush(stdout);
  }
}
