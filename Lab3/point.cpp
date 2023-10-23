/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "point.h"

/*
  defines a point object
  x is the x coordinate
  y is the y coordinate
  apperance is the char symbol of the line
*/
Point::Point(int x, int y, char appearance) {
  this->x = x;
  this->y = y;
  this->appearance = appearance;
}

/*
  draws out the shape on the grid
  grid: the grid object
*/
void Point::draw(Grid* grid){
  grid->placeSymbol(this->x, this->y, this->appearance);
}