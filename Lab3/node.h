//********************************************************************
//
//  Developer:          Erin Oefelein
//
//  Lab #:            	Three
//
//  File Name:          node.h
//
//  Course:             COSC-1337 Data Structures & Algorithms
//
//  Due Date:           5/2/2021
//
//  Instructor:         Kathyrn Rehfield
//
//  Description:
//      Specifies the data attributes and member functions of the Node class.
//
//********************************************************************
#ifndef NODE_H
#define NODE_H

#include <string>
#include <memory>

using namespace std;

class Node {

	private:
        string line; // stores each line read from file
        shared_ptr<Node> next; // stores pointer to next node
    public:
        Node(); // default constructor
        
        // line methods
        string getLine(); // accessor
        void setLine(string line); // mutator
        
        // next methods
        shared_ptr<Node> getNext(); // accessor
        void setNext(Node* nextPtr); // mutator

};

#include "linkedlist.h"

#endif