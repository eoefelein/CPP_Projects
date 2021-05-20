# CPP_Projects

Lab 1: ARRAYS & RECURSION

Write a method to sort an array bag in ascending order, using the Bubble Sort.
Implement two (2) versions of the binary search, one using repetition and one using recursion.

Give the user the option to:
1) Display the contents of the bag
    The display function should be a program function using the toVector method to get the contents of the bag to then display.
2) Sort the bag
3) Search for a value using iterative or recursive search
Allow the user to keep displaying, searching and sorting until they are done.

Lab 2: STACKS

Write a program to keep track of a collection of "Item" objects.
Create an “Item” class with the following private data attributes:
    Item name (string)
    Color (string)
The "Item" class should also have the following public methods:
    Accessors and mutators for each attribute
    Constructor that initializes the attributes to nulls (empty string)

 
Create another class to implement a stack of "Items" using an array-based implementation.
The stack class should include the following operations:
    isEmpty – tell whether there are any entries in the stack
    push – add another item
    pop – remove the top item
    peek – look at the item on top
    display - displays the items in the stack indicating where the top is (this one just gives and easy way for me to see what is in the stack as I test your program)

User Interface
Write a program that offers a way to:
1) Add an item
2) Remove the last item
3) Look at the last item put in the list

Lab 3: LINKED LISTS
 
Write a program to process the lines in a text file using a linked list ADT and shared pointers.

Node class
Create a class “Node” with the following private data attributes:
    line – line from a file (string)
    next - (shared pointer to a Node)
The "Item" class will also have the following public methods:
    Accessors and mutators for each attribute
    Constructor that initializes the attributes to nulls (empty string)
    The shared pointer gets initialized automatically.

LinkedList class
Create a class “LinkedList” with the following private data attributes:
    headPtr – shared pointer to the head of the list
    numItems – number of items in the list
The "LinkedList" class will also have the following public methods:
    1) Accessor to get the current size
    2) Constructor that initializes numItems to zero
    3) Add a node – this method will take as input one string value. 
    It will then create a node object and set the attribute. 
    Then it will put it in the linked list at either the front or the back.
    4) toVector – returns vector with the contents of the list. 
    Use only the “push_back” method to get the strings into the vector.
    5) toSortedVectorNoDups – returns a vector with the contents of the list in ascending order with no duplicates. 
    Use only the “push_back” method to get the strings into the vector.

Client Program
Program will ask the user for the file name, open the text file , read each line and store it in a Node.  
Ensure the file has opened correctly before processing it.
Display the contents of the list (the lines that were read from the file) with all the duplicates. 

Use a class method “toVector” that puts all of the lines into a vector and returns it to the program that will display it.

Create a method called “toSortedVectorNoDups” that will put the contents of the list into a vector and returns it to the program do display it.  
Your method will put the lines into the vector in sorted order. You will put each line into the vector only once.

The client program will do the following:
    Read the file name from the user
    Display the lines from the file using the class method toVector to get the lines.
    Display the number of lines in the vector.
    Display the lines from the file in sorted order with no dupicates using the toSortedVectorNoDups method.
    Display the number of lines that were in the vector. 

Lab 4: BINARY TREES

Create a class for EmployeeInfo that contains:
    Employee ID Number – int
    Employee Name – string

Implement a binary tree whose nodes hold an instance of the EmployeeInfo class. The nodes should be sorted by Employee ID.
Program should read an Employee ID and display a message informing the user whether the ID was found in the tree or not.

The main program will have one binary tree object. All operations on the binary tree should be class methods.
Some additional methods to include:
    Display the tree
    Allow user to add a new employee
    Allow user to remove an employee
