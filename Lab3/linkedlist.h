//********************************************************************
//
//  Developer:          Erin Oefelein
//
//  Lab #:            	Three
//
//  File Name:          linkedlist.h
//
//  Course:             COSC-1337 Data Structures & Algorithms
//
//  Due Date:           5/2/2021
//
//  Instructor:         Kathyrn Rehfield
//
//  Description:
//      Specifies the data attributes and member functions of the LinkedList class.
//
//********************************************************************
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>

class LinkedList {
private:
	shared_ptr<Node> headPtr; // shared_ptr<Node> headPtr
	int numItems; // numItems class data attribute
public:
   LinkedList(); // constructor
   int getCurrentSize(); // accessor method to getCurrentSize

   // adds node with value passed to line variable
    void addNode(string line);
    
    // displays the list
    std::vector<string> toVector();
    // sort LinkedList
    void sortLinkedList();
    // sorts & removes duplicates before displaying the list
    std::vector<string> toSortedVectorNoDups();
//    void print(){



//    	Node* iter = headPtr.get(); // create pointer to iterate list

//        // iterate list until last node
//        while (iter != nullptr) {
//            cout<<iter->getLine()<<endl;
//            iter = iter->getNext().get();
//        }
//        // add node to end o
//    }
    ~LinkedList(); // destructor
};

#include "node.cpp"

#endif