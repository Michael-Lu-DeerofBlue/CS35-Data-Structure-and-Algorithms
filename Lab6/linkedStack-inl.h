/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "linkedStack.h"
#include "adts/stlList.h"
using namespace std;

// NOTE: Most of the method bodies in this class will only require a
// single line of code!

/*construct a new stack using the linkedlist ADT*/
template <typename T> LinkedStack<T>::LinkedStack() {
  this->linkedlist = new STLList<T>(); 
}

/*destruct the stack*/
template <typename T> LinkedStack<T>::~LinkedStack() {
  delete this->linkedlist; 
}


/*push an element to the end of the stack*/
template <typename T> void LinkedStack<T>::push(T element) {
  this->linkedlist->insertFirst(element);
}

/*pop the first element from the stack and returns the value of the element*/
template <typename T> T LinkedStack<T>::pop() {
  T value = this->linkedlist->getFirst();
  this->linkedlist->removeFirst();
  return value;
}

/*inserts an element to the end of the stack*/
template <typename T> void LinkedStack<T>::insert(T element) {
  // To "insert" into a stack is to push onto it.  So when we are told to
  // insert, we will push.
  this->push(element);
}

/*remove the first element from the stack and returns the value of the element*/
template <typename T> T LinkedStack<T>::remove() {
  T value = this->pop();
  return value;
}

/*returns the number of elements inside the stack*/
template <typename T> int LinkedStack<T>::getSize() {
  return this->linkedlist->getSize();
}

/*returns true when the stack is empty, false if the stack is not empty*/
template <typename T> bool LinkedStack<T>::isEmpty() {
  return this->linkedlist->isEmpty();
}

/*returns the first element of the stack*/
template <typename T> T LinkedStack<T>::peek() {
  return this->linkedlist->getFirst();
}
