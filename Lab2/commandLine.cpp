/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
using namespace std;

/*
  Use this program to practice handling command-line arguments.
    argc   the number of arguments on the command line
    argv   an array of strings containing the arguments in order
  Note that the executable program name is always the first argument.
 */

int main(int argc, char** argv) {
  /* 
     Update this program so that it expects the command line to 
     contain a major (as a single word) and a graduation year.
     
     If the command-line does not contain the correct number of 
     arguments, print an error message and return 1 to indicate
     a problem.

     Otherwise, print a message formatted as follows:
       You'll get a degree in <major> in <number> years.

  */

  if (argc != 3){
    cout << "Error!Incorrect number of arguments" << endl;
    cout << "usage:./picfilter <filename> <function>" << endl;
    return 1;
  }
  cout << "There are " << argc << " command-line arguments" << endl;
  for (int i=0; i<argc; i++) {
    cout << "argv " << i << " is " << argv[i] << endl;
  }
  return 0;
}
