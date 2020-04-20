/*************************************************************************
 *
 * Project 1: ImdbList header
 *
 * File Name: ImdbList.h
 * Course:    CPTR 242
 * Date:      April 7, 2019
 */

#include "Array.h"
#include "Bridges.h"
#include "DataSource.h"
#include "SLelement.h"

using namespace bridges;

#ifndef IMDB_LIST_H
#define IMDB_LIST_H

// Bridges library must be provided by the user of this class.

class ImdbList {
public:
  ImdbList();
  // Constructor

  ~ImdbList();
  // Destructor

  void MakeEmpty();
  // Function: Returns the list to the empty state.
  // Post:  List is empty.

  bool IsFull() const;
  // Function:  Determines whether list is full.
  // Pre:  List has been initialized.
  // Post: Function value = (list is full)

  int GetLength() const;
  // Function: Determines the number of elements in list.
  // Pre:  List has been initialized.
  // Post: Function value = number of elements in list

  void GetActor(string name, string &movies, bool &found);
  // Function: Retrieves list element whose key matches item's key (if present).
  // Pre:  List has been initialized.
  // Post: If there is an element someItem whose key matches
  //       item's key, then found = true and someItem is returned;
  // 	 otherwise found = false and item is returned.
  //       List is unchanged.

  void PutActor(string name, string movies, int count);
  // Function: Adds item to list.
  // Pre:  List has been initialized.
  //       List is not full.
  //       item is not in list.
  // Post: item is in list.

  void DeleteActor(string name);
  // Function: Deletes the element whose key matches item's key.
  // Pre:  List has been initialized.
  //       Key member of item is initialized.
  //       One and only one element in list has a key matching item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Function: Initializes current position for an iteration through the list.
  // Pre:  List has been initialized.
  // Post: Current position is prior to list.

  void GetNextActor(string &name, string &movies);
  // Function: Gets the next element in list.
  // Pre:  List has been initialized and has not been changed since last call.
  //       Current position is defined.
  //       Element at current position is not last in list.
  //
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

  SLelement<string> *GetHead();
  // Function: Returns the pointer to the beginning of the list.
  // Pre:  List has been initialized.
  // Post: List pointer is returned.

private:
  SLelement<string> *listData;
  int length;
  SLelement<string> *currentPos;
};

#endif // IMDB_LIST_H
