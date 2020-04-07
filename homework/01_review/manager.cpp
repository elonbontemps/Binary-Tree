/*************************************************************************
 *
 * Assignment 1: high score manager
 *
 * File Name: manager.cpp
 * Name:      Elon Bontemps
 * Course:    CPTR 242
 * Date:      4-4-20
 *
 */
#include "manager.h"
#include <iostream>
#include <string>
using namespace std;

void Manager::addPlayer(int &numPlayers, Player *&players, string name, int score) {
    Player *playerTemp = new Player(score, name);
    Player *nextList = new Player[numPlayers + 1];
    for (int i = 0; i < numPlayers; ++i) {
        nextList[i] = players[i];
    }
    if (numPlayers > 9) {
        int min = 0;
        for (int i = 0; i < numPlayers; ++i) {
            if (players[i].getScore() < players[min].getScore()) {
                min = i;
            }
        }
        nextList[min] = *playerTemp;
        players = nextList;
    } else {
        nextList[numPlayers] = *playerTemp;
        numPlayers++;
    }
    Player *formattedList = new Player[numPlayers];
    int currMax = 12;
    int index = 0;

    for (int i = 12; i >= 0; --i) {
        for (int i = 0; i < numPlayers; ++i) {
            if (nextList[i].getScore() == currMax) {
                formattedList[index] = nextList[i];
                index++;
            }
        }
        currMax--;
    }
    players = formattedList;
}

int Manager::searchPlayers(int numPlayers, Player *players, string target) {
    for (int i = 0; i < numPlayers; ++i) {
        if (players[i].getName() == target) {
            return players[i].getScore();
        }
    }
    return -1;
}

void Manager::removePlayer(int &numPlayers, Player *&players, string target) {
    Player *newList = new Player[numPlayers - 1];
    newList = players;
    int j = 0;
    for (int i = 0; i < numPlayers; ++i) {
        if (players[i].getName() == target) {
            continue;
        } else {
            newList[j] = players[i];
            ++j;
        }
    }
    players = newList;
    numPlayers -= 1;
}

