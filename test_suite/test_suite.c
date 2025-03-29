#include "./test_suite.h"

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

  for (int i = 0; i < suite.number_tests; i++) {
    if (!suite.tests[i]()) result = 0;
  }

  if (result) printf("Não ocorreu nenhum erro.\n");

  return result;
}

int assertIntEqual (int i1, int i2) {
  return i1 == i2;
}

int assertIntMatrixAllEqualZero(int n, int m, int** received) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (received[i][j] != 0) {
        printf("Erro na linha %d e coluna %d\n", i, j);
        printf("%d é diferente de 0\n\n", received[i][j]);
        return 0;
      }
    }
  }
  return 1;
}

int assertIntMatrix (int n, int m, int** received, int expected[4][4]) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (received[i][j] != expected[i][j]) {
        printf("Erro na linha %d e coluna %d\n", i, j);
        printf("%d (recebido) é diferente de %d (esperado)\n\n", received[i][j], expected[i][j]);
        return 0;
      }
    }
  }
  return 1;
}