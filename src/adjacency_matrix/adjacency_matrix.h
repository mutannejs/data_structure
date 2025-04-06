/**
 * Matriz de Adjacência
 * 
 * G: v 0 1 2 3
 *    0 0 1 2 1
 *    1 1 0 0 0
 *    2 2 0 2 0
 *    3 1 0 0 0
 *    v
 * 
 * V(G) = {0, 1, 2, 3}
 * E(G) = {01, 02, 02, 03, 22}
 */

struct adjacency_matrix_struct {
  int* n;
  int** matrix;
};

typedef struct adjacency_matrix_struct adjacency_matrix;

adjacency_matrix nullGraph (int n);

void addEdge (adjacency_matrix, int vertex1, int vertex2);

int getSize (adjacency_matrix);
