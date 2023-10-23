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
  declears a point object
  x is the x coordinate
  y is the y coordinate
  apperance is the char symbol of the line
  Point is the constructor function
  draw is the draw the shape on the grid function
*/
class Point : public Shape {
  private:
    int x;
    int y;
    char appearance;
  public:
    Point(int x, int y, char appearance);
    void draw(Grid* grid);
};
