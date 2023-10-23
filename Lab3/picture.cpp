/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <stdexcept>

#include "picture.h"

using namespace std;
/*
  Initialize the picture object, create the array of pointers of shape.
*/
Picture::Picture() {
    this->numberOfShapes = 0;
    this->shapes = new Shape *[50];
}

/*
  destructor of the picture. first it deletes each pointer in the array, and
  then the array itself
*/
Picture::~Picture() {
    for (int i = 0; i < this->numberOfShapes; i++){
        delete shapes[i];
    }
    delete [] shapes;
}

/*
  transform the shapes in the picture to strings in a grid. it generates the grid in
  this function and then deletes the grid.
*/
string Picture::toString() {
    Grid *grid = new Grid();
    string pic;
    for (int i = 0; i < this->numberOfShapes; i++){
        shapes[i]->draw(grid);
    }
    pic = grid->toString();
    delete grid;
    return pic;
}

/*
  prints out the shapes in ht picture
*/
void Picture::print() {
    cout << this->toString() << endl;
}

/*
  add shapes in to the picture object and increment the number of shapes.
  shape: the shape object in the picture
*/
void Picture::addShape(Shape* shape) {
    shapes[this->numberOfShapes] = shape;
    this->numberOfShapes++;
}
