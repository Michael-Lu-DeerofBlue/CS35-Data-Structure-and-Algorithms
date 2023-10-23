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

int main() {
    // TODO: write any tests you want here; this is your sandbox
    string filename;
    filename="test_data/scene3.asciimation";
    List<pair<int, string>>* movie = loadMovie(filename);
    playMovie(movie);
    delete movie;
    return 0;
}
