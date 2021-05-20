#include "bubbleSort.h"

#include <iostream>
#include <vector>
#include <string>

using std::cout; using std::endl; using std::vector; using std::string; using std::swap;

/****************************************************************************/ 
/* Function:   displayBag 
/* Inputs:     ArrayBag obj, represents a bag of items 
/* Outputs:    contents of bag are output to console 
/* Purpose:    
/****************************************************************************/ 
// void displayBag(ArrayBag &bag)
// {
//     cout << "The bag contains " << bag.getCurrentSize() << " items." << endl;
//     vector string bagItems = bag.toVector();

//     int numItems = (int)bagItems.size();
//     for (int i=0; i < numItems; i++)
//     {
//         cout << bagItems[i] << " ";
//     }

// }
/****************************************************************************/ 
/* Function:    bubbleSort
/* Inputs:      n = num of elements in arr
                arr = arr to be sorted
/* Outputs:     outputs sorted arr to console 
/* Purpose:     This function blah blah blah….. describing what 
/*                     the function does 
/****************************************************************************/ 
void bubbleSort(int arr[], size_t n)
{
    int i,j;
    for(i=0; i < n; i++)
    {   
        for(j=0; j < (n-i-1); j++)
        {
            if (arr[j] > arr[j+1])
            {
                {
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
}
/****************************************************************************/ 
/* Function:   functionName 
/* Inputs:       parameters passed and what they represent 
/* Outputs:    value(s) returned via return statemen or 
/*                     on the parameter list 
/* Purpose:    This function blah blah blah….. describing what 
/*                     the function does 
/****************************************************************************/ 
int binarySearchRecur(const int anArray[], int first, int last, int target)
{
   int idx = 0;
   if (first > last)
   idx = -1;
   else{
      int mid = first +  (last- first)/2;
      if (target == anArray[mid])
      {idx=mid;}
      else if (target < anArray[mid])
      {idx=binarySearchRecur(anArray, first, mid-1, target);}
      else
      {idx = binarySearchRecur(anArray, mid+1, last, target);}
   }
   return idx;
}