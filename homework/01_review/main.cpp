/*************************************************************************
 *
 * Assignment 1: drier for the high score manager
 *
 * File Name: main.cpp
 * Course:    CPTR 242
 * Date:      April 2, 2019
 */

#include <string.h>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#include "manager.h"

using namespace std;
void printPlayers(ofstream &outFile, int numPlayers, Player *players);

int main() {
    ifstream inFile;
    ofstream outFile;
    string inFileName;
    string outFileName;
    string outPutLabel;
    string option;
    string name;
    int score;
    string target;

    Player *players = nullptr;
    int numPlayers = 0;
    Manager manager;
    int index;
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

    numOptions = 0;
    while (option != "Quit") {
        cout << option;
        if (option == "Menu") {
            cout << "Select option:" << endl;
            cout << " - Menu." << setw(25) << "Display menu." << endl;
            cout << " - PrintList." << setw(25) << "Print all players and scores." << endl;
            cout << " - FindPlayer."  << setw(25) << "Search for a player's score." << endl;
            cout << " - AddPlayer." << setw(25) << "Add new player and score." << endl;
            cout << " - RemovePlayer."  << setw(25) << "Remove a player." << endl;
            cout << " - Quit." << setw(25) << "Quit application." << endl;
        } else if (option == "AddPlayer") {
            inFile >> name;
            inFile >> score;
            manager.addPlayer(numPlayers, players, name, score);
            outFile << "Player " << name << " has been added with a score of " << score << '.' << endl;
        } else if (option == "PrintList") {
            printPlayers(outFile, numPlayers, players);
        } else if (option == "FindPlayer") {
            inFile >> target;
            index = manager.searchPlayers(numPlayers, players, target);
            if (index >= 0) {
                outFile << "The score for " << target << " is " << index << endl;
            } else {
                outFile << "Player " << target << " not found." << endl;
            }
        } else if (option == "RemovePlayer") {
            inFile >> target;
            manager.removePlayer(numPlayers, players, target);
            outFile << "Player " << target << " removed." << endl;
        } else if (option == "Quit") {
            outFile << "Quit" << endl << "Testing completed." << endl;
        } else {
            cout << option << " is not a valid command." << endl;
        }
        numOptions++;
        cout << " Command number " << numOptions << " completed." << endl;
        inFile >> option;
    };

    inFile.close();
    outFile.close();
    return 0;
}

void printPlayers(ofstream &dataFile, int numPlayers, Player *players) {
    dataFile << "Player Scores" << endl;
    for (int i = 0; i < numPlayers; i++)
        dataFile << setw(2) << right << (i + 1) << ". " << left << setw(12) << players[i].getName() << setw(5) << right
                 << players[i].getScore() << endl;
}