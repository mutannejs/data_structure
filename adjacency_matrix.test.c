#include "./src/adjacency_matrix/adjacency_matrix.c"
#include "./test_suite/test_suite.c"

void testInitGraph();
void testAddEdges();
void testgetSize();

int main() {
  test_function t_functions[] = {
    testInitGraph,
    testAddEdges,
    testgetSize,
    NULL,
  };

  test_suite s_test = initTestSuite(t_functions);
  executeTests(s_test);

  return 0;
}

void testInitGraph() {
  int expectedNumVertex = 4;
  int receivedNumVertex = -1;

  adjacency_matrix am = nullGraph(expectedNumVertex);
  receivedNumVertex = am.n;

  newTest("testInitGraph");
  assertIntEqual(receivedNumVertex, expectedNumVertex);
  assertIntMatrixAllEqualZero(expectedNumVertex, expectedNumVertex, am.matrix);
  endTest();
}

void testAddEdges() {
  int numVertices = 4;
  int expectedMatrix[4][4] = {
    {0, 1, 2, 1},
    {1, 0, 0, 0},
    {2, 0, 2, 0},
    {1, 0, 0, 0}
  };

  adjacency_matrix am = nullGraph(numVertices);
  addEdge(am, 0, 1);
  addEdge(am, 0, 2);
  addEdge(am, 0, 2);
  addEdge(am, 0, 3);
  addEdge(am, 2, 2);

  newTest("testAddEdges");
  assertIntMatrix(numVertices, numVertices, am.matrix, expectedMatrix);
  endTest();
}

void testgetSize() {
  int numVertices = 4;
  int expectedSize = 5;
  int receivedSize = -1;

  adjacency_matrix am = nullGraph(numVertices);
  addEdge(am, 0, 1);
  addEdge(am, 0, 2);
  addEdge(am, 0, 2);
  addEdge(am, 0, 3);
  addEdge(am, 2, 2);
  receivedSize = getSize(am);

  newTest("testgetSize");
  assertIntEqual(expectedSize, receivedSize);
  endTest();
}