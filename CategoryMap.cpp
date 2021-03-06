
#include "CategoryMap.h"

using namespace std;
        
        /**
         * copies old values into new variables so the CategoryMap can be copied
         *
         */
        void CategoryMap::copyContents(const CategoryMap& cm)
        {
            size = cm.size;
            capacity = cm.capacity;
            subCategories = new char*[cm.capacity];
            categories = new char*[cm.capacity];
            for(int i = 0; i < cm.size; i++)
            {
                subCategories[i] = new char[strlen(cm.subCategories[i])+1];
                categories[i] = new char[strlen(cm.categories[i]) + 1];
                strcpy(subCategories[i], cm.subCategories[i]);
                strcpy(categories[i], cm.categories[i]);
            }
        }
        /**
         * simple resize function, if category map grows too big
         *
         */
        void CategoryMap::resize()
        {
            if (DEBUGl3)
                cout << "Resizing the Category Map from "
                    << capacity << " to " << (capacity + 10) << endl;
            char** tempSubCat;
            char** tempCat;

            tempSubCat = new char*[capacity + 10];
            tempCat = new char*[capacity + 10];
            //iterates through all spaces in subcategories and categories, copying their values into temporary char**'s
            for (int i = 0; i < capacity; i++)
            {
                tempSubCat[i] = subCategories[i];
                tempCat[i] = categories[i];
            }
            //delets old subCategories to make room for new
            delete [] subCategories;
            delete [] categories;
            
            //add's 10 to capacity and puts temporary char** into original char**'s
            capacity += 10;
            subCategories = tempSubCat;
            categories = tempCat;
            
        }
        /**
         * categoryMap constructor
         * Initilizes all vaiables
         */
        CategoryMap::CategoryMap()
        {
            subCategories = new char*[10];
            categories = new char*[10];
            size = 0;
            capacity = 10;
        }
        /**
         * overloaded contructor, to copy over vars
         *
         */
        CategoryMap::CategoryMap(const CategoryMap& rhs)
        {
            copyContents(rhs);
        }
        /**
         * overloaded assignment operator
         *
         */
        CategoryMap& CategoryMap::operator=(const CategoryMap& rhs)
        {
            if(this != &rhs)
            {
                delete [] subCategories;
                delete [] categories;

                copyContents(rhs);

            }
            return *this;
        }
        /**
         *Deconstructs the dynamic memory so it will not cause a memory leak
         *
         */
        CategoryMap::~CategoryMap(){
            if(size > 0){
                for(int i=0;i<size;i++){
                     delete subCategories[i];
                     delete categories[i];
                }
                delete [] subCategories;
                delete [] categories;
            }
        }

        /**
         * returns the category associated with a particular
         * subcategory
         *
         * potential source of memory leak (fixed)
         */
        char* CategoryMap::contains(char word[])
        {
            for (int i = 0; i < size; i++)
            {
                if(strcmp(subCategories[i], word) == 0)
                {
                    return categories[i];
                    break;
                }
            }
            

        }
        /**
         * adds entry to category map accepting the subcategory and the category it is in
         *
         *
         */
        void CategoryMap::addEntry(char* subcat, char* cat)
        {
            if (size == capacity)
                resize();
            subCategories[size] = new char[strlen(subcat) + 1];
            categories[size] = new char[strlen(cat) + 1];

            strcpy(subCategories[size], subcat);
            strcpy(categories[size], cat);
            size++;
        }
        /**
         * prints the whole category map by iterating through each position in the categories and subcategories
         *
         *
         */
        void CategoryMap::printmap()
        {
            for (int i = 0; i < size; i ++)
            {
                cout << subCategories[i] << " -> " << categories[i] << endl;
            }
        }

