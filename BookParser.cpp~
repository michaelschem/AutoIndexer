
#include "BookParser.h"

using namespace std;
        
        /**
         * Constructor, accepts a char* for filename
         *
         * Checks to see if the file can be opened, returns an error if it cannot be opened.
         */
        BookParser::BookParser(const char* fName)
        {
            file.open(fName);
            if (!file.is_open())
                cerr << "ERROR:  Cannot open Book Parser File" << endl;
        }
        
        /**
         * Deconstructor, closes the file
         *
         */
        
        BookParser::~BookParser()
        {
            file.close();
        }
        /**
         * checks to see if the file is open, returns bool
         *
         */
        bool BookParser::isFileOpen()
        {
            return file.is_open();
        }
        /**
         * parse's the index passed by reference.
         *
         */
        void BookParser::parseBook(MyIndex& idx)
        {

            char currentWord[51] = {0};
            char currentPageString [10] = {0} ;
            int currentPage;

            file >> currentWord;
            while (currentWord[1] != '-')
            {
                //check if page number and handle if so
                if(currentWord[0] == '[')
                {
                    if (DEBUGl2) cout << "before: *" << currentWord << "* *" << currentPageString << "*" << endl;

                    //copy from 2nd character of currentWord to before the closing ]
                    //which is at strlen(currentWord)
                    int count = 1;
                    while (currentWord[count] != ']')
                    {
                        if (DEBUGl2) cout << "  count = " << count << endl;
                        currentPageString[count - 1] = currentWord[count];
                        count++;
                    }
                    currentPageString[count - 1] = '\0';

                    if (DEBUGl4) cout << "After: " << currentWord << " " << currentPageString << endl;

                    currentPage = getPageNumber(currentPageString);

                    if (DEBUGl4)
                        cout << "    Handling new page number: " << currentPage << endl;
                }
                else
                {
                    //convert the word to upper case
                    Word::toUpper(currentWord);
                    if (DEBUGl4)
                        cout << "  Handling word " << currentWord << endl;

                    //add to the index (passed in as param) with current page
                    idx.addWord(currentWord, currentPage);
                }
                //get next word
                file >> currentWord;
            }
        }

        int BookParser::getPageNumber(char* str)
        {
            return atoi(str);
        }

