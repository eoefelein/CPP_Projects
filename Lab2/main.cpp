#include "program.cpp"

#include <iostream>
using std::cin;
using std::cout;

#include <limits>
using std::numeric_limits;
using std::streamsize;

/* Program Description:
   Program allows user to:
   1) Create an item by choosing item color and name
   2) Remove the last item
   3) Look at the item put in the list
   4) Display all items
*/

int main()
{
    // declare stack & do-while sentinel variables
    char ch;
    Stack stack;

    // do-while loop allows user to choose menu item
    do {

    // declare user input variables    
    string userInputName;
    string userInputColor;

    // display menu
    cout<<endl<<endl;
    cout<<"*****Menu Options******"<<endl;
    cout<<"1. Add item"<<endl;
    cout<<"2. Remove top item"<<endl;
    cout<<"3. Look at top item"<<endl;
    cout<<"4. Display all items"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"************************"<<endl;

     // store user choice to ch variable
     cout << "Choose your operation by selecting a number from the menu: ";
     cin >> ch;
     
     // declare variables to validate name input
     int i;
     int nameLength;
     
     // declare variables to validate color input
     int k;
     int colorLength;

     // declare variable to validate char input
     bool flag = false;

     switch(ch)
     {
         // ADD
         case '1':
	 
        while(!flag)
        {
        // prompt user for item name input
        cout << "Enter item name: ";
	    cin >> userInputName;

        // initialize validation variables
        i = 0;
        nameLength = userInputName.length();
        flag = true;

        // validate character input for name
	    while (i < nameLength)
        {
           // should user input be outside acceptable char input...
           if (!((userInputName[i] >= 'a' &&  userInputName[i] <= 'z' ) || (userInputName[i] >= 'A' && userInputName[i] <= 'Z')))
            {
                cout << "Error - Invalid input; Program accepts character input only. Program does not accept spaces.";
                cin.clear();
                /* ignore chars 
                (until max num of chars the stream buffer can support is reached) 
                until the delimiter \n occurs
                */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                flag = false;
            }
            i++;
        }
        }
        
        //prompt user to set item color
        cout << "Enter item color: ";
        cin >> userInputColor;

        k = 0;
        colorLength = userInputColor.length();
        // validates character input for color
        while (k < colorLength)
        {
            // should user input be outside acceptable char input...
            if (!((userInputColor[k] >= 'a' &&  userInputColor[k] <= 'z' ) || (userInputColor[k] >= 'A' && userInputColor[k] <= 'Z')))
            {
                cout << "Error - Invalid input; Program accepts character input only. Program does not accept spaces.";
                cin.clear();
                /* ignore chars 
                (until max num of chars the stream buffer can support is reached) 
                until the delimiter \n occurs
                */
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                flag = false;
            }
            k++;
        }

        if((stack.itemCount() <= 1000))
        {
            // declare new item obj for every new item added
            Item myitem(userInputName,userInputColor);

            // verify stack has room to add
            cout<<"\nStack has room to add.\n";
            // display item to be added
            cout<<"Adding item: "<<myitem.getName()<<" "<<myitem.getColor()<<"... "<<endl;
            // push item
            stack.push(myitem);
            // success message
            cout<<"Item added to stack.\n";   
        }
        break;

         // POP
         case '2':
         if(!(stack.isEmpty()))
         {
            // display item to remove
            cout<<"Item to remove is: "<<stack.peek().getName()<<" "<<stack.peek().getColor()<<endl<<endl;
            // pop top item
            stack.pop();
            // success message
            cout<<"Item removed."<<endl;
         }
         else
            // message should there be no items to remove
            cout<<"The stack has no items to remove."<<endl;
         break;

         // PEEK
         case '3':
         if(!(stack.isEmpty()))
         {
            // peek item
            cout<<"Item at top of stack is: "<<stack.peek().getName()<<" "<<stack.peek().getColor()<<endl<<endl;
         }
         else
            // message should there be no items to peek
            cout<<"The stack has no items to view."<<endl;
         break;

         // DISPLAY
         case '4':
        if(!(stack.isEmpty()))
        {
            // display number of items currently in the stack
            cout<<"\nThe stack contains "<<stack.itemCount()<<" item(s)."<<endl;
            // display all items currently in the stack
            stack.display();
        }
         else
            // message should there be no items to display
            cout<<"The stack has no items to display."<<endl;
         break;

         // EXIT PROGRAM
         case '5':
            break;
        
         default:
            // prompt should user enter a choice outside 1-5
            cout<<"Please enter a valid choice."<<endl;
      }
   }while(ch!='5');
}