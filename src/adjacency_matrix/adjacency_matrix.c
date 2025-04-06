#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include "./adjacency_matrix.h"

adjacency_matrix nullGraph (int n) {
  if (n < 0)
    return nullGraph(0);

  adjacency_matrix am;
  int* vertices;

  am.n = (int*) calloc(1, sizeof(int));
  am.matrix = (int**) malloc(n * sizeof(int*));

  vertices = (int*) calloc(n * n, sizeof(int));

  *(am.n) = n;

  for (int i = 0; i < n; i++) {
    am.matrix[i] = &vertices[i*n];
  }

  return am;
}

void addEdge (adjacency_matrix am, int vertex1, int vertex2) {
  int isValidInsertion =
    vertex1 >= 0
    and vertex1 < *(am.n)
    and vertex2 >=0
    and vertex2 < *(am.n);
  if (not isValidInsertion)
    return;

  am.matrix[vertex1][vertex2] += 1;
  am.matrix[vertex2][vertex1] += 1;
}

int getSize (adjacency_matrix am) {
  int size = 0;

  for (int i = 0; i < *am.n; i++) {
    for (int j = 0; j < *am.n; j++) {
      size += am.matrix[i][j];
    }
  }

  return size / 2;
}
