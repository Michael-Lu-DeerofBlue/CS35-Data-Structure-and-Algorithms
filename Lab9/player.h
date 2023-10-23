/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  M. Lu, C. Dawes
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/


#pragma once
#include "goal.h"
#include "adts/stlHashTable.h"
#include <vector>

using namespace std;

class Player {
  public:
    /*
    makes a player object
    int score - score for player
    int tracks - tracks for player
    vector<Goal*> goals - premade goals for player
    */
    Player(int score, int tracks, std::vector<Goal*> goals);
    ~Player();
    /*Sets score for player
    int score - player score
    */
    void setScore(int score);
    /*get score from player
    returns player tracks*/
    int getScore();
    /*set tracks for player
    int tracks - player tracks
    */
    void setTracks(int tracks);
    /*get tracks from player
    returns player tracks*/
    int getTracks();
    /*get Goals vector from player
    returns player goals*/
    vector<Goal*> getGoals();
    /*add cities to player city dictionary
    string city - string to be added to vector*/
    void addCities(string city);
    /*returns all keys in the cities dictionary
    retuns player cities*/
    vector<string> getCities();
    /*checks if player cities dictionary contains a city
    string city - city to check if in dictionary
    returns true if city is in dictionary, false otherwise*/
    bool containsCity(string city);
  private:
    int score;
    int tracks;
    vector<Goal*> goals;
    STLHashTable<string,bool> myCities;
};