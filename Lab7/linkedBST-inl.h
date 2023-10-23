/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>
#include <utility>
#include <vector>

#include "adts/list.h"
#include "adts/queue.h"
#include "adts/stlList.h"
#include "adts/stlQueue.h"

#include "linkedBSTNode.h"
#include "helpers.h"

using std::pair;
using std::runtime_error;
using std::vector;

/*
Consturcts a bst
*/
template <typename K, typename V> LinkedBST<K, V>::LinkedBST() {
  this->size = 0;
  this->root = nullptr;
}

/*
desturcts a bst
*/
template <typename K, typename V> LinkedBST<K, V>::~LinkedBST() {
  // To do: implement the destructor
  // Use the helper deleteSubtree 
  deleteSubtree(this->root);
}

/*
get the size of the bst
returns: the size of the bst
*/
template <typename K, typename V> int LinkedBST<K, V>::getSize() {
  return this->size;
}

/*
check if the bst is empty or not
returns: true if empty, false if not empty
*/
template <typename K, typename V> bool LinkedBST<K, V>::isEmpty() {
  if (this->size == 0){
    return true;
  }
  else{
    return false;
  }
}

/*
insert a node into the bst
key: the key of the node
value: the value of the node
*/
template <typename K, typename V> void LinkedBST<K, V>::insert(K key, V value) {
  // Use the helper insertInSubtree
  this->root = this->insertInSubtree(this->root,key,value);
  this->size++;
}

/*
update the value inside a node
key: the key of the node
value: the value of the node that needs to be updated to
*/
template <typename K, typename V> void LinkedBST<K, V>::update(K key, V value) {
  // Use the helper updateInSubtree
  updateInSubtree(this->root, key, value);
}

/*
get the value inside a node with the key
key: the key of the node
returns: the value inside the node
*/
template <typename K, typename V> V LinkedBST<K, V>::get(K key) {
  // Use the helper findInSubtree
  return findInSubtree(this->root, key);
}

/*
check if the bst contains the key
key: the key of the node
returns: true if contains; false if not contains
*/
template <typename K, typename V> bool LinkedBST<K, V>::contains(K key) {
  // Use the helper containsInSubtree
  return containsInSubtree(this->root, key);
}

/*
remove a node in the bst
key: the key of the node
*/
template <typename K, typename V> void LinkedBST<K, V>::remove(K key) {
  // Use the helper removeFromSubtree
  this->root = removeFromSubtree(this->root, key);
  this->size--;
}

/*
get a vector containing all the keys inside a bst
returns: a vector containing all the keys inside a bst
*/
template <typename K, typename V> vector<K> LinkedBST<K, V>::getKeys() {
  // Use one of the traversals
  List<pair<K,V>>* results = new STLList<pair<K,V>>();
  buildInOrderTraversal(this->root,results);
  vector<pair<K,V>> vec = dynamicListToStaticVector(results);
  vector<K> veckey;
  for (int i = 0; i < vec.size(); i++){
    pair<K,V> temp = vec[i];
    veckey.push_back(temp.first);
  }
  delete results;
  return veckey;
}

/*
get a vector containing a pair of all the keys and its values inside a bst
returns: a vector containing a pair of all the keys and its values inside a bst
*/
template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::getItems() {
  // Use one of the traversals
  List<pair<K,V>>* results = new STLList<pair<K,V>>();
  buildInOrderTraversal(this->root,results);
  vector<pair<K,V>> vec = dynamicListToStaticVector(results);
  delete results;
  return vec;
}

/*
get the height of the bst
returns: the height of the bst
*/
template <typename K, typename V> int LinkedBST<K, V>::getHeight() {
  // Use the helper getHeightInSubtree
  return getHeightInSubtree(this->root);
}

/*
get the max key of the bst
returns: the max key of the bst
*/
template <typename K, typename V> K LinkedBST<K, V>::getMaxKey() {
  // Use the helper getMaxInSubtree
  return getMaxInSubtree(this->root).first;
}

/*
get the min key of the bst
returns: the min key of the bst
*/
template <typename K, typename V> K LinkedBST<K, V>::getMinKey() {
  // Use the helper getMinInSubtree
  return getMinInSubtree(this->root).first;
}

/*
get a vector of pairs of key and value in Preorder of the bst
returns: a vector of pairs of key and value in Preorder of the bst
*/
template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePreOrder() {
  // Use the helper buildPreOrderTraversal
  // Also consider using dynamicListToStaticVector in helpers.h
  List<pair<K,V>>* results = new STLList<pair<K,V>>();
  buildPreOrderTraversal(this->root,results);
  vector<pair<K,V>> vec = dynamicListToStaticVector(results);
  delete results;
  return vec;
}

/*
get a vector of pairs of key and value in Inorder of the bst
returns: a vector of pairs of key and value in Inorder of the bst
*/
template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseInOrder() {
  // Use the helper buildInOrderTraversal
  // Also consider using dynamicListToStaticVector in helpers.h
  List<pair<K,V>>* results = new STLList<pair<K,V>>();
  buildInOrderTraversal(this->root,results);
  vector<pair<K,V>> vec = dynamicListToStaticVector(results);
  delete results;
  return vec;
}

/*
get a vector of pairs of key and value in Postorder of the bst
returns: a vector of pairs of key and value in Postorder of the bst
*/
template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traversePostOrder() {
  // Use the helper buildPostOrderTraversal
  // Also consider using dynamicListToStaticVector in helpers.h
  List<pair<K,V>>* results = new STLList<pair<K,V>>();
  buildPostOrderTraversal(this->root,results);
  vector<pair<K,V>> vec = dynamicListToStaticVector(results);
  delete results;
  return vec;
}

/*
get a vector of pairs of key and value in levelorder of the bst
returns: a vector of pairs of key and value in levelorder of the bst
*/
template <typename K, typename V>
vector<pair<K, V>> LinkedBST<K, V>::traverseLevelOrder() {
  Queue<LinkedBSTNode<K, V>*>* queue = new STLQueue<LinkedBSTNode<K, V>*>();
  List<pair<K,V>>* results = new STLList<pair<K,V>>();
  queue->enqueue(this->root);
  while (!queue->isEmpty()){
    LinkedBSTNode<K, V>*  current = queue->dequeue();
    if (current->getLeft()!=nullptr){
      queue->enqueue(current->getLeft());
    }
    if (current->getRight()!=nullptr){
      queue->enqueue(current->getRight());
    }
    results->insertLast(pair<K,V>(current->getKey(),current->getValue()));
  }
  vector<pair<K,V>> vec = dynamicListToStaticVector(results);
  delete queue;
  delete results;
  return vec;
}

template <typename K, typename V> void LinkedBST<K, V>::checkInvariants() {
    if (this->countNodes(this->root) != this->size) {
        throw runtime_error(
            "Problem in BST: Node count doesn't match tree size");
    }
    if (this->root != nullptr) {
        // The bounds provided here are arbitrary because the false
        // arguments indicate that they do not apply.  But we need a
        // value of type K to fill this parameter since we don't have
        // globally min/max K values generically.
        this->verifyKeysBoundedBy(this->root, false, this->root->getKey(),
                                  false, this->root->getKey());
    }
}
