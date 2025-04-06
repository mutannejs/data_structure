#include "../src/incidence_matrix/incidence_matrix.c"
#include "../test_suite/test_suite.c"

incidence_matrix initGraph(int);
void testInitGraph();
void testAddEdges();
void testInitInvalidGraph();
void testInvalidInsertion();

int main() {
  test_function t_functions[] = {
    testInitGraph,
    testAddEdges,
    testInitInvalidGraph,
    testInvalidInsertion,
    NULL,
  };

  test_suite s_test = initTestSuite(t_functions, "Incidence Matrix");
  executeTests(s_test);

  return 0;
}

incidence_matrix initGraph(int step) {
  incidence_matrix im = nullGraph(3, 5);

  if (step == 0) return im;

  addEdge(im, 1, 2);
  addEdge(im, 0, 1);
  addEdge(im, 0, 2);
  addEdge(im, 0, 2);
  addEdge(im, 1, 1);

  return im;
}

void testInitGraph() {
  int** receivedMatrix;
  int expectedNumVertices,
    expectedSizeGraph,
    receivedNumVertices,
    receivedSizeGraph;
  incidence_matrix im;

  im = initGraph(0);

  expectedNumVertices = 3;
  expectedSizeGraph = 5;
  receivedNumVertices = *im.n;
  receivedSizeGraph = *im.m;
  receivedMatrix = im.matrix;

  newTest("Inicialização do grafo");
  assertIntEqual(receivedNumVertices, expectedNumVertices);
  assertIntEqual(receivedSizeGraph, expectedSizeGraph);
  assertIntMatrixAllEqualZero(expectedNumVertices, expectedSizeGraph, receivedMatrix);
  endTest();
}

void testAddEdges() {
  int** expectedMatrix,
    ** receivedMatrix;
  int numVertices, numEdges;
  incidence_matrix im;

  im = initGraph(1);

  numVertices = 3;
  numEdges = 5;
  expectedMatrix = mockMatrix(
    numVertices,
    numEdges,
    numVertices * numEdges,
    0, 1, 1, 1, 0,
    1, 1, 0, 0, 2,
    1, 0, 1, 1, 0
  );
  receivedMatrix = im.matrix;

  newTest("Inserção de arestas");
  assertIntMatrix(numVertices, numEdges, receivedMatrix, expectedMatrix);
  endTest();
}

void testInitInvalidGraph() {
  int expectedNumVertices,
    expectedSizeGraph,
    receivedNumVertices,
    receivedSizeGraph;
  incidence_matrix im;

  im = nullGraph(-2, -2);

  expectedNumVertices = 0;
  expectedSizeGraph = 0;
  receivedNumVertices = *im.n;
  receivedSizeGraph = *im.m;

  newTest("Inicialização inválida");
  assertIntEqual(receivedNumVertices, expectedNumVertices);
  assertIntEqual(receivedSizeGraph, expectedSizeGraph);
  endTest();
}

void testInvalidInsertion() {
  int expectedSizeGraph, receivedSizeGraph;
  incidence_matrix im;

  im = initGraph(1);

  expectedSizeGraph = 5;
  receivedSizeGraph = *im.addedEdges;

  newTest("Inserção inválida");
  assertIntEqual(receivedSizeGraph, expectedSizeGraph);
  endTest();
}
