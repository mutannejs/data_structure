#include "./assert_functions.h"

extern int resultTest;

void assertIntEqual (int i1, int i2) {
  if (i1 != i2) {
    putp(tparm(set_a_foreground, 9));
    putp(enter_bold_mode);
    printf(" failed\n");
    putp(exit_attribute_mode);
    fflush(stdout);
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
        putp(tparm(set_a_foreground, 9));
        putp(enter_bold_mode);
        printf(" failed\n");
        putp(exit_attribute_mode);
        fflush(stdout);
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

void assertIntMatrix (int n, int m, int** received, int expected[4][4]) {
  if (!resultTest) return;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (received[i][j] != expected[i][j]) {
        putp(tparm(set_a_foreground, 9));
        putp(enter_bold_mode);
        printf(" failed\n");
        putp(exit_attribute_mode);
        fflush(stdout);
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