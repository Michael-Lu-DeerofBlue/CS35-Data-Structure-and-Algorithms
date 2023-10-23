#pragma once

/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "adts/queue.h"

/**
 * The LinkedQueue is an implementation of the Queue interface using a
 * linked list.  
 * @tparam T The type of elements stored in the queue.
 */
template <typename T> class LinkedQueue : public Queue<T> {
  public:
    LinkedQueue();
    ~LinkedQueue();
    void enqueue(T element);
    T dequeue();
    void insert(T element);
    T remove();
    int getSize();
    bool isEmpty();
    T peek();

  private:
    List<T>* linkedlist;



  private:
    // You can safely ignore the following code.  You can read more here:
    //   http://www.cplusplus.com/articles/y8hv0pDG/
    LinkedQueue(const LinkedQueue& other) = delete;
    LinkedQueue& operator=(const LinkedQueue& other) = delete;
};

#include "linkedQueue-inl.h"
