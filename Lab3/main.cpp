//********************************************************************
//
//  Developer:          Erin Oefelein
//
//  Lab #:            	Three
//
//  File Name:          main.cpp
//
//  Course:             COSC-1337 Data Structures & Algorithms
//
//  Due Date:           5/2/2021
//
//  Instructor:         Kathyrn Rehfield
//
//  Description:
//      Program:
//			1) Takes file name as input from user
//			2) Displays the lines from the file,
//					using the class method toVector
//				& displays the number of lines in the vector
//			4) Displays the lines from the file,
//					in sorted order, with no duplicates,
//					using the class method toSortedVectorNoDups
//				 & displays the number of lines that were in the vector
//
//********************************************************************
#include <fstream>

#include "node.h"
#include "linkedlist.h"

using namespace std;

int main() {
   // create linkedlist to represent list data within the program
   LinkedList list;
   string filename = "";

   cout << "Please provide the name of the file you wish to read: ";
   cin >> filename;

   // read from file
   ifstream file(filename);

   // check if the file can be opened
   if (file.is_open()) {

	   string line;

	   while (!file.eof()) { // until end of file is reached...
           
           getline(file, line); // ...read file line by line
           // add line to list
           list.addNode(line);

       }

       cout<<"\n"<<list.getCurrentSize()<<" lines were read from the file and stored to the LinkedList."<<endl;
       cout<<endl;
       // print file content
       cout << "File " << filename << " contains lines:\n" << endl;

       // display contents of LinkedList
       std::vector<string> file_contents = list.toVector();
       for (int i=0; i<list.getCurrentSize(); i ++)
       {
    	   cout << file_contents[i] << endl;
       }
       
       // remove duplicates from list and sort in ascending order & display contents of LinkedList
       std::vector<string> sorted_file_contents = list.toSortedVectorNoDups();
       // print final result
       cout << "\nAfter sorting and removing duplicates, the LinkedList contains " <<sorted_file_contents.size()<<" lines."<<endl;
       cout<<endl;
       cout << "All lines now stored to the cleaned and sorted LinkedList include:\n" << endl;
       for (int i=0; i<sorted_file_contents.size(); i ++)
       {
    	   cout << sorted_file_contents[i] << endl;
       }
        
   }
   else {
       // print error message
       cout << "Could not open file: " << filename << endl;
   }

   return 0;
}