#pragma once

/*
  Copyright (c) 2023
  Swarthmore College Computer Science Department, Swarthmore PA
  J. Brody, A. Danner, L. Fontes, L. Meeden, Z. Palmer, A. Soni
  Distributed as course material for Spring 2023
  CPSC 035: Data Structures and Algorithms
*/

#include <string>
#include <vector>

#include "adts/dictionary.h"
#include "hashTable.h"
#include "linearDictionary.h"
/**
 * This class represents a tool which can be used to perform a keyword
 * search on a document.  The user of this class instantiates it,
 * updates it with words from a document, and can then use it to
 * identify the pages on which specific words appear most frequently.
 */
class KeywordSearcher {
  public:
    /**
     * Creates a new keyword searcher with no data.
     */
    KeywordSearcher();

    /**
     * Destructs a KeywordSearcher and releases the memory it is using.
     */
    ~KeywordSearcher();

    /**
     * Loads the words from a given file into this searcher.
     * @param filename The name of the text file to use.
     * Throws a runtime error if the filename does not exist.
     */
    void loadWords(std::string filename);

    /**
     * Searches this object to find the pages on which a particular word most
     * frequently appeared.
     * @param word The word to find.
     * @return A vector of pairs between page numbers and occurrences.  The top
     *         ten pages are returned, ordered from most to least occurrences.
     *         All pairs have a positive (non-zero) number of occurrences; if a
     *         word appears on fewer than ten pages, the returned vector
     *         contains fewer than ten elements.
     */
    std::vector<std::pair<int, int>> search(std::string word);

  private:
    /*
    a dictionary that holds data with key of the words in the document and the value of pointers to another
    dictionary holding the appearence on each page
    */
    Dictionary<string, Dictionary<int, int>*>* WordHashTable;
    /*
    a helper function that hash the word appearence on one page to the big hash table
    int: the page number
    OnePage: the hash table that contains the number of appearence of each word on this page
    */
    void hashingToWordHashTable(int page, Dictionary<string, int>* OnePage);
};
