


#ifndef CATEGORYMAP_H
#define CATEGORYMAP_H
#include <iostream>
#include <cstring>
#include "debug.h"
using namespace std;

/**
 *
 * Stores the data in an inverse order.
 * If helperfile contains:
 *    apple = ipod ipad macbook
 * this structure will look like
 *    ipod->apple
 *    ipad->apple
 *    macbook->apple
 *
 *
 */
class CategoryMap
{
    private:
        char** subCategories;
        char** categories;
        int size;
        int capacity;

        void copyContents(const CategoryMap&);
        void resize();

    public:

        CategoryMap();
        CategoryMap(const CategoryMap&);
        CategoryMap& operator=(const CategoryMap&);
        ~CategoryMap();
        /**
         * returns the category associated with a particular
         * subcategory
         *
         * potential source of memory leak
         */
        char* contains(char[]);
        void addEntry(char*, char*);
        void printmap();

};

#endif
