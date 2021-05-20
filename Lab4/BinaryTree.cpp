//********************************************************************
//
//  Developer:          Erin Oefelein
//
//  Lab #:            	Four
//
//  File Name:          BinaryTree.cpp
//
//  Course:             COSC-1337 Data Structures & Algorithms
//
//  Due Date:           5/16/2021
//
//  Instructor:         Kathyrn Rehfield
//
//  Description:
//      File contains implementation of BinaryTree class methods.
//
//********************************************************************
#include <iostream>

using namespace std;

//***************************************************************
//
//  Method:       (iterative) search
// 
//  Description:  tells the user whether Employee ID was found in the tree or not
//
//  Parameters:   EmployeeInfo e
//
//  Returns:      N/A 
//
//**************************************************************
void BinaryTree::search(EmployeeInfo e)
{
    Node* temp = root;
    while(temp != NULL){
        if(temp->emp.id == e.id){ // if e.id is equal to temp, then node has been found
            cout << "Employee with ID " << e.id << " exists in the tree." << endl;
            return;
        }
        else if(temp->emp.id > e.id){ // if e.id is less than temp...
            temp = temp->left; // ... go left
        }
        else{ // if e.id is greater than temp...
            temp = temp->right; // ... go right
        }
    }
    cout << "Employee with ID " << e.id << " doesn't exist in the tree." << endl;
}
//***************************************************************
//
//  Method:       (recursive) displayImplementation
// 
//  Description:  implements display functionality
//
//  Parameters:   Node *start
//
//  Returns:      N/A 
//
//**************************************************************
void BinaryTree::displayImplementation(Node *temp)
{
    if (temp == NULL) // base case
    {
        return;
    }
    displayImplementation(temp->left); // if left node is not null
    cout << "ID: " << temp->emp.id << "\t Name: " << temp->emp.name << endl;
    displayImplementation(temp->right);// if right node is not null
}
//***************************************************************
//
//  Method:       display
// 
//  Description:  called from main to display the tree
//
//  Parameters:   N/A
//
//  Returns:      N/A 
//
//**************************************************************
void BinaryTree::display()
{
    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }
    cout << "\nDisplaying Binary Tree's Data i.e. Employee's ID and Name: \n" << endl;
    displayImplementation(root);
}
//***************************************************************
//
//  Method:       (recursive) insertImplementation
// 
//  Description:  implements insert functionality 
//          using temp to protect BinaryTree class member root from being changed.
//
//  Parameters:   Node *temp, EmployeeInfo e
//
//  Returns:      Node* temp 
//
//**************************************************************
Node* BinaryTree::insertImplementation(Node *temp, EmployeeInfo e)
{
    if (temp == NULL) // if the binary tree is empty...
    {
        Node *newNode = new Node(e);
        return newNode; // ...return a new EmployeeInfo Node
    }
    // else, recur down the binary tree
    else if (temp->emp.id > e.id) // if id is less than temp...
    {
        temp->left = insertImplementation(temp->left, e); // ... go left
    }
    else if (temp->emp.id < e.id) // if id is greater than temp...
    {
        temp->right = insertImplementation(temp->right, e); // ... go right
    }
    return temp;
}
//***************************************************************
//
//  Method:       insert
// 
//  Description:  called from main to insert EmployeeInfo Node to tree
//
//  Parameters:   EmployeeInfo e
//
//  Returns:      N/A 
//
//**************************************************************
void BinaryTree::insert(EmployeeInfo e)
{
    root = insertImplementation(root, e);
    cout << "\nEmployee Info Added to Binary Tree." << endl;
}
//***************************************************************
//
//  Method:       findInorderPre
// 
//  Description:  helper function to do inorder traversal of binary tree
//
//  Parameters:   Node *temp
//
//  Returns:      Node* temp 
//
//**************************************************************
Node* BinaryTree::findInorderPre(Node *temp)
{
    // loop down to find the rightmost leaf
    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}
//***************************************************************
//
//  Method:       remove
// 
//  Description:  called from main to remove EmployeeInfo Node from tree
//
//  Parameters:   int id
//
//  Returns:      N/A 
//
//**************************************************************
void BinaryTree::remove(int id)
{
    if (root == NULL)
    {
        cout << "Tree is empty." << endl;
        return;
    }
    root = removeImplementation(root, id);
}
//***************************************************************
//
//  Method:       (recurisve) removeImplementation
// 
//  Description:  implements remove functionality 
//          using temp to protect BinaryTree class member root from being changed.
//
//  Parameters:   Node *start, int id
//
//  Returns:      N/A 
//
//**************************************************************
Node* BinaryTree::removeImplementation(Node *temp, int id)
{
    if (temp == NULL)
    {
        cout << "Employee with ID " << id << " doesn't exist in the tree." << endl;
        return temp;
    }
    else if (temp->emp.id > id) // if id to be removed is smaller than temp's key...
    {
        temp->left = removeImplementation(temp->left, id); // ...then it lies in left subtree
    }
    else if (temp->emp.id < id) // if id to be removed is larger than temp's key...
    {
        temp->right = removeImplementation(temp->right, id); // ...then it lies in right subtree
    }
    else // if id is equal to temp, then it's the node to remove
    {
        cout << "\nEmployee with ID " << id <<" has been removed from the tree." << endl;
        if (temp->left == NULL && temp->right == NULL) // node has no child
        {
            delete temp;
            return NULL;
        }
        // node with only one child or no child
        else if (temp->left == NULL)
        {
            Node *del = temp;
            temp = temp->right;
            delete del;
            return temp;
        }
        else if (temp->right == NULL)
        {
            Node *del = temp;
            temp = temp->left;
            delete del;
            return temp;
        }
        else
        {
            Node* inorderPre = findInorderPre(temp->left);
            temp->emp = inorderPre->emp; // copy inorder successor's content to temp
            inorderPre->emp.id = id;
            temp->left = removeImplementation(temp->left, id); // delete inorder successor
            return temp;
        }
    }
    return temp;
}