#pragma once

/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

/*
 * A file for helper functions in the BST lab.  These functions are separate
 * from the BST classes because they're not specific to the binary search tree
 * algorithms; that is, even if this lab weren't about BSTs, these functions
 * might be useful.  Feel free to add your own helper functions here.
 */

#include <vector>

#include "adts/list.h"

/**
 * Converts a CS35 List into a C++ STL vector.
 * @param list The list to convert.
 * @return The resulting vector.
 */
template <typename T> vector<T> dynamicListToStaticVector(List<T>* list);

#include "helpers-inl.h"
