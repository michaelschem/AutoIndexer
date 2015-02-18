#include <cstring>
#include <iostream>

using namespace std;

#ifndef STOPWORDLIST_H
#define STOPWORDLIST_H

#include "debug.h"

class StopWordList
{

    private:
        char** stopWords;
        int size;
        int cap;

        void resize();

    public:
        StopWordList();
        ~StopWordList();
        StopWordList(const StopWordList&);
        StopWordList& operator=(const StopWordList&);
        void addWord(const char[]);
        bool isStopWord(const char*);
        void printList(ostream&);
};

#endif
