#include <stdio.h>
#include "./adjacency_matrix.h"

adjacency_matrix nullGraph (int n) {
  adjacency_matrix am;

  am.n = n;
  am.matrix = (int**) malloc(n * sizeof(int*));

  int* vertices = (int*) malloc(n * n * sizeof(int));

  for (int i = 0; i < n*n; i++) {
    vertices[i] = 0;
  }

  for (int i = 0; i < n; i++) {
    am.matrix[i] = &vertices[i*n];
  }

  return am;
}

void addEdge (adjacency_matrix am, int vertex1, int vertex2) {
  am.matrix[vertex1][vertex2]++;
  am.matrix[vertex2][vertex1]++;
}

void removeEdge (adjacency_matrix am, int vertex1, int vertex2) {
  am.matrix[vertex1][vertex2]--;
  am.matrix[vertex2][vertex1]--;
}

int getSize (adjacency_matrix am) {
  int size = 0;

  for (int i = 0; i < am.n; i++) {
    for (int j = 0; j < am.n; j++) {
      size += am.matrix[i][j];
    }
  }

  return size / 2;
}
