//********************************************************************
//
//  Developer:          Erin Oefelein
//
//  Lab #:            	Four
//
//  File Name:          main.cpp
//
//  Course:             COSC-1337 Data Structures & Algorithms
//
//  Due Date:           5/16/2021
//
//  Instructor:         Kathyrn Rehfield
//
//  Description:
//      Program:
//			1) Displays menu of options available to the user
//          2) Takes option as input from the user
//			3) Pending user input, program will:
//					add, remove, search or display the BinaryTree.
//			4) User may run the program until option 5 is selected.
//********************************************************************
#include "EmployeeInfo.h"
#include "Node.h"
#include "BinaryTree.h"

int main()
{
    // declare BinaryTree object as 'binarytree'
    BinaryTree binarytree;

    // option to store user input
    int option;

    // id for employee id
    int id;
    // name for employee name
    string name;

    while (true) // loop terminates when user enters 5
    { 
        // menu
        cout << "\n1. Add New Employee to the Binary Tree.";
        cout << "\n2. Remove Employee by Employee ID.";
        cout << "\n3. Display Binary Tree.";
        cout << "\n4. Search Employee by Employee ID.";
        cout << "\n5. Exit the program.";
        cout << "\n\nEnter your option: ";
        // take user input and store to option
        cin >> option;

        // option 1 adds new employee info to the binary tree
        if(option==1){
            cout<<"\nEnter Employee ID: ";
            // take user input and store to id
            cin >> id;
            cout << "\nEnter Employee name: ";
            // take user input and store to name
            cin >> name;

            // declare emp obj of EmployeeInfo class
            EmployeeInfo emp;
            // id and name assigned to emp
            emp.id = id;
            emp.name = name;

            // call to binarytree's insert function
            binarytree.insert(emp);
        }
        // option 2 removes employee by ID
        else if(option==2){
            cout << "\nEnter Employee ID to remove: ";
            cin >> id;
            // call to binarytree's remove function
            binarytree.remove(id);
        }
        // option 3 displays binarytree's data
        else if(option==3){
            // call to binarytree's display function
            binarytree.display();
        }
        // option 4 displays binarytree's data
        else if(option==4){
            cout << "\nEnter Employee ID to search: ";
            // take user input and store to id
            cin >> id;

            // declare emp obj of EmployeeInfo class
            EmployeeInfo emp;
            // id assigned to emp
            emp.id = id;

            // call binarytree's search function
            binarytree.search(emp);
        }
        // option 5 allows user to exit program
        else if(option==5){
            // program terminates with exit function 
            exit(0);
        }
        // should the user enter an invalid input...
        else{
            cout << "\nError! Enter correct option.";
        }
    }
    return 0;
}