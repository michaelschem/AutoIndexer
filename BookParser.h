
#include <iostream>
#include <cstdlib>
#include <fstream>
#include "index.h"
#include "debug.h"
#include "word.h"

using namespace std;

#ifndef BOOKPARSER_H
#define BOOKPARSER_H

class BookParser
{
    private:
        ifstream file;

    public:
        BookParser(const char*);
        ~BookParser();
        bool isFileOpen();
        void parseBook(MyIndex&);
        int getPageNumber(char*);
};

#endif
