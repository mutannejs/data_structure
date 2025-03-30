#include "./mock.h"

int** mockMatrix (int n, int m, int numCells, ...) {
  int** matrix;
  int* array;
  va_list cellsList;

  numCells = n * m;
  va_start(cellsList, numCells);

  matrix = (int**) malloc(n * sizeof(int*));
  array = (int*) malloc(numCells * sizeof(int));

  for (int i = 0; i < numCells; i++) {
    array[i] = va_arg(cellsList, int);
  }

  for (int i = 0; i < n; i++) {
    matrix[i] = &array[i*m];
  }

  va_end(cellsList);

  return matrix;
}