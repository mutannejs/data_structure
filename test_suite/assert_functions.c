#include "./assert_functions.h"

extern int resultTest;

void printFailed () {
  printColored(" failed\n", COLOR_ERROR, -1);
}

void printSuccess () {
  printColored(" success\n", COLOR_SUCCESS, -1);
}

void assertIntEqual (int i1, int i2) {
  if (!resultTest) return;

  if (i1 != i2) {
    printFailed();
    printf(
      "\tassertIntEqual: Erro - %d (recebido) é diferente de %d\n",
      i1, i2
    );
    resultTest = 0;
  }
}

void assertIntMatrixAllEqualZero(int n, int m, int** received) {
  if (!resultTest) return;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (received[i][j] != 0) {
        printFailed();
        printf(
          "\tassertIntMatrixAllEqualZero: Erro na linha %d e coluna %d, %d (recebido) é diferente de 0\n",
          i, j, received[i][j]
        );
        resultTest = 0;
        return;
      }
    }
  }
}

void assertIntMatrix (int n, int m, int** received, int** expected) {
  if (!resultTest) return;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (received[i][j] != expected[i][j]) {
        printFailed();
        printf(
          "\tassertIntMatrix: Erro na linha %d e coluna %d, %d (recebido) é diferente de %d (esperado)\n",
          i, j, received[i][j], expected[i][j]
        );
        resultTest = 0;
        return;
      }
    }
  }
}
