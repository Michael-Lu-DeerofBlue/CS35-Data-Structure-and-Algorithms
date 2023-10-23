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

#include "maze.h"
#include "mazeUtils.h"
#include "adts/stlList.h"

using namespace std;

/*Takes in a command line argument and the number of arguments and solves the maze.
int argc: the number of arguments in the cmdline
char** argv: an array of commandline arguments*/
int main(int argc, char** argv) {
    if (argc!=3){
      cout << "The argument line should be: [0]:application [1]:filename [2]:breadth or depth" << endl;
    }
    
    try{
      Maze* map = loadMap(argv[1]);
      delete map;
    }
    catch(runtime_error e){
      cout << "You enter an invalid maze name" << endl;
      cout << e.what() << endl;
      return 1;
    }
    Maze* map = loadMap(argv[1]);
    string argument = argv[2];
    List<Position*>* path = nullptr;
    if (argument == "depth"){
      path = map->solveDepthFirst();
      cout << renderAnswer(map, path) << endl;
    }
    else if (argument == "breadth"){
      path = map->solveBreadthFirst();
      cout << renderAnswer(map, path) << endl;
    }
    else{
      cout << "Need to enter either depth or breadth" << endl;
    }
    delete path;
    delete map;
    return 0;
}
