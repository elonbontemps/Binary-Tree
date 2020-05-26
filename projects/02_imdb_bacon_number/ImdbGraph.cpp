/*************************************************************************
 *
 * Project: ImdbGraph implementation
 *
 * File Name: ImdbGraph.cpp
 * Name:      Elon Bontemps
 * Course:    CPTR 242
 * Date:      May 25, 2020
 *
 */
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

#include "Bridges.h"
#include "DataSource.h"
#include "GraphAdjList.h"
#include "ImdbGraph.h"
#include "SLelement.h"
#include "data_src/ActorMovieIMDB.h"

using namespace bridges;

// Constructor
ImdbGraph::ImdbGraph() {}

// Destructor
ImdbGraph::~ImdbGraph() {}


void ImdbGraph::AddVertex(string actorOrMovie) {
   auto vertices = graph.getVertices();
  if (vertices->find(actorOrMovie) == vertices->end()) {
    graph.addVertex(actorOrMovie);
    graph.getVisualizer(actorOrMovie)->setColor(Color("blue"));
    graph.getVisualizer(actorOrMovie)->setSize(8);
    graph.getVisualizer(actorOrMovie)->setOpacity(1.5);
  }
}

}


void ImdbGraph::AddEdge(string actorOrMovie, string movieOrActor) {
  graph.addEdge(actorOrMovie, movieOrActor, "1");
  graph.addEdge(movieOrActor, actorOrMovie, "1");
  graph.getLinkVisualizer(actorOrMovie, movieOrActor)
      ->setColor(Color("red"));
  graph.getLinkVisualizer(movieOrActor, actorOrMovie)
      ->setColor(Color("red"));
  graph.getLinkVisualizer(actorOrMovie, movieOrActor)->setThickness(1.5);
  graph.getLinkVisualizer(movieOrActor, actorOrMovie)->setThickness(1.5);
}


void ImdbGraph::VisualizeVertex(string actorOrMovie, string color) {
  graph.getVisualizer(actorOrMovie)->setColor(Color(color));
  graph.getVisualizer(actorOrMovie)->setSize(45);
  graph.getVisualizer(actorOrMovie)->setOpacity(2.);
}


void ImdbGraph::VisualizeEdge(string actorOrMovie, string movieOrActor2,
                              string color) {
  graph.getLinkVisualizer(actorOrMovie, movieOrActor2)->setColor(Color(color));
  graph.getLinkVisualizer(movieOrActor2, actorOrMovie)->setColor(Color(color));
  graph.getLinkVisualizer(actorOrMovie, movieOrActor2)->setThickness(8.);
  graph.getLinkVisualizer(movieOrActor2, actorOrMovie)->setThickness(8.);
}


void ImdbGraph::ResetVisualizer() {
  for (auto &vertex : *graph.getVertices()) {
    graph.getVisualizer(vertex.first)->setColor(Color("orange"));
    graph.getVisualizer(vertex.first)->setSize(10);
    graph.getVisualizer(vertex.first)->setOpacity(1.5);

    auto sl_list = graph.getAdjacencyList(vertex.first);
    for (auto sle = sl_list; sle != NULL; sle = sle->getNext()) {
      auto destination = ((Edge<string>)sle->getValue()).to();
      graph.getLinkVisualizer(vertex.first, destination)
          ->setColor(Color("green"));
      graph.getLinkVisualizer(vertex.first, destination)->setThickness(1.);
    }
  }
}


int ImdbGraph::GetBaconNumber(string sourceActor, string destinationActor) {
  if (sourceActor == destinationActor) {
    return 0;
  }
  return -1;
}

