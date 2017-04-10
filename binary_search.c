#include <stdio.h>

int binarySearch_iter(int arr[], int low, int high, int x)
{
  int mid;
  while (low <= high)
  {
    mid = low + ( (high-low)/2 );
 
    // Check if x is present at mid
    if (arr[mid] == x) 
        return mid;  
 
    // If x greater, ignore left half  
    if (arr[mid] < x) 
        low = mid + 1; 
 
    // If x is smaller, ignore right half 
    else
         high = mid - 1; 
  }
 
  // if we reach here, then element was not present
  return -1; 
}


int binarySearch_with_recur(int arr[], int low, int high, int x)
{
   int mid;
   if (high >= low)
   {
    	mid = low + ( (high-low)/2 );
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch_with_recur(arr, low, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch_with_recur(arr, mid+1, high, x);
   }
 
   // We reach here when element is not present in array
   return -1;
}
 
int main(void)
{
   int arr[] = {2, 3, 4, 10, 40};
   int n = sizeof(arr)/ sizeof(arr[0]);
   int x = 10;
   printf("Recursive\n");
   int result = binarySearch_with_recur(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array\n")
                 : printf("Element is present at index %d\n", result);


   x = 3;
   printf("Standard  non-recurs\n");
   result = binarySearch_iter(arr, 0, n-1, x);
   (result == -1)? printf("Element is not present in array\n")
                 : printf("Element is present at index %d\n", result);
   return 0;
}
