/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "image.h"

#include <iostream>
using namespace std;

// Note: see image.h for documentation on functions.

int pixelToIndex(int width, int x, int y) {
    int index;
    index = y*width*3+x*3;
    return index;
    return -9999; // dummy value so that the code compiles at first
}

void noRed(int width, int height, int* ppm) {
    int index;
    for (int j = 0; j < height; j++){
      for(int i = 0; i < width; i++){
        index = pixelToIndex(width,i,j);
        ppm[index] = 0;
      }
    }    
}


void noGreen(int width, int height, int* ppm) {
    int index;
    for (int j = 0; j < height; j++){
      for(int i = 0; i < width; i++){
        index = pixelToIndex(width,i,j)+1;
        ppm[index] = 0;
      }
    }    
}

void noBlue(int width, int height, int* ppm) {
    int index;
    for (int j = 0; j < height; j++){
      for(int i = 0; i < width; i++){
        index = pixelToIndex(width,i,j);
        ppm[index+2] = 0;
      }
    }    
}

void invert(int width, int height, int* ppm) {
    int index;
    for (int j = 0; j < height; j++){
      for(int i = 0; i < width; i++){
        index = pixelToIndex(width,i,j);
        ppm[index] = 255-ppm[index];
        ppm[index+1] = 255-ppm[index+1];
        ppm[index+2] = 255-ppm[index+2];
      }
    }    
}

void greyscale(int width, int height, int* ppm) {
    int index;
    int r;
    int g;
    int b;
    int avg;
    for (int j = 0; j < height; j++){
      for(int i = 0; i < width; i++){
        index = pixelToIndex(width,i,j);
        r = ppm[index];
        g = ppm[index+1];
        b = ppm[index+2];
        avg = (r+b+g)/3;
        ppm[index] = avg;
        ppm[index+1] = avg;
        ppm[index+2] = avg;
      }
    }    
}

/* Remember that the two flips are significantly harder than the
   other transofmations. We recommend that you work out the math
   on paper before attempting to write the code.
*/
void flipHorizontally(int width, int height, int* ppm){
  int index;
  int opp_index;
    int temp_r;
    int temp_g;
    int temp_b;
    int avg;
    for (int j = 0; j < height; j++){
      for(int i = 0; i < width/2; i++){
        opp_index = pixelToIndex(width,width-1-i,j);
        index = pixelToIndex(width,i,j);
        cout << width/2 << endl;
        temp_r = ppm[index];
        temp_g = ppm[index+1];
        temp_b = ppm[index+2];
        ppm[index] = ppm[opp_index];
        ppm[index+1] = ppm[opp_index+1];
        ppm[index+2] = ppm[opp_index+2];
        ppm[opp_index] = temp_r;
        ppm[opp_index+1] = temp_g;
        ppm[opp_index+2] = temp_b;
      }
    }
}

void flipVertically(int width, int height, int* ppm){
  int index;
  int opp_index;
    int temp_r;
    int temp_g;
    int temp_b;
    int avg;
    for (int j = 0; j < height/2; j++){
      for(int i = 0; i < width; i++){
        opp_index = pixelToIndex(width,i,height-1-j);
        index = pixelToIndex(width,i,j);
        cout << width/2 << endl;
        temp_r = ppm[index];
        temp_g = ppm[index+1];
        temp_b = ppm[index+2];
        ppm[index] = ppm[opp_index];
        ppm[index+1] = ppm[opp_index+1];
        ppm[index+2] = ppm[opp_index+2];
        ppm[opp_index] = temp_r;
        ppm[opp_index+1] = temp_g;
        ppm[opp_index+2] = temp_b;
      }
    }
}
