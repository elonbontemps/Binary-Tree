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
    numPlayers++;
    Player *addedPlayers = new Player[numPlayers];
    Player bottomPlayer;
    if (numPlayers > 10) {
        int low = players[0].getScore();
        for (int i = 1; i < numPlayers - 1; i++) {
            if (players[i].getScore() < low) {
                bottomPlayer = players[i];
            }
        }
    }
    for (int i = 0; i < numPlayers - 1; i++) {
        if (players[i].getName() == bottomPlayer.getName()) {
            continue;
        }
        addedPlayers[i] = players[i];
    }
    Player *newPlayer = new Player(score, name);
    addedPlayers[numPlayers - 1] = *newPlayer;
    players = addedPlayers;
    return;
}


int Manager::searchPlayers(int numPlayers, Player *players, string target) {
    for (int i = 0; i < numPlayers; i++) {
        if (players[i].getName() == target) {
            return players[i].getScore();
        }
    }
    return -1;
}

void Manager::removePlayer(int &numPlayers, Player *&players, string target) {
}

