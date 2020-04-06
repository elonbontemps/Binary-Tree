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
    Player *newPlayers = nullptr;
    newPlayers = new Player[numPlayers];
    Player lowestPlayer;
    if(numPlayers > 10){
        int lowest = players[0].getScore();
        for(int i = 1; i < numPlayers; i++){
            if(players[i].getScore() < lowest){
                lowestPlayer = players[i];
            }
        }
    }
    for(int i = 0; i < numPlayers; i++) {
        if(players[i].getName() == lowestPlayer.getName()){
            continue;
        }
        newPlayers[i] = players[i];
    }
    Player *newPlayer = new Player(score, name);
    newPlayers[numPlayers] = *newPlayer;
    players = newPlayers;
    return;
}

int Manager::searchPlayers(int numPlayers, Player *players, string target) {

