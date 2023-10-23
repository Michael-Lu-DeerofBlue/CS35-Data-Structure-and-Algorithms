#pragma once

/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "grid.h"

/**
 * A class representing a shape.
 */
class Shape {
  public:
    virtual ~Shape() {
    }

    /**
     * Draws this shape on the provided grid.
     * @param grid The grid onto which to draw the shape.
     */
    virtual void draw(Grid* grid) = 0;
};
