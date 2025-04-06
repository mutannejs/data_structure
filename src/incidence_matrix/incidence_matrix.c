#include <stdlib.h>
#include <stdio.h>
#include <iso646.h>
#include "./incidence_matrix.h"

incidence_matrix nullGraph (int n, int m) {
  int isValidInsertion = n >= 0 and m >= 0;
  if (not isValidInsertion)
    return nullGraph(0, 0);

  incidence_matrix im;
  int* vertices;

  im.n = (int*) calloc(1, sizeof(int));
  im.m = (int*) calloc(1, sizeof(int));
  im.addedEdges = (int*) calloc(1, sizeof(int));
  im.matrix = (int**) malloc(n * sizeof(int*));

  vertices = (int*) calloc(n * m, sizeof(int));

  *(im.n) = n;
  *(im.m) = m;
  *(im.addedEdges) = 0;

  for (int i = 0; i < n; i++) {
    im.matrix[i] = &vertices[i*m];
  }

  return im;
}

void addEdge (incidence_matrix im, int vertex1, int vertex2) {
  int column = (*im.addedEdges);

  int isValidInsertion =
    vertex1 >= 0
    and vertex1 < *(im.n)
    and vertex2 >=0
    and vertex2 < *(im.n)
    and column < *(im.m);
  if (not isValidInsertion)
    return;

  im.matrix[vertex1][column] += 1;
  im.matrix[vertex2][column] += 1;

  *(im.addedEdges) += 1;
}
