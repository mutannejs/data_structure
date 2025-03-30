#include <stdio.h>
#include "./incidence_matrix.h"

incidence_matrix nullGraph (int n, int m) {
  incidence_matrix im;

  im.n = (int*) calloc(1, sizeof(int));
  *(im.n) = n;
  im.m = (int*) calloc(1, sizeof(int));
  *(im.m) = m;
  im.addedEdges = (int*) calloc(1, sizeof(int));;
  *(im.addedEdges) = 0;
  im.matrix = (int**) malloc(n * sizeof(int*));

  int* vertices = (int*) calloc(n * m, sizeof(int));

  for (int i = 0; i < n; i++) {
    im.matrix[i] = &vertices[i*m];
  }

  return im;
}

void addEdge (incidence_matrix im, int vertex1, int vertex2) {
  int column = (*im.addedEdges);

  im.matrix[vertex1][column] += 1;
  im.matrix[vertex2][column] += 1;

  *(im.addedEdges) += 1;
}

void removeEdge (incidence_matrix im, int edge) {
  for (int i = 0; i < *im.n; i++) {
    im.matrix[i][edge] = 0;
  }

  *(im.addedEdges) -= 1;
}
