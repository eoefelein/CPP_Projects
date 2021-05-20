//********************************************************************
//
//  Developer:          Erin Oefelein
//
//  Lab #:            	Three
//
//  File Name:          linkedlist.cpp
//
//  Course:             COSC-1337 Data Structures & Algorithms
//
//  Due Date:           5/2/2021
//
//  Instructor:         Kathyrn Rehfield
//
//  Description:
//      File contains implementation of LinkedList class methods.
//
//********************************************************************
#include <iostream>

using namespace std;

//**************************************************************
//
//  	LinkedList constructor
//
//  Description:  called when LinkedList object is created
//					to initialize numItems class data attribute
//
//  Parameters:   N/A
//
//  Returns:      N/A
//
//**************************************************************
LinkedList::LinkedList() {
   numItems = 0; // initialize numItems to 0
}

//**************************************************************
//
//  Method: 	  LinkedList getCurrentSize
//
//  Description:  accessor method that returns
//				the current size of the LinkedList,
//				stored in the private class data attribute, numItems.
//
//  Parameters:   N/A
//
//  Returns:      numItems
//
//**************************************************************
int LinkedList::getCurrentSize() {
	return numItems;
}

//**************************************************************
//
//  Method: 	  LinkedList addNode
//
//  Description:  method takes one string value as input
//				creates a node object, and 
//              sets the string value to the line attribute.
//				Node is then added to the back of the linkedlist.
//
//  Parameters:   N/A
//
//  Returns:      numItems
//
//**************************************************************
void LinkedList::addNode(string line) {

    Node*  node = new Node(); // create new node object
    node->setLine(line); // set line attribute to new node

    // check for first node
    if (numItems==0) { // if list is empty (headPtr is null) then...
    	// cast temp to shared_ptr to equate to headPtr
        shared_ptr<Node> temp(node);
        headPtr = temp; //  new node is first to insert
        numItems++; // increment numItems in the linkedlist
        return;
    }
    else { // if list contains nodes (headPtr is not null) then...
        // create pointer to iterate list
    	Node* iter = headPtr.get();
        
        // iterate list until last node
        while (iter->getNext() != nullptr) {
            iter = iter->getNext().get();
        }
        // add node to end of list
        iter->setNext(node);
        numItems++; // increment numItems in the linkedlist
    }
}

//**************************************************************
//
//  Method: 	  LinkedList toVector
//
//  Description:  creates a new Node object and sets the line,
//			passed to the function as a parameter, to the new Node object.
//			The new Node object containing line, then gets added
//			to the end of the LinkedList.
//
//  Parameters:   string line
//
//  Returns:      N/A
//
//**************************************************************
std::vector<string> LinkedList::toVector() {
	std::vector<string> listcontents;
	// create pointer to iterate list
	Node* iter = headPtr.get();
    // print each node's data
    while (iter != NULL) {
    	// push_back to get strings into vector
    	listcontents.push_back(iter->getLine());
        // move to next node
        iter = iter->getNext().get();
    }
    return listcontents;
}

//**************************************************************
//
//  Method: 	  LinkedList toSortedVectorNoDups
//
//  Description:  creates a new Node pointer, iter,
//					to iterate & compare
//
//  Parameters:   string line
//
//  Returns:      N/A
//
//**************************************************************
std::vector<string> LinkedList::toSortedVectorNoDups() {

	// create vector to store sorted list contents
	std::vector<string> list_sorted;
	// create variable to store index of last value in linkedlist
	int idx = 0; // initialize to 0
    // create variable to indicate when the min value is found
    bool found = true; // initialize to true
    // create pointer to iterate list
    Node* iter = headPtr.get(); // initialize to headPtr
    // create variable to store min value
    string min = iter->getLine(); // initialize to data at headPtr
    // create variable to store max value
    string max =iter->getLine(); // initialize to data at headPtr
    
    while(iter != nullptr){ // while iter is not at end of linkedlist
        if(iter->getLine() <= min ){ // if current line is less than min...
            
            min = iter->getLine(); // ... set as min
        }
        if(iter->getLine() >= max ){ // if current line is greater than max...
            
            max = iter->getLine(); // ... set as max
        }
        iter = iter->getNext().get(); // get the next value in the linkedlist
    }
    
    list_sorted.push_back(min); // push the min valued line onto the list_sorted vector

    while(found){
        
        iter = headPtr.get(); // initialize to headPtr
        min = max; // store max value in min to ensure capture of all min values
        found = false; // while loop will not continue unless if condition is satisfied...
        while(iter!=nullptr){ // while iter is not at end of linkedlist
            // if line at iter is less than min and greater than last value stored in list...
            if(iter->getLine() < min && iter->getLine() > list_sorted[idx] ){
                min = iter->getLine(); // ... set as min and...
                found = true; // ... set found to true to continue the while loop
            }
             iter = iter->getNext().get(); // get the next line and store to iter
        }

        list_sorted.push_back(min); // push line onto list_sorted vector
        idx++; // increment the index
    }
    return list_sorted;
}

//**************************************************************
//
//  	LinkedList destructor
//
//  Description:  automatically called to deallocate the memory
//					which was allocated upon the creation of a
//					LinkedList class object.
//					Also does any other necessary cleanup
//					upon destruction of the LinkedList class object.
//
//  Parameters:   N/A
//
//  Returns:      N/A
//
//**************************************************************
LinkedList::~LinkedList() {

	// create temp shared_ptr<Node> pointer
	shared_ptr<Node> temp  = headPtr;

	while (temp) {

		// store temp to curr shared_ptr
		shared_ptr<Node> curr = temp;
		// getNext in LinkedList
		temp = temp->getNext();
		// eliminate one owner of curr shared_ptr
		curr.reset();
	}

	// set headPtr to nullptr
	headPtr = nullptr;
}