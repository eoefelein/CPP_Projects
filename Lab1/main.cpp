#include "bubbleSort.h"
#include "bubbleSort.cpp"
#include "ArrayBag.h"

#include <iostream>

using std::cout; using std::endl;

int main() 
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    //int arr[] = {1,5,3,8,7,4,9,2,6};
    size_t n = sizeof (arr) / sizeof (int); 
    cout << "The array has " << n << " elements." << endl;
    bubbleSort(arr, n);
    printf("Sorted array: \n");
    for (int i=0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int x = 90;

    // target is there
    int result1 = binarySearchRecur(arr, 0, n-1, x);
    (result1 == -1) ? cout << "Element is not present in the array" // when element is not present
                   : cout << "Element is present at index " << result1;
    x = 20;
    cout << endl;
    // target is not there
    int result2 = binarySearchRecur(arr, 0, n-1, x);
    (result2 == -1) ? cout << "Element is not present in the array"
                   : cout << "Element is present at index " << result2;

    return 0; 
} 