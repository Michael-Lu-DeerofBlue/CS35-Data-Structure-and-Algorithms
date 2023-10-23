/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <string>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"

using namespace std;

int main(int argc, char** argv) {

    /*if the user only calls the file name*/
    if (argc==2){
      string filename;
      filename=argv[1];
      List<pair<int, string>>* movie = loadMovie(filename);
      playMovie(movie);
      delete movie;
    }
    /*if the user calls the file name and reverse*/
    else if (argc==3){
      string argument = argv[1];
      /*makes sure the user inputed reverse correctly. if yes, invert the list, then play it*/
      if (argument=="--reverse"){
        string filename;
        pair<int,string> frame;
        filename=argv[2];
        List<pair<int, string>>* movie = loadMovie(filename);
        List<pair<int, string>>* movieReverse = new LinkedList<pair<int, string>>;
        int size=movie->getSize();
        for (int i=0;i<size;i++){
          frame=movie->removeFirst();
          movieReverse->insertFirst(frame);
        }
        delete movie;
        playMovie(movieReverse);
        delete movieReverse;

      }
      /*makes sure command line inputs were correct*/
      else{
        throw runtime_error("Wrong command line argument (first argument should be reverse or the name of the file): asciimation::main");
      }
      

    }
    else{
      throw runtime_error("Wrong number of command line argumnents: asciimation::main");
    }
    return 0;
}
