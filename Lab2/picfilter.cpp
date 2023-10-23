/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>

#include "image.h"
#include "ppmio.h"

using namespace std;

int main(int argc, char** argv) {
    // TODO: write your main program here
    // Remember:
    //   * The first command-line argument in argv is always the name of the
    //     program.
    //   * You can convert from char* to string just by assignment:
    //         string infile = argv[1];
    //   * You should have code that deals with the case that your
    //     user gave you too few or too many command-line arguments.
    // Good luck!  Remember to ask for help!
    
  if (argc != 4){
    cout << "Error!Incorrect number of arguments" << endl;
    cout << "usage:./picfilter <import filename> <function> <export filename>" << endl;
    return 1;
  }

  int *image; // the pointer to the image
  int width; // the width of the image
  int height; // the height of the image
  string cmd; // the function that the user want

  image = read_ppm(argv[1]);
  width = ppm_width(argv[1]);
  height = ppm_height(argv[1]);
  cmd = argv[2];
  

  if (cmd == "noRed"){
    noRed(width,height,image);
  }
  else if (cmd == "noGreen"){
    noGreen(width,height,image);
  }
  else if (cmd == "noBlue"){
    noBlue(width,height,image);
  }
  else if (cmd == "invert"){
    invert(width,height,image);
  }
  else if (cmd == "grayscale"){
    greyscale(width,height,image);
  }
  else if (cmd == "flipHorizontally"){
    flipHorizontally(width,height,image);
  }
  else if (cmd == "flipVertically"){
    flipVertically(width,height,image);
  }
  else{
    cout << "Invalid function name" << endl;
  }

  write_ppm(argv[3], width, height, image);

  return 0;
}
