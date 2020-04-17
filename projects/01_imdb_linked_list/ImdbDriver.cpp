/*************************************************************************
 *
 * Project 1: IMDB Actor and Movie Linked List
 *
 * File Name: ImdbDriver.cpp
 * Course:    CPTR 242
 * Date:      April 17, 2019
 */
#include "Array.h"
#include "Bridges.h"
#include "BridgesUser.h"
#include "DataSource.h"
#include "ImdbList.h"
#include "SLelement.h"
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace bridges;

//  we will use this class to keep track of the number of movies that an
// 	actor has appeared in; we will use that to color/size the nodes
struct am_obj {
  string movies;
  int num_movies;
};

void PrintList(ofstream &dataFile, ImdbList &list);

int main() {
  // Used for test driver functionality.
  ifstream inFile;
  std::ofstream outFile;
  string inFileName;
  string outFileName;
  string outPutLabel;
  string option;

  // Used to interact with Actor/Movie List.
  string actor;
  string movies;

  ImdbList list;
  bool found; // For use with GetActor
  int numOptions;

  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin >> outPutLabel;

  outFile << outPutLabel << endl;
  if (!inFile) {
    cout << "File not found." << endl;
    return 0;
  }

  inFile >> option;

  // create the Bridges object, set credentials
  BridgesUser bUser;
  Bridges bridges(bUser.getBridgesNumber(), bUser.getBridgesUserID(),
                  bUser.getBridgesAPIKey());

  bridges.setTitle("List with IMDB Actor/Movie Data");
  bridges.setDescription("Here the data is processed to be a list of actors "
                         "with all movies they have been in.");

  // get the actor movie IMDB data
  DataSource ds(&bridges);
  vector<ActorMovieIMDB> am_imdb = ds.getActorMovieIMDBData();

  //  Actors or movies can repeat in the actor-movie pairs; so we will process
  //  the list of actor-movie pairs so that we get a list of actors with all the
  //  movies they have been in. We will use a map for this
  unordered_map<string, am_obj> am_map;
  int max_movies = 0;
  for (auto im : am_imdb) {
    string actor = im.getActor();
    string movie = im.getMovie();

    if (am_map.find(actor) != am_map.end()) {
      am_map[actor].movies = am_map[actor].movies + "\n     " + movie;
      am_map[actor].num_movies++;
      if (am_map[actor].num_movies > max_movies) {
        max_movies = am_map[actor].num_movies;
      }
    } else {
      am_obj amo = {actor + "\n     " + movie, 1};
      am_map[actor] = amo;
    }
  }

  // Test driver menu and options
  numOptions = 0;
  while (option != "Quit") {
    cout << option;
    if (option == "Menu") {
      outFile << "Select options" << endl;
      outFile << "PrintList. Prints list." << endl;
      outFile << "MakeEmpty. Returns the list to the empty state." << endl;
      outFile << "IsFull. Returns whether list is full." << endl;
      outFile << "GetLength. Returns length of list." << endl;
      outFile
          << "GetActor. Retrieves list element whose key matches item's key."
          << endl;
      outFile << "PutActor. Add item to list." << endl;
      outFile
          << "DeleteActor. Deletes the element whose key matches item's key."
          << endl;
      outFile << "ResetList. Reinitializes current position of iteration "
                 "through list."
              << endl;
      outFile << "GetNextActor. Gets next element in list." << endl;
      outFile
          << "Visualize. Builds the bridges visualization and prints the URL."
          << endl;
      outFile << "AddAll. Adds all actors to the list." << endl;
      outFile << "Quit. Quit application." << endl;
      outFile << "Menu. Display menu." << endl;
    } else if (option == "PrintList") {
      PrintList(outFile, list);
    } else if (option == "MakeEmpty") {
      list.MakeEmpty();
      outFile << "List has been emptied." << endl;
    } else if (option == "IsFull") {
      if (list.IsFull()) {
        outFile << "List is full." << endl;
      } else {
        outFile << "List is not full." << endl;
      }
    } else if (option == "GetLength") {
      outFile << "List has " << list.GetLength() << " items." << endl;
    } else if (option == "GetActor") {
      inFile >> actor;
      list.GetActor(actor, movies, found);
      if (found) {
        outFile << "Actor " << actor << " was found." << endl;
      } else {
        outFile << "Actor  " << actor << " was not found." << endl;
      }
    } else if (option == "PutItem") {
      inFile >> actor;
      if (list.IsFull()) {
        outFile << "The array is full. Item not inserted" << endl;
      } else {
        if (am_map.find(actor) != am_map.end()) {
          list.PutActor(actor, am_map[actor].movies, am_map[actor].num_movies);
          outFile << "Actor " << actor << " was inserted into the list."
                  << endl;
        } else {
          outFile << "Actor " << actor << " was not found in dataset." << endl;
        }
      }
    } else if (option == "DeleteActor") {
      inFile >> actor;
      list.DeleteActor(actor);
      outFile << actor << " is deleted." << endl;
    } else if (option == "ResetList") {
      list.ResetList();
      outFile << "List was reset." << endl;
    } else if (option == "GetNextActor") {
      string actor, movies;
      list.GetNextActor(actor, movies);
      outFile << "The next item in the list is " << actor << "." << endl;
    } else if (option == "Visualize") {
      bridges.setDataStructure(list.GetHead());
      bridges.visualize();
      outFile << "List was visualized." << endl;
    } else if (option == "AddAll") {
      for (auto im : am_map) {
        list.PutActor(im.first, im.second.movies, im.second.num_movies);
      }
      outFile << "All actors have been added." << endl;
    } else {
      cout << option << " is not a valid command." << endl;
    }
    numOptions++;
    cout << " Command number " << numOptions << " completed." << endl;
    inFile >> option;
  };

  cout << "Quit" << endl << "Testing completed." << endl;
  inFile.close();
  outFile.close();
  return 0;
}

void PrintList(ofstream &dataFile, ImdbList &list) {
  // Pre:  list has been initialized.
  //       dataFile is open for writing.
  // Post: Each component in list has been written to dataFile.
  //       dataFile is still open.
  dataFile << "PrintList: ";
  list.ResetList();
  int length = list.GetLength();
  if (length == 0) {
    dataFile << "List is empty.";
  } else {
    for (int counter = 1; counter <= length; counter++) {
      string actor, movies;
      list.GetNextActor(actor, movies);
      dataFile << "  " << actor << endl;
    }
  }
  dataFile << endl;
}
