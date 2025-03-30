#include "./src/incidence_matrix/incidence_matrix.c"
#include "./test_suite/test_suite.c"

incidence_matrix initGraph(int);
void testInitGraph();
void testAddEdges();

int main() {
  test_function t_functions[] = {
    testInitGraph,
    testAddEdges,
    NULL,
  };

  test_suite s_test = initTestSuite(t_functions, "IncidenceMatrix");
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
  int expectedNumVertices, expectedSizeGraph, receivedNumVertices, receivedSizeGraph;
  incidence_matrix im = initGraph(0);

  expectedNumVertices = 3;
  expectedSizeGraph = 5;
  receivedNumVertices = *im.n;
  receivedSizeGraph = *im.m;
  receivedMatrix = im.matrix;

  newTest("testInitGraph");
  assertIntEqual(receivedNumVertices, expectedNumVertices);
  assertIntEqual(receivedSizeGraph, expectedSizeGraph);
  assertIntMatrixAllEqualZero(expectedNumVertices, expectedSizeGraph, receivedMatrix);
  endTest();
}

void testAddEdges() {
  int** expectedMatrix, ** receivedMatrix;
  int numVertices = 3, numEdges = 5;
  incidence_matrix im = initGraph(1);

  expectedMatrix = mockMatrix(
    numVertices,
    numEdges,
    numVertices * numEdges,
    0, 1, 1, 1, 0,
    1, 1, 0, 0, 2,
    1, 0, 1, 1, 0
  );
  receivedMatrix = im.matrix;

  newTest("testAddEdges");
  assertIntMatrix(numVertices, numEdges, receivedMatrix, expectedMatrix);
  endTest();
}
