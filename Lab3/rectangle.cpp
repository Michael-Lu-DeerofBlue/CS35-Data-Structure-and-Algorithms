/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "rectangle.h"

/*
  declears a horizontal line object
  x is the x coordinate
  y is the y coordinate
  length is the length of the rectangle
  width is the width of the rectangle
  apperance is the char symbol of the line
*/
Rectangle::Rectangle(int x, int y, int width, int length, char appearance) {
  this->x = x;
  this->y = y;
  this->width = width;
  this->length = length;
  this->appearance = appearance;
}

/*
  draws out the shape on the grid
  grid: the grid object
*/
void Rectangle::draw(Grid* grid){
  for (int i = 0; i < length; i++){
    for (int j = 0; j < width; j++){
      grid->placeSymbol(this->x+j, this->y+i, this->appearance);
    }    
  }
}