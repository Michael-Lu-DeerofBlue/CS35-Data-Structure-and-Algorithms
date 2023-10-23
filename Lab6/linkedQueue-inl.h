/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "linkedQueue.h"
#include "adts/stlList.h"
using namespace std;

// NOTE: Most of the method bodies in this class will only require a
// single line of code!

/*construct a new queue using the linkedlist ADT*/
template <typename T> LinkedQueue<T>::LinkedQueue() {
  this->linkedlist = new STLList<T>(); 
}

/*destruct the queue*/
template <typename T> LinkedQueue<T>::~LinkedQueue() {
  delete this->linkedlist;
}

/*returns the number of elements inside the queue*/
template <typename T> int LinkedQueue<T>::getSize() {
  return this->linkedlist->getSize();
}

/*returns true when the queue is empty, false if the queue is not empty*/
template <typename T> bool LinkedQueue<T>::isEmpty() {
  return this->linkedlist->isEmpty();
}

/*returns the first element of the queue*/
template <typename T> T LinkedQueue<T>::peek() {
  return this->linkedlist->getFirst();
}

/*enqueue an element to the end of the queue*/
template <typename T> void LinkedQueue<T>::enqueue(T element) {
  this->linkedlist->insertLast(element);
}

/*dequeue the first element from the queue and returns the value of the element*/
template <typename T> T LinkedQueue<T>::dequeue() {
  T value = this->linkedlist->getFirst();
  this->linkedlist->removeFirst();
  return value;
}

/*inserts an element to the end of the queue*/
template <typename T> void LinkedQueue<T>::insert(T element) {
  this->enqueue(element);
}

/*remove the first element from the queue and returns the value of the element*/
template <typename T> T LinkedQueue<T>::remove() {
  T value = this->dequeue();
  return value;
}
