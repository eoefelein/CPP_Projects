//********************************************************************
//
//  Developer:          Erin Oefelein
//
//  Lab #:            	Four
//
//  File Name:          BinaryTree.h
//
//  Course:             COSC-1337 Data Structures & Algorithms
//
//  Due Date:           5/16/2021
//
//  Instructor:         Kathyrn Rehfield
//
//  Description:
//      Specifies the data attributes and member functions of the BinaryTree class.
//
//********************************************************************
#ifndef BINARY_TREE_H
#define BINARY_TREE_H

class BinaryTree
{

private:
    // root to point to the root of the binary tree
    Node *root;

    /* 
    display function to display the contents of the binary tree
    by inorder traversal, so sorted by Employee ID
    */
    void displayImplementation(Node *temp);

    // insert function inserts the user input employee info
    Node* insertImplementation(Node *temp, EmployeeInfo e);

    // findInorderPre function returns inorder predecessor of the binary tree 
    Node* findInorderPre(Node *temp);

    // remove function to remove an Employee Info Node by emp.id
    Node* removeImplementation(Node *temp, int id);

public:
    // constructor to intialize BinaryTree data member
    BinaryTree()
    {
        root = NULL;
    }

    // main search function declaration
    void search(EmployeeInfo e);
    
    // main display function declaration
    void display();

    // main insert function declaration 
    void insert(EmployeeInfo e);

    // main remove function declaration 
    void remove(int id);
};

#include "BinaryTree.cpp"

#endif