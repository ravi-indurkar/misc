#include <cstdio>

#include <algorithm> // needed for sort

using namespace std;
 
// Method prints possible triangle when array
// values are taken as sides
bool isPossibleTriangle(int arr[], int N)
{
    // If number of elements are less than 3,
    // then no triangle is possible
    if (N < 3)
      return false;
 
	printf("Before sort:\n");
    for (int i=0; i<N; i++) {
		printf("i=%d val=%d\n", i, arr[i]);
	}
	printf("\n");

    //  first sort the array
    sort(arr, arr + N);
 
	printf("After  sort:\n");
    for (int i=0; i<N; i++) {
		printf("i=%d val=%d\n", i, arr[i]);
	}
	printf("\n");

	// DO THE MAIN work
	
    //  loop for all 3 consecutive triplets
    for (int i=0; i<N-2; i++) {
 
        // If triplet satisfies triangle
        // condition, break
        if (arr[i] + arr[i+1] > arr[i+2])
            return true;
	}
}
 
//  Driver code to test above method
int main()
{
    int arr[] = {5, 4, 3, 1, 2};
    int N = sizeof(arr) / sizeof(int);
 
	if ( isPossibleTriangle(arr, N) ) printf("yes\n");
	else printf("No\n");
    return 0;
}
