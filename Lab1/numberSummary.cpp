/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
  This program is for doing a number summary task.
*/
#include <iostream>
using namespace std;

#include <fstream>

/*
  This function finds and returns the largest number in this array.
  array points to the base address of the array
  size is the size of the array
*/
int find_largest(int *array, int size){
  int largest = 0;
  for (int i =0; i<size; i++){
    if (array[i] > largest){
      largest = array[i];
    }
  }
  return largest;
}

/*
  This function finds the number of integers that are lower than 10
  array points to the base address of the array
  size is the size of the array
*/
int under_ten(int *array, int size){
  int count = 0;
  for (int i =0; i<size; i++){
    if (array[i] < 10){
      count = count + 1;
    }
  }
  return count;
}

/*
  This function calculates the average of the integers of the array
  array points to the base address of the array
  size is the size of the array
*/
float average(int *array, int size){
  float avg;
  float total;
  for (int i =0; i<size; i++){
    total = total + array[i];
  }
  float s = size;
  avg = total / s;
  return avg;
}

/*
  This the main fuction that reads the file and prints out the results.
*/
int main() {
  ifstream my_file;
  string file_name;
  cout << "Please enter the name of your file:";
  cin >> file_name;
  my_file.open(file_name);

  int size = 0;
  int larg = 0;
  int count = 0;
  float avg = 0;
  my_file >> size;

  int *number_array = new int[size];
  for (int i =0; i<size; i++){
    my_file >> number_array[i];
  }
  cout << "The last number is " << number_array[size-1] << endl;
  larg = find_largest(number_array,size);
  cout << "The largest number is " << larg << endl;
  count = under_ten(number_array,size);
  avg = average(number_array,size);
  cout << "There are " << count << " numbers less than 10 in the sequence." << endl;
  cout << "The average is "<< avg << endl;
  delete[] number_array;
  return 0;
}

