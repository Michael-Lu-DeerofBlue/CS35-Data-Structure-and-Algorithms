/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include "keywordSearcher.h"
#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

#include <string>
#include <vector>
#include "adts/dictionary.h"
#include "linearDictionary.h"
#include "adts/priorityQueue.h"
#include "adts/stlMaxPriorityQueue.h"

/*
initialize a keywordsearcher
*/
KeywordSearcher::KeywordSearcher() {
    this->WordHashTable= new HashTable<string, Dictionary<int, int>*>();
}

/*
destructs a keywordsearcher
*/
KeywordSearcher::~KeywordSearcher() {
    vector<pair<string, Dictionary<int, int>*>> items;
    items = this->WordHashTable->getItems();
    for (int i = 0; i < items.size(); i++){
        delete items[i].second;
    }
    delete this->WordHashTable;
}

/*
a helper function that hash the word appearence on one page to the big hash table
int: the page number
OnePage: the hash table that contains the number of appearence of each word on this page
*/
void KeywordSearcher::hashingToWordHashTable(int page, Dictionary<string, int>* OnePage){
    vector<pair<string,int>> items;
    items = OnePage->getItems();
    for (int i = 0; i < items.size(); i ++){
        string word = items[i].first;
        int appearence = items[i].second;
        if (this->WordHashTable->contains(word)){
            Dictionary<int, int>* small_hash = WordHashTable->get(word);
            small_hash->insert(page,appearence);
                }
        else{
            Dictionary<int, int>* new_small_hash = new HashTable<int,int>();
            new_small_hash->insert(page,appearence);
            this->WordHashTable->insert(word,new_small_hash);
        }
    }
}

/*
load the words into this object
filename: the name of the document
*/
void KeywordSearcher::loadWords(string filename) {
    ifstream my_file;
    my_file.open(filename);
    string element;
    int page = 0;
    bool newpage = false;
    my_file >> element;
    Dictionary<string, int>* OnePage = new HashTable<string, int>();
    while(!my_file.eof()){
        if (element == "$$@@$$PAGE:"){
            newpage = true;
            hashingToWordHashTable(page, OnePage);
            delete OnePage;
            Dictionary<string, int>* new_OnePage = new HashTable<string, int>();
            OnePage = new_OnePage;
        }
        else{
            if (newpage == true){
                page =  stoi(element);
                newpage = false;
            }
            else{
                if (OnePage->contains(element) == false){
                    OnePage->insert(element,1);
                }
                else{
                    int times = 0;
                    times = OnePage->get(element);
                    OnePage->update(element,times+1);
                }
            }
        }
        my_file >> element;
  }
  hashingToWordHashTable(page, OnePage);
  delete OnePage;
}

/*
the search function that searches the word
returns a vector that contains the top 10, or top n, page that the word appears the most.
word: the word you want to search
*/
vector<pair<int, int>> KeywordSearcher::search(string word) {
    vector<pair<int,int>> result;
    if (this->WordHashTable->contains(word)){
        vector<pair<int,int>> page_occurence;
        page_occurence = this->WordHashTable->get(word)->getItems();
        for (int i = 0; i < page_occurence.size(); i++){
            int temp = page_occurence[i].first;
            page_occurence[i].first = page_occurence[i].second;
            page_occurence[i].second = temp;
        }
        PriorityQueue<int,int>* heap = new STLMaxPriorityQueue<int,int>(page_occurence);
        if (page_occurence.size() < 10){
            pair<int,int> value;
            for (int i = 0; i < page_occurence.size(); i++){
                value.second = heap->peekPriority();
                value.first = heap->remove();
                result.push_back(value);
            }
        }
        else{
            pair<int,int> value;
            for (int i = 0; i < 10; i++){
                value.second= heap->peekPriority();
                value.first = heap->remove();
                result.push_back(value);
            }
        }
        delete heap;
        return result;
    }
    else{
        return result;
    }
}
