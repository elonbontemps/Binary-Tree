/*************************************************************************
 *
 * Assignment: DeleteVertex
 *
 * File Name: DeleteVertex.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */

#include "GraphType.h"

// IMPLEMENTATION FOR DeleteVertex HERE
template <class VertexType>
void GraphType<VertexType>::DeleteVertex(VertexType vertex1) {
  // Deletion of vertex
  int index = IndexIs(vertex1);
  for (int i = 0; i < numVertices; i++) {
    if (edges[index][i]) {
      DeleteEdge(vertex1, vertices[i]);
    }
  }
  for (int i = 0; i < numVertices; i++) {
    if (edges[i][index]) {
      DeleteEdge(vertices[i], vertex1);
    }
  }
  AddUnusedVertex(index);
  vertices[index] = 0;
  return;
}
// Keep this at the end of the file.
template class GraphType<int>;