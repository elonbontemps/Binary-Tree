/*************************************************************************
 *
 * Assignment: DeleteEdge
 *
 * File Name: DeleteEdge.cpp
 * Name:        ?
 * Course:      CPTR 242
 * Date:        ?
 */

#include "GraphType.h"

// IMPLEMENTATION FOR DeleteEdge HERE
template <class VertexType>
void GraphType<VertexType>::DeleteEdge(VertexType vertex1, VertexType vertex2) {
  int index1 = IndexIs(vertex1);
  int index2 = IndexIs(vertex2);
//setting = 0 for DeleteEdge
  edges[index1][index2] = 0;
}
// Keep this at the end of the file.
template class GraphType<int>;