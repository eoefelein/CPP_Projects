//********************************************************************
//
//  Developer:          Erin Oefelein
//
//  Lab #:            	Four
//
//  File Name:          Node.h
//
//  Course:             COSC-1337 Data Structures & Algorithms
//
//  Due Date:           5/16/2021
//
//  Instructor:         Kathyrn Rehfield
//
//  Description:
//      Specifies the data attributes and member functions of the Node class.
//
//********************************************************************
#ifndef NODE_H
#define NODE_H

class Node
{
// public members
public:
    // EmployeeInfo obj
    EmployeeInfo emp;
    // pointers to point to another node in the binary tree
    Node* left; // left pointer
    Node* right; // right pointer

    // constructor to intialize Node data members
    Node(EmployeeInfo e){
    // initialize EmployeeInfo
    emp.id = e.id;
    emp.name = e.name;
    // initialize left and right pointers to NULL
    left = right = NULL;
    };
};

#include "BinaryTree.h"

#endif