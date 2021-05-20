//********************************************************************
//
//  Developer:          Erin Oefelein
//
//  Lab #:            	Three
//
//  File Name:          node.cpp
//
//  Course:             COSC-1337 Data Structures & Algorithms
//
//  Due Date:           5/2/2021
//
//  Instructor:         Kathyrn Rehfield
//
//  Description:
//      File contains implementation of Node class methods.
//
//********************************************************************

//**************************************************************
//
//  	Node constructor
//
//  Description:  called when Node object is created,
//					to initialize line & next class data attributes.
//
//  Parameters:   N/A
//
//  Returns:      N/A
//
//**************************************************************
Node::Node() { // initialize data attributes to null values

    line = "";
    next = nullptr;

}

//**************************************************************
//
//  Method: 	  Node getLine
//
//  Description:  accessor method that returns
//				the private class data attribute, line.
//
//  Parameters:   N/A
//
//  Returns:      numItems
//
//**************************************************************
string Node::getLine() {

    return line;
}

//**************************************************************
//
//  Method: 	  Node setLine
//
//  Description:  mutator method that sets
//				the private class data attribute, line.
//
//  Parameters:   N/A
//
//  Returns:      N/A
//
//**************************************************************
void Node::setLine(string line) {
    this->line = line;
}

//**************************************************************
//
//  Method: 	  Node getNext
//
//  Description:  accessor method that returns
//				the private class data attribute, next.
//
//  Parameters:   N/A
//
//  Returns:      next
//
//**************************************************************
shared_ptr<Node> Node::getNext() {
    return next;
}

//**************************************************************
//
//  Method: 	  Node setNext
//
//  Description:  mutator method that sets
//				the private class data attribute, next.
//
//  Parameters:   N/A
//
//  Returns:      N/A
//
//**************************************************************
void Node::setNext(Node* next) {
	shared_ptr<Node> temp(next);
    this->next = temp;
}

#include "linkedlist.cpp"