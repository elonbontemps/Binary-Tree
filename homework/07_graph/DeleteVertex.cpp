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
  int index = IndexIs(vertex1);

// Keep this at the end of the file.
template class GraphType<int>;