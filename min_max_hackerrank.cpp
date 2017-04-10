#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // needed for sort

using namespace std;
 

void min_max(long int a, long int b, long int c, long int d, long int e)
{
    vector<long int> numbers;
    vector<long int> sums;
    long int total_sum;
	int i;

    numbers.push_back(a);
    numbers.push_back(b);
    numbers.push_back(c);
    numbers.push_back(d);
    numbers.push_back(e);

    total_sum = a+b+c+d+e;
	printf("Tot-sum=%d\n", total_sum);

	printf("sums:\n");
    for (i=0; i<5; i++) {
        // sums[i] = total_sum - numbers[i];
		sums.push_back( total_sum - numbers[i] );
		printf("i=%d num=%d sum=%d\n", i, numbers[i], sums[i]);
    }

	i = sums.size();
	sort( &sums[0], &sums[i] );

	printf("after sort:\n");
    for (i=0; i<5; i++) {
        // sums[i] = total_sum - numbers[i];
		sums.push_back( total_sum - numbers[i] );
		printf("i=%d num=%d sum=%d\n", i, numbers[i], sums[i]);
    }

	printf("%d %d\n", sums[0], sums[4]);
	cout <<sums[0]<<" "<<sums[4]<<endl;
}

 
int main()
{
	min_max( 1,2,3,4,5);
    return 0;
}
