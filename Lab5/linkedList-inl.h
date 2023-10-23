/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

using std::runtime_error;

// This file defines the methods for two classes: LinkedListNode and LinkedList.
// The LinkedListNode methods have been defined for you.  You are responsible
// for defining the LinkedList methods.

// //////// LinkedListNode /////////////////////////////////////////////////////

template <typename T>
LinkedListNode<T>::LinkedListNode(T val, LinkedListNode<T>* next) {
    this->value = val;
    this->next = next;
}

// //////// LinkedList /////////////////////////////////////////////////////////
/*
 constructs a linkedlist
 */
template <typename T> LinkedList<T>::LinkedList() {
    this -> size = 0;
    this -> head = nullptr;
    this -> tail = nullptr;
}

/*
 destructs a linkedlist
 */
template <typename T> LinkedList<T>::~LinkedList() {
    if (this->size > 0){
        while (this->size != 0){
            T e = removeFirst();
        }
    }
}

/*
 check if the number of nodes equals to the size of the list
 */
template <typename T> void LinkedList<T>::checkInvariants() {
    LinkedListNode<T>* p = this->head;
    int i = 0;
    if (this->size > 0){
        while (p->next != nullptr){
            i++;
            p = p->next;
        }
        i++;
    }
    if (this->size != i){
        throw runtime_error("Sizes don't match: LinkedList::checkInvariants");
    }
}

/*
 return the size of the linkedlist
 */
template <typename T> int LinkedList<T>::getSize() {
    return this->size;
}

/*
 returns true if the linkedlist is empty, false if not
 */
template <typename T> bool LinkedList<T>::isEmpty() {
    if (this->size == 0){
        return true;
    }
    else{
        return false;
    }
}

/*
 returns the first item of the linkedlist
 */
template <typename T> T LinkedList<T>::getFirst() {
    if (this->head == nullptr){
        throw runtime_error("Null pointer for head: LinkedList::getFirst");
    }
    return this->head->value;
}

/*
 returns the last item of the linkedlist
 */
template <typename T> T LinkedList<T>::getLast() {
    if (this->tail == nullptr){
        throw runtime_error("Null pointer for tail: LinkedList::getLast");
    }
    return this->tail->value;
}

/*
 returns the item of the linkedlist at the requested index
 index: the index of the requested item
 */
template <typename T> T LinkedList<T>::get(int index) {
    LinkedListNode<T>* p = this->head;
    if (index < 0){
        throw runtime_error("Cannot get a negative indexs: LinkedList::get");
    }
    if (this->size > 0){
        if (index >= this->size){
            throw runtime_error("The size of the list is less than the index: LinkedList::get");
        }
        else{
            for (int j =0; j < index; j++){
                p = p->next;
             }
            return p->value;
        } 
    }
    else{
        throw runtime_error("The size of the list is 0: LinkedList::get");
    }
    
}

/*
 insert an item of type T to the front of the linkedlist
 */
template <typename T> void LinkedList<T>::insertFirst(T value) {
    LinkedListNode<T>* node = new LinkedListNode<T>(value, this->head);
    this->head = node;
    if (this->size == 0){
        this -> tail = node;
    }
    this->size++;
}

/*
 insert an item of type T to the end of the linkedlist
 */
template <typename T> void LinkedList<T>::insertLast(T value) {
    LinkedListNode<T>* node = new LinkedListNode<T>(value, nullptr);
    if (this->size != 0){
        this->tail->next = node;
    }
    this->tail = node;
    if (this->size == 0){
        this -> head = node;
    }
    this->size++;
}

/*
 remove an item of type T at the front of the linkedlist
 return: the item at the front
 */
template <typename T> T LinkedList<T>::removeFirst() {
    if (this->size == 0){
        throw runtime_error("The size is 0: LinkedList::removeFirst");
    }
    T value = this->head->value;
    if (this->size == 1){
        delete this->head;
        this -> head = nullptr;
        this -> tail = nullptr;
    }
    else{
        LinkedListNode<T>* temp = this -> head;
        this -> head = this -> head -> next;
        delete temp;
    }
    this->size--;
    return value;
}

/*
 remove an item of type T at the end of the linkedlist
 return: the item at the end
 */
template <typename T> T LinkedList<T>::removeLast() {
    if (this->size == 0){
        throw runtime_error("The size is 0: LinkedList::removeLast");
    }
    T value = this->tail->value;
    if (this->size == 1){
        delete this->tail;
        this -> head = nullptr;
        this -> tail = nullptr;
    }
    else{
        LinkedListNode<T>* p = this -> head;
        while(p->next != this->tail){
            p = p->next;
        }
        p->next = nullptr;
        delete this -> tail;
        this->tail = p;
    }
    this->size--;
    return value;
}
