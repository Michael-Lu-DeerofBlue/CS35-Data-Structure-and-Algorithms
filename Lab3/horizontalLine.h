#pragma once

/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "shape.h"

/*
  declears a horizontal line object
  x is the x coordinate
  y is the y coordinate
  length is the length of the line
  apperance is the char symbol of the line
  HorizontalLine is the constructor function
  draw is the draw the shape on the grid function
*/
class  HorizontalLine: public Shape {
  private:
    int x;
    int y;
    int length;
    char appearance;
  public:
    HorizontalLine(int x, int y, int length, char appearance);
    void draw(Grid* grid);
};