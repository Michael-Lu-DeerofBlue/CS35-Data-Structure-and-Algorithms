/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "helpers.h"

/*
Converts a list to vector
*/
template <typename T> vector<T> dynamicListToStaticVector(List<T>* list) {
    vector<T> vec;
    while (list->isEmpty() == false){
      vec.push_back(list->removeFirst());
    }
    return vec;
}
