/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <stdexcept>

template <typename K, typename V> LinearDictionary<K, V>::LinearDictionary() {

}

template <typename K, typename V> LinearDictionary<K, V>::~LinearDictionary() {

}

/*
return the size of the number of elements inside the lineardictionary
*/
template <typename K, typename V> int LinearDictionary<K, V>::getSize() {
    return this->dictionary.size();
}

/*
check if the lineardictionary is empty
return true if it is, false if it is not
*/
template <typename K, typename V> bool LinearDictionary<K, V>::isEmpty() {
    return this->dictionary.empty();
}

/*
insert a key and its value into the lineardictionary
key: the key of the data
value: the value associated with the key
*/
template <typename K, typename V>
void LinearDictionary<K, V>::insert(K key, V value) {
    for (int i =0; i < this->dictionary.size(); i++){
        if (this->dictionary[i].first == key){
            throw std::runtime_error("The key is already in the vector: LinearDictionary<K,V>::insert");
        }
    }
    this->dictionary.push_back(pair<K,V>(key,value));
}

/*
update value of a designated key
key: the key of the data
value: the updated value associated with the key
*/
template <typename K, typename V>
void LinearDictionary<K, V>::update(K key, V value) {
    bool found = false;
    for (int i =0; i < this->dictionary.size(); i++){
        if (this->dictionary[i].first == key){
            this->dictionary[i].second = value;
            found = true;
            break;
        }
    }
    if (found == false){
        throw std::runtime_error("The key is not in the vector: LinearDictionary<K,V>::update");
    }
}

/*
get the value of a data using its key
key: the key of the data
*/
template <typename K, typename V> V LinearDictionary<K, V>::get(K key) {
    V temp;
    bool found = false;
    for (int i =0; i < this->dictionary.size(); i++){
        if (this->dictionary[i].first == key){
            found = true;
            temp = this->dictionary[i].second;
        }
        
    }
    if (found == false){
        throw std::runtime_error("Cannot find the key: LinearDictionary<K,V>::get");
    }
    return temp;
}

/*
check if the lineardictionary contains the data using a key
return true if contains, false if it doesn't
key: the key of the data
*/
template <typename K, typename V> bool LinearDictionary<K, V>::contains(K key) {
    bool found = false;
    for (int i =0; i < this->dictionary.size(); i++){
        if (this->dictionary[i].first == key){
            found = true;
        }
    }
    return found;
}

/*
remove a the data from the lineardictionary
key: the key of the data
*/
template <typename K, typename V> void LinearDictionary<K, V>::remove(K key) {
    bool found = false;
    for (int i =0; i < this->dictionary.size(); i++){
        if (this->dictionary[i].first == key){
            this->dictionary.erase(this->dictionary.begin()+i,this->dictionary.begin()+i+1);
            found = true;
        }
    }
    if (found == false){
        throw std::runtime_error("Cannot find the key: LinearDictionary<K,V>::remove");
    }
}

/*
return a vector containing all the keys inside the lineardictionary
*/
template <typename K, typename V> vector<K> LinearDictionary<K, V>::getKeys() {
    vector<K> keys;
    for (int i =0; i < this->dictionary.size(); i++){
        keys.push_back(this->dictionary[i].first);
    }
    return keys;
}

/*
return a vector of pairs containing all the keys and their value inside the lineardictionary
*/
template <typename K, typename V>
vector<pair<K, V>> LinearDictionary<K, V>::getItems() {
    return this->dictionary;
}
