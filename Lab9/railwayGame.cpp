/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <string>

#include "railwayGame.h"
#include "player.h"
#include "adts/graph.h"
#include "graphAlgorithms.h"
#include <stdlib.h>
using namespace std;


RailwayGame::RailwayGame(Graph<string, int, int>* graph){
  this->currentPlayer = 1;
  this->graph = graph;
  vector<string> cityNames = graph->getVertices();
  vector<Goal*> p1goal = setGoals(cityNames);
  vector<Goal*> p2goal = setGoals(cityNames);
  this->P1 = new Player(0,35,p1goal);
  this->P2 = new Player(0,50,p2goal);
  this->turn1 = 0;
}


RailwayGame::~RailwayGame(){
  delete this->P1;
  delete this->P2;
}


vector<Goal*> RailwayGame::setGoals(vector<string> cityNames){
  vector<Goal*> goalsvec;
  int size = cityNames.size();
  while(goalsvec.size()<3){
    int city1Num = rand()%size;
    int city2Num = rand()%size;
    vector<string> path = shortestLengthPathBFS(cityNames[city1Num], cityNames[city2Num], this->graph);
    if (path.size()-1 >= 3){
      Dictionary<string, int>* sssp = singleSourceShortestPath(cityNames[city1Num], this->graph);
      int score = sssp->get(cityNames[city2Num]) /4;
      Goal* goal = new Goal(cityNames[city1Num],cityNames[city2Num],to_string(score));
      goalsvec.push_back(goal);
      delete sssp;
    }
  }
  return goalsvec;
}


int RailwayGame::turn(){
  if (this->currentPlayer == 1){
    this->currentPlayer = 2;
    return 2;
  }
  else{
    this->currentPlayer = 1;
    return 1;
  }
}


void RailwayGame::passUpdate(int currentPlayer){
  if (currentPlayer == 1){
    this->curr = this->P1; 
  }
  else{
    this->curr = this->P2; 
  }
  vector<string> currPlayerCities = this->curr->getCities();
  int citySize= currPlayerCities.size();
  int currTracks= this->curr->getTracks();
  this->curr->setTracks(currTracks+citySize);
}


int RailwayGame::setEdge(string V1, string V2, int currentPlayer){
  if (currentPlayer == 1){
    this->curr = this->P1; 
  }
  else{
    this->curr = this->P2; 
  }
  vector<string> currPlayerCities = this->curr->getCities();
  Edge<string,int,int> e = this->graph->getEdge(V1,V2);
  int weight = e.getWeight();
  int label = e.getLabel();
  if (label != 0){
    return 1;
  }
  bool found = false;
  if(currPlayerCities.size()>0){
    for (int i = 0; i < currPlayerCities.size(); i++){
      if (V1 == currPlayerCities[i]|| V2 == currPlayerCities[i]){
        found = true;
      }
    }
    if (found == false){
      return 1;
    }
  }
  if (this->curr->getTracks()-weight < 0){
    return 1;
  }
  this->graph->removeEdge(V1,V2);
  this->graph->insertEdge(V1,V2,currentPlayer,weight);
  if (!this->curr->containsCity(V1)){
    this->curr->addCities(V1);
    int score = this->curr->getScore();
    this->curr->setScore(score+1);
  }
  if (!this->curr->containsCity(V2)){
    this->curr->addCities(V2);
    int score = this->curr->getScore();
    this->curr->setScore(score+1);
  }
  int tracks = this->curr->getTracks();
  this->curr->setTracks(tracks-weight);
  return 0;
}


void RailwayGame::calculateScore(){
  vector<Goal*> goalsvec = this->curr->getGoals();
  for(int i = 0; i < goalsvec.size(); i++){
    if (this->curr->containsCity(goalsvec[i]->getLocation(1)) && this->curr->containsCity(goalsvec[i]->getLocation(2))){
      int score = this->curr->getScore();
      string message = goalsvec[i]->getMessage();
      if (message != "COMPLETE"){
        this->curr->setScore(score+stoi(message));
        goalsvec[i]->setMessage("COMPLETE");
      }
    }
  }
}

Player* RailwayGame::getPlayer1(){
  return this->P1;
}

Player* RailwayGame::getPlayer2(){
  return this->P2;
}

int RailwayGame::getCurrentPlayer(){
  return this->currentPlayer;
}