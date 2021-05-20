#include "Item.h"
#include "Stack.h"

// ITEM SETTERS & GETTERS

/****************************************************************************/
/* Function:   setName
/* Inputs:     name
/* Outputs:    N/A
/* Purpose:    sets the itemName
/****************************************************************************/ 
void Item::setName(string name)
{
    itemName = name;
}
/****************************************************************************/
/* Function:   getName
/* Inputs:     N/A
/* Outputs:    itemName
/* Purpose:    gets the itemName Item object data attribute
/****************************************************************************/ 
string Item::getName()
{
    return itemName;
}
/****************************************************************************/
/* Function:   setColor
/* Inputs:     color
/* Outputs:    N/A
/* Purpose:    sets the itemColor Item object data attribute
/****************************************************************************/ 
void Item::setColor(string color)
{
    itemColor = color;
}
/****************************************************************************/
/* Function:   getColor
/* Inputs:     N/A
/* Outputs:    itemColor
/* Purpose:    gets the itemColor Item object data attribute
/****************************************************************************/ 
string Item::getColor()
{
    return itemColor;
}

// STACK IMPLEMENTATION

/****************************************************************************/
/* Function:   push
/* Inputs:     Item object
/* Outputs:    N/A
/* Purpose:    adds new item by pushing it to the top of the Stack
/****************************************************************************/ 
void Stack::push(Item item)
{
    stackTop+=1;
    myStack[stackTop]=item;
    
}
/****************************************************************************/
/* Function:   isEmpty
/* Inputs:     N/A
/* Outputs:    boolean value returning true if stack isEmpty, else false
/* Purpose:    indicates whether or not the stack isEmpty
/****************************************************************************/ 
bool Stack::isEmpty()
{
    return this->stackTop<0;
}
/****************************************************************************/
/* Function:   pop
/* Inputs:     N/A
/* Outputs:    N/A
/* Purpose:    removes & discards item added most recently
/****************************************************************************/ 
void Stack::pop()
{
    this->stackTop--;
}
/****************************************************************************/
/* Function:   peek
/* Inputs:     N/A
/* Outputs:    prints the last item added to the stack to the console 
/* Purpose:    gets copy of item added to the stack most recently
/****************************************************************************/ 
Item Stack::peek()
{
    return myStack[stackTop];
}
/****************************************************************************/
/* Function:   display
/* Inputs:     N/A
/* Outputs:    prints each item contained in the stack to the console
/* Purpose:    displays the contents of the stack to the user
/****************************************************************************/ 
void Stack::display()
{
    cout<<"Item(s) in stack are: \n";
    for(int i=0;i<=stackTop;i++)
    {
        cout<<myStack[i].getName()<<" "<<myStack[i].getColor();
        if(i==stackTop)
            cout<<": is at the top of the stack.";
        cout<<endl;
    }
}

// HELPER FUNCTIONS

// helper function to itemCount
int Stack::getStackTop()
{
    return stackTop;
}

// returns count of items in stack
int Stack::itemCount()
{
    // itemcount
    return stackTop + 1;
}

void getPosition(list aList, string item)
{
    int length = aList.getLength();
    bool found = false;

    for (int i=1; i <= length; i++)
    {
        if (item == aList.getEntry(i))
        {
            found = true;
        }
    if ( found == true )
    {
        return item
    }
    else
    {
        cout << "Sorry, item not found."
    }
}