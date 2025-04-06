#include "../src/adjacency_matrix/adjacency_matrix.c"
#include "../test_suite/test_suite.c"

adjacency_matrix initGraph(int);

void testInitGraph();
void testAddEdges();
void testGetSize();
void testInitInvalidGraph();
void testInvalidInsertion();

int main() {
  test_function t_functions[] = {
    testInitGraph,
    testAddEdges,
    testGetSize,
    testInitInvalidGraph,
    testInvalidInsertion,
    NULL,
  };

  test_suite s_test = initTestSuite(t_functions, "Adjacency Matrix");
  executeTests(s_test);

  return 0;
}

adjacency_matrix initGraph(int step) {
  adjacency_matrix am = nullGraph(4);

  if (step == 0) return am;

  addEdge(am, 0, 1);
  addEdge(am, 0, 2);
  addEdge(am, 0, 2);
  addEdge(am, 0, 3);
  addEdge(am, 2, 2);

  return am;
}

void testInitGraph() {
  int** receivedMatrix;
  int expectedNumVertices, receivedNumVertices;
  adjacency_matrix am;

  am = initGraph(0);

  expectedNumVertices = 4;
  receivedNumVertices = *am.n;
  receivedMatrix = am.matrix;

  newTest("Inicialização do grafo");
  assertIntEqual(receivedNumVertices, expectedNumVertices);
  assertIntMatrixAllEqualZero(expectedNumVertices, expectedNumVertices, receivedMatrix);
  endTest();
}

void testAddEdges() {
  int** expectedMatrix,
    ** receivedMatrix;
  int numVertices = 4;
  adjacency_matrix am;

  am = initGraph(1);

  expectedMatrix = mockMatrix(
    numVertices,
    numVertices,
    numVertices * numVertices,
    0, 1, 2, 1,
    1, 0, 0, 0,
    2, 0, 2, 0,
    1, 0, 0, 0
  );
  receivedMatrix = am.matrix;

  newTest("Inserção de arestas");
  assertIntMatrix(numVertices, numVertices, receivedMatrix, expectedMatrix);
  endTest();
}

void testGetSize() {
  int expectedSize, receivedSize;
  adjacency_matrix am;

  am = initGraph(1);

  expectedSize = 5;
  receivedSize = getSize(am);

  newTest("Tamanho do grafo");
  assertIntEqual(expectedSize, receivedSize);
  endTest();
}

void testInitInvalidGraph() {
  int expectedNumVertices, receivedNumVertices;
  adjacency_matrix am;

  am = nullGraph(-2);

  expectedNumVertices = 0;
  receivedNumVertices = *am.n;

  newTest("Inicialização inválida");
  assertIntEqual(receivedNumVertices, expectedNumVertices);
  endTest();
}

void testInvalidInsertion() {
  int expectedSize, receivedSize;
  adjacency_matrix am;

  am = initGraph(1);

  addEdge(am, -2, -2);

  receivedSize = getSize(am);
  expectedSize = 5;

  newTest("Inserção inválida");
  assertIntEqual(receivedSize, expectedSize);
  endTest();
}
