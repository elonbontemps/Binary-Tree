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

void ImdbGraph::AddEdge(string actorOrMovie, string movieOrActor) {
  graph.addEdge(actorOrMovie, movieOrActor, "1");
  graph.addEdge(movieOrActor, actorOrMovie, "1");
  graph.getLinkVisualizer(actorOrMovie, movieOrActor)->setColor(Color("red"));
  graph.getLinkVisualizer(movieOrActor, actorOrMovie)->setColor(Color("red"));
  graph.getLinkVisualizer(actorOrMovie, movieOrActor)->setThickness(1.5);
  graph.getLinkVisualizer(movieOrActor, actorOrMovie)->setThickness(1.5);
}

void ImdbGraph::VisualizeVertex(string actorOrMovie, string color) {
  graph.getVisualizer(actorOrMovie)->setColor(Color(color));
  graph.getVisualizer(actorOrMovie)->setSize(50);
  graph.getVisualizer(actorOrMovie)->setOpacity(1.);
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
  bool found = false;
  queue<string> toCheck;
  map<string, string> parents;
  toCheck.push(sourceActor);
  int baconNumber = 0;
  
  while (!toCheck.empty()) {
    string v = toCheck.front();
    toCheck.pop();
    if (v == destinationActor) {
      found = true;
      break;
    }
    auto adjList = graph.getAdjacencyList(v);
    for (auto edge = adjList; edge != nullptr; edge = edge->getNext()) {
      auto dest = edge->getValue().to();
      if (parents.count(dest) == 0) {
        parents.emplace(dest, v);
        toCheck.push(dest);
      }
    }
  }
  if (found) {
    string currParent = destinationActor;
    VisualizeVertex(currParent, "orange");
    while (currParent != sourceActor) {
      string parent = parents.at(currParent);
      LinkVisualizer *edge = graph.getLinkVisualizer(parent, currParent);
      VisualizeEdge(parent, currParent, "orange");
      VisualizeVertex(parent, "orange");
      baconNumber++;
      currParent = parent;
    }
    VisualizeVertex(sourceActor, "orange");
    return baconNumber;
  }
  return -1;
}
