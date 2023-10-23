/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <iostream>
#include <stdexcept>
#include <utility>
#include <vector>

#include "hashFunctions.h"
using std::pair;
using std::runtime_error;
using std::vector;

/*
initialize a hashtable
*/
template <typename K, typename V> HashTable<K, V>::HashTable() {
    this->capacity = 10;
    this->maxLoadFactor = 0.75;
    this->size = 0;
    this->table = new LinearDictionary<K,V>[this->capacity];
}

/*
initialize a hashtable with a designated maxloadfactor
*/
template <typename K, typename V>
HashTable<K, V>::HashTable(float maxLoadFactor) {
    this->capacity = 10;
    this->maxLoadFactor = maxLoadFactor;
    this->size = 0;
    this->table = new LinearDictionary<K,V>[this->capacity];

}

/*
destructs the hashtable
*/
template <typename K, typename V> HashTable<K, V>::~HashTable() {
    delete[] this->table;
}

/*
return the size of the number of elements inside the hashtable
*/
template <typename K, typename V> int HashTable<K, V>::getSize() {
    return this->size;
}

/*
check if the hashtable is empty
return true if it is, false if it is not
*/
template <typename K, typename V> bool HashTable<K, V>::isEmpty() {
    bool found = false;
    if (this->size == 0){
        found = true;
    }
    else{
        found = false;
    }
    return found;
}

/*
insert a key and its value into the hashtable
key: the key of the data
value: the value associated with the key
*/
template <typename K, typename V> void HashTable<K, V>::insert(K key, V value) {
    int index = hash(key,this->capacity);
    if (this->table[index].contains(key)){
        throw runtime_error("Key already exist, no duplicates allowed: HashTable<K,V>::insert");
    }
    this->table[index].insert(key,value);
    this->size++;
    
    float load = float(this->size)/this->capacity;
    
    if (load > this->maxLoadFactor){
        expandCapacity();
    } 
}

/*
update value of a designated key
key: the key of the data
value: the updated value associated with the key
*/
template <typename K, typename V> void HashTable<K, V>::update(K key, V value) {
    int index = hash(key,this->capacity);
    this->table[index].update(key,value);
}

/*
get the value of a data using its key
key: the key of the data
*/
template <typename K, typename V> V HashTable<K, V>::get(K key) {
    int index = hash(key,this->capacity);
    return this->table[index].get(key);
}

/*
check if the hashtable contains the data using a key
return true if contains, false if it doesn't
key: the key of the data
*/
template <typename K, typename V> bool HashTable<K, V>::contains(K key) {
    int index = hash(key,this->capacity);
    return this->table[index].contains(key);
}

/*
remove a the data from the hashtable
key: the key of the data
*/
template <typename K, typename V> void HashTable<K, V>::remove(K key) {
    int index = hash(key,this->capacity);
    this->table[index].remove(key);
    this->size--;
}

/*
return a vector containing all the keys inside the hashtable
*/
template <typename K, typename V> vector<K> HashTable<K, V>::getKeys() {
    vector<K> result;
    vector<K> temp;
    for (int i = 0; i < this->capacity; i++){
        temp = table[i].getKeys();
        result.insert((result).end(), temp.begin(), temp.end());
    }
    return result;
}

/*
return a vector of pairs containing all the keys and their value inside the hashtable
*/
template <typename K, typename V>
vector<pair<K, V>> HashTable<K, V>::getItems() {
    vector<pair<K,V>> result;
    vector<pair<K,V>> temp;
    for (int i = 0; i < this->capacity; i++){
        temp = table[i].getItems();
        result.insert((result).end(), temp.begin(), temp.end());
    }
    return result;
}

/*
a private fuction that ensures the capacity of the load of the hashtable doesn't exceed the maxloadfactor
it will double the capacity the load exceeds the maxloadfactor
*/
template <typename K, typename V> void HashTable<K, V>::expandCapacity() {
    LinearDictionary<K,V>* newtable = new LinearDictionary<K,V>[this->capacity*2];
    vector<pair<K,V>> result;
    result = this->getItems();
    delete[] this->table;
    this->table = newtable;
    this->capacity = this->capacity*2;
    this->size = 0;
    for (int i = 0; i < result.size(); i++){
        this->insert(result[i].first,result[i].second);
    }
}
