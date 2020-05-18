/*************************************************************************
 *
 * Assignment 5: Delete edge, vertex
 *
 * File Name: GraphType.cpp
 * Course:    CPTR 242
 *
 */
#include "GraphType.h"

// Post: Arrays of size 50 are dynamically allocated for
//       marks and vertices.  numVertices is set to 0;
//       maxVertices is set to 50.
template <class VertexType> GraphType<VertexType>::GraphType() {
  numVertices = 0;
  maxVertices = 50;
  vertices = new VertexType[50];
  marks = new bool[50];
}

// Post: Arrays of size maxV are dynamically allocated for
//       marks and vertices.
//       numVertices is set to 0; maxVertices is set to maxV.
template <class VertexType> GraphType<VertexType>::GraphType(int maxV) {
  numVertices = 0;
  maxVertices = maxV;
  vertices = new VertexType[maxV];
  marks = new bool[maxV];
}

// Post: arrays for vertices and marks have been deallocated.
template <class VertexType> GraphType<VertexType>::~GraphType() {
  delete[] vertices;
  delete[] marks;
}

// Post: vertex has been stored in vertices.
//       Corresponding row and column of edges has been set to NULL_EDGE.
//       numVertices has been incremented.
template <class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex) {
  for (int i = 0; i < numVertices; i++) {
    if (vertices[i] == vertex) {
      // Vertex already added.
      return;
    }
  }

  int vertexToUse;

  if (!unusedVertices.IsEmpty()) {
    unusedVertices.Dequeue(vertexToUse);
    vertices[vertexToUse] = vertex;
  } else {
    vertexToUse = numVertices;
    vertices[vertexToUse] = vertex;
    numVertices++;
  }

  for (int index = 0; index < numVertices; index++) {
    edges[vertexToUse][index] = NULL_EDGE;
    edges[index][vertexToUse] = NULL_EDGE;
  }
}

// Post: Returns the index of vertex in vertices.
template <class VertexType>
int GraphType<VertexType>::IndexIs(VertexType vertex) {
  int index = 0;

  while (!(vertex == vertices[index]))
    index++;
  return index;
}

template <class VertexType>
void GraphType<VertexType>::AddUnusedVertex(int index) {
  unusedVertices.Enqueue(index);
}

// Post: Edge (fromVertex, toVertex) is stored in edges.
template <class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex, VertexType toVertex,
                                    int weight) {
  int row;
  int col;

  row = IndexIs(fromVertex);
  col = IndexIs(toVertex);
  edges[row][col] = weight;
}

// Post: Returns the weight associated with the edge
//       (fromVertex, toVertex).
template <class VertexType>
int GraphType<VertexType>::WeightIs(VertexType fromVertex,
                                    VertexType toVertex) {
  int row;
  int col;

  row = IndexIs(fromVertex);
  col = IndexIs(toVertex);
  return edges[row][col];
}

// Post:
template <class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex,
                                          QueueType<VertexType> &adjVertices) {
  int fromIndex;
  int toIndex;

  fromIndex = IndexIs(vertex);
  for (toIndex = 0; toIndex < numVertices; toIndex++) {
    if (edges[fromIndex][toIndex] != NULL_EDGE) {
      adjVertices.Enqueue(vertices[toIndex]);
    }
  }
}

template <class VertexType>
void GraphType<VertexType>::Print(std::ofstream &dataFile) {
  dataFile << "  ";

  for (int x = 0; x < numVertices; x++) {
    if (vertices[x] != 0) {
      // Only print live vertices
      dataFile << vertices[x] << " ";
    }
  }

  for (int x = 0; x < numVertices; x++) {
    if (vertices[x] != 0) {
      dataFile << std::endl << vertices[x] << " ";
      for (int y = 0; y < numVertices; y++) {
        if (vertices[y] != 0) {
          dataFile << edges[x][y] << " ";
        }
      }
    }
  }

  dataFile << std::endl;
}

template class GraphType<int>;
