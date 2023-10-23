/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

/* ADTs */
#include "adts/list.h"
#include "adts/orderedCollection.h"
#include "adts/queue.h"
#include "adts/stack.h"

/* Implementations of above ADTs */
#include "adts/stlList.h"
#include "linkedQueue.h"
#include "linkedStack.h"

#include "maze.h"

using namespace std;
/*constructor for Maze, uses imbeded loops to intilize each part of positions*/
Maze::Maze(int width, int height) {
  this->positions = new Position**[width];
  this->width = width;
  this->height = height;
  for (int i =0; i<this->width; i++){
    this->positions[i] = new Position*[height];
    for(int j=0; j<this->height; j++){
      this->positions[i][j] = new Position(i,j);
    }
  }
}
/*maze deconstructor*/
Maze::~Maze() {
  
  for (int i =0; i<this->width; i++){
    for(int j=0; j<this->height; j++){
      delete this->positions[i][j];
    }
    delete [] this->positions[i];
  }
  delete [] this->positions;
  
}
/*simple getters for width, hight, and isWall of a given position in positions*/
int Maze::getWidth() {
  return this->width;
}

int Maze::getHeight() {
  return this->height;
}

bool Maze::isWall(int x, int y) {
  return this->positions[x][y]->isWall();
}
/*Simple setter for isWall of a given position in positions*/
void Maze::setWall(int x, int y) {
  this->positions[x][y]->setWall();
}
/*private method for solve. our implimention does not count walls as neighbors*/
List<Position*>* Maze::getNeighbors(Position* position) {
  List<Position*>* neighbors = new STLList<Position*>();
  int x = position->getX();
  int y = position->getY();
  if (y-1>=0){
    if (this->positions[x][y-1]->isWall() == false){
      neighbors->insertFirst(this->positions[x][y-1]);
    }    
  }
  if (x+1<width){
    if (this->positions[x+1][y]->isWall() == false){
      neighbors->insertFirst(this->positions[x+1][y]);
    }    
  }
  if (y+1<height){
    if (this->positions[x][y+1]->isWall() == false){
      neighbors->insertFirst(this->positions[x][y+1]);
    }    
  }
  if (x-1>=0){
    if (this->positions[x-1][y]->isWall() == false){
      neighbors->insertFirst(this->positions[x-1][y]);
    }    
  }
  return neighbors;
}
/*solves using a Queue*/
List<Position*>* Maze::solveBreadthFirst() {
  OrderedCollection<Position*>* exploration = new LinkedQueue<Position*>();
  List<Position*>* path = solve(exploration);
  delete exploration;
  return path;
}
/*solves using a stack*/
List<Position*>* Maze::solveDepthFirst() {
  OrderedCollection<Position*>* exploration = new LinkedStack<Position*>();
  List<Position*>* path = solve(exploration);
  delete exploration;
  return path;
}
/*private method to be used in solveDepthFirst and solveBreadthFirst*/
List<Position*>* Maze::solve(OrderedCollection<Position*>* exploration) {
  exploration->insert(this->positions[0][0]);
  while (exploration->isEmpty()==false){
    Position* current = exploration->remove();
    if (current->isVisited()){
      continue;
    }
    current->setVisited();
    if (current->getX() == this->width-1 && current->getY() == this->height-1){
      break;
    }
    List<Position*>* neighbors = nullptr;
    neighbors = this->getNeighbors(current);
    for (int i = 0; i < neighbors->getSize(); i++){
      if (neighbors->get(i)->isVisited() == false){
        if (neighbors->get(i)->getPrevious() == nullptr){
          neighbors->get(i)->setPrevious(current);
        }
        exploration->insert(neighbors->get(i));
      }
    }
    delete neighbors;
  }
  if (this->positions[width-1][height-1]->isVisited()){
    List<Position*>* path = new STLList<Position*>();
    path->insertFirst(this->positions[width-1][height-1]);
    while(path->getFirst()->getPrevious() != nullptr){
      path->insertFirst(path->getFirst()->getPrevious());
    }
    return path;
  }
  else{
    return nullptr;
  }
}
