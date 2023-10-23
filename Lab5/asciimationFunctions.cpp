/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <unistd.h>
#include <utility>

#include "adts/list.h"
#include "asciimationFunctions.h"
#include "linkedList.h"


using namespace std;
/*loads the movie from the .asciimation file into a list*/
List<pair<int, string>>* loadMovie(string filename) {
  /*create list and initilize variables*/
  LinkedList<pair<int, string>>* movie = new LinkedList<pair<int, string>>;
  int time;
  string temptime;
  string data;
  string content;
  ifstream myFile;
  /*open the file*/
  myFile.open(filename);
  if (!myFile.is_open()){
    throw runtime_error("file " + filename + " failed to open ");
  }
  /*read file into list*/
  getline(myFile, temptime);
  while(!myFile.eof()){
    time=stoi(temptime);
    for (int i = 0; i < 13; i++){
      getline(myFile, data);
      content=content+data+"\n";
    }
    pair<int,string> frame(time, content);
    movie->insertLast(frame);
    getline(myFile, temptime);
    
    content = "";
  }
  return movie;    
}
/*prints out the strings in the list at the correct intervals to make an animation*/
void playMovie(List<pair<int, string>>* list) {
    pair<int,string> frame;
    system("clear");
    int size=list->getSize();
    /*get each value, then print out the string, then clear after the right amount of time*/
    for (int i=0;i<size;i++){
      frame=list->removeFirst();
      cout<<frame.second<<endl;
      usleep((1000000/15)*frame.first);
      system("clear");
    }
}
