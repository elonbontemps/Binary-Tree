/*************************************************************************
 *
 * Assignment 5: Delete edge, vertex
 *
 * File Name: GraphType.h
 * Course:    CPTR 242
 *
 */
#ifndef GRAPH_TYPE_H
#define GRAPH_TYPE_H

#include "QueueType.h"
#include <fstream>

using namespace std;

const int NULL_EDGE = 0;

template <class VertexType>
// Assumption: VertexType is a type for which the "=",
// "==", and "<<" operators are defined
class GraphType {
public:
  GraphType();         // Default of 50 vertices
  GraphType(int maxV); // maxV <= 50
  ~GraphType();

  void AddVertex(VertexType);
  void AddEdge(VertexType, VertexType, int);
  int WeightIs(VertexType, VertexType);
  void GetToVertices(VertexType, QueueType<VertexType> &);
  int IndexIs(VertexType);

  void AddUnusedVertex(int index);

  void DeleteEdge(VertexType, VertexType);
  // Pre:  vertex1 and vertex2 are in the set of vertices.
  // Post: (vertex1, vertex2) is not in the set of edges

  void DeleteVertex(VertexType);
  // Pre: vertex1 is in the set of vertices
  // Post: vertex1 is not in the set of vertices

  void Print(std::ofstream &dataFile);

private:
  int numVertices;
  int maxVertices;
  VertexType *vertices;
  int edges[50][50] = {};
  QueueType<VertexType> unusedVertices;
  bool *marks; // marks[i] is mark for vertices[i].
};

#endif // GRAPH_TYPE_H