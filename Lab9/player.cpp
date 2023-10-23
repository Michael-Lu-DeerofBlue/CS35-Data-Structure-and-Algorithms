/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  M. Lu, C. Dawes
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "goal.h"
#include "player.h"

using namespace std;

Player::Player(int score, int tracks, vector<Goal*> goals) {
    this->score = score;
    this->tracks = tracks;
    this->goals = goals;
}

Player::~Player() {
  for (int i = 0; i < this->goals.size(); i++){
    delete this->goals[i];
  }
}

void Player::setScore(int score){
  this->score = score;
}
int Player::getScore(){
  return this->score;
}
void Player::setTracks(int tracks){
  this->tracks = tracks;
}
int Player::getTracks(){
  return this->tracks;
}
vector<Goal*> Player::getGoals(){
  return this->goals;
}
void Player::addCities(string city){
  this->myCities.insert(city,true);
}
vector<string> Player::getCities(){
  return this->myCities.getKeys();
}
bool Player::containsCity(string city){
  return this->myCities.contains(city);
}
