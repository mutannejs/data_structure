/**
 * Matriz de Adjacência
 * 
 * G: e 0 1 2 3 4
 *    0 0 1 1 1 0
 *    1 1 1 0 0 2
 *    2 1 0 1 1 0
 *    v
 * 
 * V(G) = {0, 1, 2}
 * E(G) = {0 = 11, 1 = 01, 2 = 02, 3 = 02, 4 = 11}
 */

struct incidence_matrix_struct {
  int* n;
  int* m;
  int* addedEdges;
  int** matrix;
};

typedef struct incidence_matrix_struct incidence_matrix;

incidence_matrix nullGraph (int n, int m);

void addEdge (incidence_matrix, int vertex1, int vertex2);
