/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <UnitTest++/UnitTest++.h>
#include <iostream>

#include "quickSort.h"

using namespace std;

TEST(threeElements) {
  // Create a static array containing the numbers 4, 8, 6.
  int array[3] = {4, 8, 6};
  quickSort(array, 0, 2);
  CHECK_EQUAL(4, array[0]);
  CHECK_EQUAL(6, array[1]);
  CHECK_EQUAL(8, array[2]);
}

TEST(reverseSorted) {
  int size = 20;
  // Create a dynamically-allocated array
  int *array = new int[size];
  for (int i = 0; i < size; i++) {
    array[i] = size - 1 - i;
  }
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size-1; i++) {
    CHECK(array[i] < array[i+1]);
  }
  // de-allocate array
  delete[] array;
  array = nullptr;
}

/*
  This is an array with only one element
*/
TEST(singleTest) {
  int array[1];
  array[0] = 0;
  quickSort(array, 0, 0);
  CHECK_EQUAL(0, array[0]);
}

/*
  This is an array that is already sorted
*/
TEST(alreadySorted) {
  int size = 20;
  // Create a dynamically-allocated array
  int *array = new int[size];
  for (int i = 0; i < size; i++) {
    array[i] = i+1;
  }
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size-1; i++) {
    CHECK(array[i] < array[i+1]);
  }
  // de-allocate array
  delete[] array;
  array = nullptr;
}

/*
  This is an array that has duplicated elements
*/
TEST(hasDuplicate) {
  int array[4] = {4, 4, 8, 6};
  quickSort(array, 0, 3);
  CHECK_EQUAL(4, array[0]);
  CHECK_EQUAL(4, array[1]);
  CHECK_EQUAL(6, array[2]);
  CHECK_EQUAL(8, array[3]);
}

/*
  This is an array that approach a midpoint from opposite 
  directions
*/
TEST(approachMiddle) {
  int size = 30;
  // Create a dynamically-allocated array
  int *array = new int[size];
  for (int i = 0; i < size; i = i + 2) {
    array[i] = i+1;
    array[i+1] = size - i;
  }
  quickSort(array, 0, size - 1);
  for (int i = 0; i < size-1; i++) {
    CHECK(array[i] < array[i+1]);
  }
  // de-allocate array
  delete[] array;
  array = nullptr;
}

/* no need to modify main */
int main() {
  return UnitTest::RunAllTests();
}
