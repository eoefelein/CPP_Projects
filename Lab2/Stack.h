#ifndef STACK_CLASS_
#define STACK_CLASS_

#include "Item.h"

class Stack
{
    private:
        int stackTop; // stackTop variable
        Item myStack[1000]; // stack variable
    public:
        Stack() : stackTop(-1){}; // stack constructor
        bool isEmpty(); // indicate if entries exist in the stack
        void push(Item); // add item
        void pop(); // remove top item
        Item peek(); // look at top item
        void display(); // displays items in the stack
        
        // helper functions
        int getStackTop(); // helper function to itemCount
        int itemCount(); // returns count of items in stack
};

#endif