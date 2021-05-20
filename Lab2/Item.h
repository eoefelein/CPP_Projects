#ifndef ITEM_CLASS_
#define ITEM_CLASS_

#include <string>
#include <iostream>

using std::string; 
using std::cout; 
using std::endl;

class Item 
{
    private:
        string itemName; // private data member of string datatype
        string itemColor; // private data member of string datatype
    public:
        // constructor initializes attributes to null
        Item(string name = "", string color = "") : itemName(name), itemColor(color){};
        // accessor and mutator methods for private data members
        string getName();
        void setName(string name);
        string getColor();
        void setColor(string color);
};

#endif