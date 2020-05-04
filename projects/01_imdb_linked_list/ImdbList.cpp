/*************************************************************************
 *
 * Project 1: ImdbList implemented using linked list
 *
 * File Name: ImdbList.cpp
 * Name:      Elon Bontemps
 * Course:    CPTR 242
 * Date:      April 27, 2020
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
  currentPos = NULL;
  listData = NULL;
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
  // Create Element
  SLelement<string> *newNode = new SLelement<string>(actor, movies);
  if (this->listData == NULL) {
    newNode->setNext(NULL);
    this->listData = newNode;
  } else if (newNode->getValue() <= listData->getValue()) {
    newNode->setNext(this->listData);
    this->listData = newNode;
  } else {
    SLelement<string> *currNode = this->listData;
    while (currNode->getNext() != NULL &&
           currNode->getNext()->getValue() < newNode->getValue()) {
      currNode = currNode->getNext();
    }
    newNode->setNext(currNode->getNext());
    currNode->setNext(newNode);
  }
  this->length++;

  // Creating visualization
  // Set size and color based on movies
  string color = "";
  double size = 0;

  if (count < 10) {
    color = "blue";
    size = 10.0;
  } else if (count < 50) {
    color = "orange";
    size = 20.0;
  } else if (count < 100) {
    color = "green";
    size = 30.0;
  } else {
    color = "purple";
    size = 40.0;
  }
  newNode->setSize(size);
  newNode->setColor(Color(color));
}
//     // Add the element to the list
//   newNode->setNext(listData);
//   listData = newNode;

//   // Update the length
//   length++;

void ImdbList::GetActor(string actor, string &movies, bool &found) {
  SLelement<string> *currNode = this->listData;
  while (currNode->getNext() != NULL) {
    if (currNode->getValue() == actor) {
      found = true;
      movies = currNode->getLabel();
      return;
    }
    currNode = currNode->getNext();
  }
  found = false;
}

void ImdbList::DeleteActor(string actor) {
  SLelement<string> *currNode = this->listData;
  if (currNode->getValue() == actor) {
    if (currNode->getNext() != NULL) {
      this->listData = currNode->getNext();
    }
    free(currNode);
    this->length--;
    return;
  }

void ImdbList::ResetList() { currentPos = NULL; }

void ImdbList::GetNextActor(string &actor, string &movies) {
  if (this->currentPos == NULL || this->currentPos->getNext() == NULL) {
    this->currentPos = this->listData;
    actor = this->currentPos->getValue();
    movies = this->currentPos->getLabel();
  } else {
    this->currentPos = this->currentPos->getNext();
    actor = this->currentPos->getValue();
    movies = this->currentPos->getLabel();
  }
}
