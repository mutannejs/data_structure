#include "./test_suite.h"

extern int resultTest;
extern int testCount;

test_suite initTestSuite (test_function tests[], char* name) {
  test_suite suite;

  int i = 0;
  while (tests[i] != NULL) i++;

  suite.number_tests = i;
  suite.tests = tests;
  suite.name = name;

  testCount = 0;

  return suite;
}

int executeTests (test_suite suite) {
  int result;
  char* suiteName;

  result = 1;
  suiteName = (char*) calloc(strlen(suite.name) + 3, sizeof(char));
  sprintf(suiteName, " %s ", suite.name);

  initSetupTerm();

  printf(">>>>> Suite de Teste:");
  printInBold(suiteName, -1, -1);
  printf("<<<<<\n");

  for (int i = 0; i < suite.number_tests; i++) {
    suite.tests[i]();
    result *= resultTest;
  }

  if (result)
    printf("Todos os testes obtiveram sucesso.\n\n");
  else
    printf("\n\n");

  return result;
}

void newTest (char* testName) {
  resultTest = 1;
  testCount += 1;

  printf("(%d) %s:", testCount, testName);
}

void endTest () {
  if (resultTest) {
    printSuccess();
  }
}
