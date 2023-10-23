/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "quickSort.h"

/**
 * @brief swap two items in an array
 * 
 * @param array a pointer to an array
 * @param obj the index of one of the item (object)
 * @param targ the index of one of the item (target)
 */
void swap(int* array,int obj,int targ){
  int temp = array[obj];
  array[obj] = array[targ];
  array[targ] = temp;
}

/**
 * @brief the function that splits the array into two parts
 * 
 * @param array a pointer to an array
 * @param startIndex the start index for this part of the array
 * @param endIndex the end index for this part of the array
 * @return int the index which supposes to be the pivot position
 */
int partition(int* array,int startIndex,int endIndex){
  int pivotVal = array[endIndex];
  int left = startIndex;
  int right = endIndex - 1;
  while (left <= right){
    if (array[left] <= pivotVal){
      left++;
    }
    else if (array[right] >= pivotVal){
      right--;
    }
    else{
      swap(array,left,right);
    }
  }
  swap(array,left,endIndex);
  return left;
}

/**
 * @brief the quick sort function
 * 
 * @param array the pointer to the array
 * @param startIndex the start index for the quick sort
 * @param endIndex the end index for the quick sort
 */
void quickSort(int *array, int startIndex, int endIndex) {
  int pivotPosition;
  if (startIndex < endIndex){
    pivotPosition = partition(array,startIndex,endIndex);
    quickSort(array,startIndex,pivotPosition-1);
    quickSort(array,pivotPosition+1,endIndex);
  }
}

void qSort(int *array, int size) {
  quickSort(array, 0, size - 1);
}
