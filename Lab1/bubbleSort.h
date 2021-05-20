#ifndef BUBBLE_SORT_
#define BUBBLE_SORT_

#include "ArrayBag.h"
#include <string>

using std::string;

// void displayBag(ArrayBag &bag);
void bubbleSort(int arr[], size_t n);
void swapped(int &a, int &b);
int binarySearchRecur(const int anArray[], int first, int last, int target);

#endif