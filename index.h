
#include <cstring>
#include <iostream>

using namespace std;

#include "word.h"
#include "StopWordList.h"
#include "CategoryMap.h"
#include "debug.h"

#ifndef INDEX_H
#define INDEX_H

class MyIndex
{
    private:

        Word** wordList;
        int wordListSize;
        int wordListCapacity;

        StopWordList swl;
        CategoryMap catmap;
        /**
         * resize the wordList array
         */
        void resize();
        //I don't think I ever want to copy one of these
        MyIndex(const MyIndex&);
        /**
         * Sort the words in the index
         * Using a basic selection sort
         * Referenced: http://www.algolist.net/Algorithms/Sorting/Selection_sort
         */
        void sortIdx();
    public:

        MyIndex(StopWordList&, CategoryMap&);
        MyIndex();
        ~MyIndex();
        /**
         * adds a word to the index at a given page number
         * if its not a stop word.  Handles categories as well.
         */
        void addWord(char[], int, bool = false);

        bool isInIndex(char[]);
        /**
         * Print the index in the required format given a particular
         * output stream
         */
        void printList(ostream&);

};

#endif
