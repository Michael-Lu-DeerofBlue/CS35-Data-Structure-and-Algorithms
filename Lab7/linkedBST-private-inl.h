/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <utility>

#include "adts/list.h"
#include "adts/stlList.h"
#include <iostream>

using std::runtime_error;
using namespace std;

/*
This finds a key inside a bst and returns its value
current: the current node
key: the key
returns: the value store in the key
*/
template <typename K, typename V>
V LinkedBST<K, V>::findInSubtree(LinkedBSTNode<K, V>* current, K key) {
    if (current == nullptr){
        throw runtime_error("key not in tree: LinkedBST<K,V>::get");
    }
    if (key == current->getKey()){
        return current->getValue();
    }
    if (key < current->getKey()){
        return findInSubtree(current->getLeft(), key);
    }
    else{
        return findInSubtree(current->getRight(), key);
    }
}

/*
Find if a key is in the bst
current: the current node
key: the key
returns: true if found, false if didn't find
*/
template <typename K, typename V>
bool LinkedBST<K, V>::containsInSubtree(LinkedBSTNode<K, V>* current, K key) {
    if (current == nullptr){
        return false;
    }
    if (key == current->getKey()){
        return true;
    }
    else if (key < current->getKey()){
        return containsInSubtree(current->getLeft(), key);
    }
    else{
        return containsInSubtree(current->getRight(), key);
    }
}

/*
Updates a value in the bst
current: the current node
key: the key
value: the value that needs to be updated to
*/
template <typename K, typename V>
void LinkedBST<K, V>::updateInSubtree(LinkedBSTNode<K, V>* current, K key,
                                      V value) {
    if (current == nullptr){
        throw runtime_error("key not in tree: LinkedBST<K,V>::update");
    }
    if (key == current->getKey()){
        current->setValue(value);
    }
    else if (key < current->getKey()){
        updateInSubtree(current->getLeft(), key, value);
    }
    else{
        updateInSubtree(current->getRight(), key, value);
    }
}

/*
Find the height of the tree
current: the current node
key: the key
returns: the height of the tree
*/
template <typename K, typename V>
int LinkedBST<K, V>::getHeightInSubtree(LinkedBSTNode<K, V>* current) {
    int left_h = 0;
    int right_h = 0;
    if (current->getLeft() == nullptr){
        left_h = -1;
    }
    else{
        left_h = getHeightInSubtree(current->getLeft());
    }
    if (current->getRight() == nullptr){
        right_h = -1;
    }
    else{
        right_h = getHeightInSubtree(current->getRight());
    }
    int height = max(left_h,right_h)+1;
    return height;
}

/*
Find the minimum key inside the tree
current: the current node
results: the stllist that holds the traversal
returns: a pair of the min key in bst and its results
*/
template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMinInSubtree(LinkedBSTNode<K, V>* current) {
    List<pair<K,V>>* results = new STLList<pair<K,V>>();
  buildInOrderTraversal(current,results);
  pair<K,V> min = results->getFirst();
  delete results;
  return min;
}

/*
Find the maximum key inside the tree
current: the current node
results: the stllist that holds the traversal
returns: a pair of the max key in bst and its results
*/
template <typename K, typename V>
pair<K, V> LinkedBST<K, V>::getMaxInSubtree(LinkedBSTNode<K, V>* current) {
    List<pair<K,V>>* results = new STLList<pair<K,V>>();
  buildInOrderTraversal(current,results);
  pair<K,V> max = results->getLast();
  delete results;
  return max;
}

/*
Insert a node in the subtree
current: the current node
key: the key of the new node
value: the value of the new node
returns: the inserted node
*/
template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::insertInSubtree(LinkedBSTNode<K, V>* current, K key, V value) {
    if (current == nullptr){
        LinkedBSTNode<K, V>* node = new LinkedBSTNode<K,V>(key, value);
        return node;
    }
    if (key == current->getKey()){
        throw runtime_error("no duplicate keys allowed: LinkedBST<K,V>::insert");
    }
    if (key < current->getKey()){
        current->setLeft(insertInSubtree(current->getLeft(),key,value)); 
        return current;
    }
    else{
        current->setRight(insertInSubtree(current->getRight(),key,value));
        return current;
    }
    
}

/*
Remove a node in the subtree
current: the current node
key: the key of the new node
returns: the removed node
*/
template <typename K, typename V>
LinkedBSTNode<K, V>*
LinkedBST<K, V>::removeFromSubtree(LinkedBSTNode<K, V>* current, K key) {
    if (current == nullptr){
        throw runtime_error("key not in tree: LinkedBST<K,V>::remove");
    }
    if (key < current->getKey()){
        current->setLeft(removeFromSubtree(current->getLeft(),key));
        return current;
    }
    else if (key > current->getKey()){
        current->setRight(removeFromSubtree(current->getRight(),key));
        return current;
    }
    else{
        if (current->getLeft() == nullptr && current->getRight()==nullptr){
            delete current;
            current = nullptr;
            return current;
        }
        if (current->getLeft() == nullptr){
            LinkedBSTNode<K, V>* temp = current->getRight();
            delete current;
            return temp;
        }
        if (current->getRight() == nullptr){
            LinkedBSTNode<K, V>* temp = current->getLeft();
            delete current;
            return temp;
        }
        else{
            LinkedBSTNode<K, V>* predecessor = nullptr;
            predecessor = current->getLeft();
            while(predecessor->getRight()!=nullptr){
                predecessor = predecessor->getRight();
            }
            current->setKey(predecessor->getKey());
            current->setValue(predecessor->getValue());
            current->setLeft(removeFromSubtree(current->getLeft(),predecessor->getKey()));
            return current;
        }
    }
}

/*
delete the bst node to node
current: the current node
*/
template <typename K, typename V>
void LinkedBST<K, V>::deleteSubtree(LinkedBSTNode<K, V>* current) {
    if (current == nullptr){
        return;
    }
    if (current -> getLeft() != nullptr){
        deleteSubtree(current->getLeft());
    }
    if (current -> getRight() != nullptr){
        deleteSubtree(current->getRight());
    }
    delete current;
}

/*
Implement Preorder Traversal on the bst
current: the current node
list: the list that this fuction puts the pair of key and value into
*/
template <typename K, typename V>
void LinkedBST<K, V>::buildPreOrderTraversal(LinkedBSTNode<K, V>* current,
                                             List<pair<K, V>>* list) {
    if (current == nullptr){
        return;
    }
    list->insertLast(pair<K,V>(current->getKey(),current->getValue()));
    buildPreOrderTraversal(current->getLeft(),list);
    buildPreOrderTraversal(current->getRight(),list);
}

/*
Implement Inorder Traversal on the bst
current: the current node
list: the list that this fuction puts the pair of key and value into
*/
template <typename K, typename V>
void LinkedBST<K, V>::buildInOrderTraversal(LinkedBSTNode<K, V>* current,
                                            List<pair<K, V>>* list) {
    if (current == nullptr){
        return;
    }
    buildInOrderTraversal(current->getLeft(),list);
    list->insertLast(pair<K,V>(current->getKey(),current->getValue()));
    buildInOrderTraversal(current->getRight(),list);
}

/*
Implement Postorder Traversal on the bst
current: the current node
list: the list that this fuction puts the pair of key and value into
*/
template <typename K, typename V>
void LinkedBST<K, V>::buildPostOrderTraversal(LinkedBSTNode<K, V>* current,
                                              List<pair<K, V>>* list) {
    if (current == nullptr){
        return;
    }
    buildPostOrderTraversal(current->getLeft(),list);
    buildPostOrderTraversal(current->getRight(),list);
    list->insertLast(pair<K,V>(current->getKey(),current->getValue()));
    
}

/*
Count the number of nodes in the bst
current: the current node
*/
template <typename K, typename V>
int LinkedBST<K, V>::countNodes(LinkedBSTNode<K, V>* current) {
    if (current == nullptr) {
        return 0;
    } else {
        return this->countNodes(current->getLeft()) +
               this->countNodes(current->getRight()) + 1;
    }
}

template <typename K, typename V>
void LinkedBST<K, V>::verifyKeysBoundedBy(LinkedBSTNode<K, V>* current,
                                          bool minApplies, K minBound,
                                          bool maxApplies, K maxBound) {
    if (minApplies && current->getKey() < minBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a "
                            "right descendent with lesser key");
    }
    if (maxApplies && current->getKey() > maxBound) {
        throw runtime_error("LinkedBST::verifyKeysBoundedBy: a node has a left "
                            "descendent with greater key");
    }
    if (current->getLeft() != nullptr) {
        verifyKeysBoundedBy(current->getLeft(), minApplies, minBound, true,
                            current->getKey());
    }
    if (current->getRight() != nullptr) {
        verifyKeysBoundedBy(current->getRight(), true, current->getKey(),
                            maxApplies, maxBound);
    }
}
