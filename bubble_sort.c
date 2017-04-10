#include <stdio.h>
 
void swap(int *num1, int *num2)
{
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
 
void bubbleSort_iterative(int arr[], int n)
{
   int i, j;
   int swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = 0;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = 1;
        }
     }
 
     // check if we swapped; If not swapped, then break
     if (swapped == 0)
        break;
   }
}


void bubbleSort_recurse(int arr[], int n)
{
    // exit case
    if (n == 1)
        return;
 
    // Move my heaviest element all the way down
	int i;
    for (i=0; i<n-1; i++)
        if (arr[i] > arr[i+1])
            swap( &arr[i], &arr[i+1]);
 
    // recur for remaining array
    bubbleSort_recurse(arr, n-1);
}
 
/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)    printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver program to test above functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Before: un-Sorted array: \n"); printArray(arr, n);
    bubbleSort_iterative(arr, n);
    printf("After :    Sorted array: \n"); printArray(arr, n);
    bubbleSort_recurse(arr, n);
    return 0;
}
