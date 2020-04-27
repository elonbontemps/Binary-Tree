/*************************************************************************
 *
 * Project 1: ImdbList implemented using linked list
 *
 * File Name: ImdbList.cpp
 * Name:      ??
 * Course:    CPTR 242
 * Date:      ??
 *
 */
#include "ImdbList.h"
#include "Array.h"
#include "Bridges.h"
#include "DataSource.h"
#include "SLelement.h"

using namespace bridges;

ImdbList::ImdbList() {
  // Class constructor
  length = 0;
  listData = NULL;
  currentPos = NULL
}

ImdbList::~ImdbList() {
  // Post: List is empty; all items have been deallocated.
  MakeEmpty();
}

bool ImdbList::IsFull() const {
  // Returns true if there is no room for another actor
  //  on the free store; false otherwise.
  SLelement<string> *location;
  try {
    location = new SLelement<string>;
    delete location;
    return false;
  } catch (std::bad_alloc exception) {
    return true;
  }
}

int ImdbList::GetLength() const {
  // Post: Number of items in the list is returned.
  return length;
}

void ImdbList::MakeEmpty() {
  SLelement<string> *currNode = this->listData;
  SLelement<string> *nextNode;

  while (currNode->getNext() != NULL) {
    nextNode = currNode->getNext();
    free(currNode);
    currNode = nextNode;
  }
  this->listData = NULL;
  this->currentPos = NULL;
  this->length = 0;
}

SLelement<string> *ImdbList::GetHead() { return listData; }

void ImdbList::PutActor(string actor, string movies, int count) {
  // TODO Add code here.

  // Create Element
  SLelement<string> *newNode = new SLelement<string>(actor, movies);

  // Creating visualization
  // Set size and color based on movies
  string color = "";
  double size = E;

  if (count < 10) {
    color = "green";
    size = 10.0
  } else if (count < 50) {
    color = "yellow";
    size = 20.0
  } else if (count < 100) {
    color = "orange";
    size = 30.0
  } else {
    color = "red";
    size = 40.0
  }

  newNode->setSize(size);
  newNode->setColor(Color(color));
}
    // Add the element to the list
  newNode->setNext(listData);
  listData = newNode;

  // Update the length
  length++;
}

void ImdbList::GetActor(string actor, string &movies, bool &found) {
  // TODO Add code here.
}

void ImdbList::DeleteActor(string actor) {
  SLelement<string> *currNode = this->listData;
  while (currNode->getNext() != NULL) {
    if (currNode->getNext()->getValue() == actor) {
      SLelement<string> *prevNode = currNode;
      currNode = currNode->getNext();
      SLelement<string> *nextNode = currNode->getNext();
      free(currNode);
      prevNode->setNext(nextNode);
      return;
    }
    currNode = currNode->getNext();
  }
  this->length--;
}

void ImdbList::ResetList() {
  currentPos = NULL; }
}

void ImdbList::GetNextActor(string &actor, string &movies) {

}
