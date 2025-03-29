#include "./src/adjacency_matrix/adjacency_matrix.c"
#include "./test_suite/test_suite.c"

int testInitGraph();
int testAddEdges();

int main() {
  test_function t_functions[] = {
    testInitGraph,
    testAddEdges,
    NULL,
  };

  test_suite s_test = initTestSuite(t_functions);
  executeTests(s_test);

  return 0;
}

int testInitGraph() {
  int expectedNumVertex = 4;
  int receivedNumVertex = -1;
  int result = 0;

  adjacency_matrix am = nullGraph(expectedNumVertex);
  receivedNumVertex = am.n;

  result = assertIntEqual(receivedNumVertex, expectedNumVertex);
  result = 1 * assertIntMatrixAllEqualZero(expectedNumVertex, expectedNumVertex, am.matrix);

  return result;
}

int testAddEdges() {
  int numVertices = 4;
  int expectedMatrix[4][4] = {
    {0, 1, 2, 1},
    {1, 0, 0, 0},
    {2, 0, 1, 0},
    {1, 0, 0, 0}
  };
  int result = 0;

  adjacency_matrix am = nullGraph(numVertices);
  addEdge(am, 0, 1);
  addEdge(am, 0, 2);
  addEdge(am, 0, 2);
  addEdge(am, 0, 3);
  addEdge(am, 2, 2);

  result = assertIntMatrix(numVertices, numVertices, am.matrix, expectedMatrix);

  return result;
}