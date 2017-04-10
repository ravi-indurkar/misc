#include <cstdio> 
#include <iostream>
#include <vector>

#include <algorithm> // needed for sort

using namespace std;
 
 
int main()
{
	printf("============================\n");

	vector <long int> long_int_array;
	long_int_array.push_back(22);
	long_int_array.push_back(99);
	long_int_array.push_back(3);
	long_int_array.push_back(58);
	long_int_array.push_back(68);
	cout << long_int_array[0] << endl;
	cout << long_int_array[1] << endl;
	cout << long_int_array[2] << endl;

	int i;
	cout << "Before sorting\n";
	for (i=0; i<long_int_array.size(); i++) {
		cout << long_int_array[i] << endl;
	}


	i = long_int_array.size();
	sort( &long_int_array[0], &long_int_array[i] );


	cout << "After  sorting\n";
	for (i=0; i<long_int_array.size(); i++) {
		cout << long_int_array[i] << endl;
	}

    return 0;
}
