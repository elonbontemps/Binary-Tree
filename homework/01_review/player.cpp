/*************************************************************************
 *
 * Assignment 1: high score manager
 *
 * File Name: player.cpp
 * Course:    CPTR 242
 * Date:      April 2, 2019
 */
#include "player.h"
#include <iostream>
#include <string>
using namespace std;

Player::Player() : name(""), score(0) {
}

Player::Player(int newScore, string newName) : name(newName), score(newScore) {
}

void Player::setName(string newName) {
    name = newName;
}
void Player::setScore(int newScore) {
    score = newScore;
}
string Player::getName() {
    return name;
}
int Player::getScore() {
    return score;
}
