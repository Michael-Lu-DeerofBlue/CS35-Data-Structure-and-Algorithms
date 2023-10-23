/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "verticalLine.h"

/*
  defines a vertical line object
  x is the x coordinate
  y is the y coordinate
  length is the length of the line
  apperance is the char symbol of the line
*/
VerticalLine::VerticalLine(int x, int y, int length, char appearance) {
  this->x = x;
  this->y = y;
  this->length = length;
  this->appearance = appearance;
}

/*
  draws out the shape on the grid
  grid: the grid object
*/
void VerticalLine::draw(Grid* grid){
  for (int i = 0; i < length; i++){
    grid->placeSymbol(this->x, this->y+i, this->appearance);
  }
}