#include <cstdio> 
#include <iostream>
#include <vector>

#include <algorithm> // needed for sort

using namespace std;
 
 
int main()
{
	printf("============================\n");

	vector <int> int_array;
	int_array.push_back(22);
	int_array.push_back(99);
	int_array.push_back(3);
	int_array.push_back(58);
	int_array.push_back(68);
	cout << int_array[0] << endl;
	cout << int_array[1] << endl;
	cout << int_array[2] << endl;

	int i;
	cout << "Before sorting\n";
	for (i=0; i<int_array.size(); i++) {
		cout << int_array[i] << endl;
	}


	i = int_array.size();
	sort( &int_array[0], &int_array[i] );


	cout << "After  sorting\n";
	for (i=0; i<int_array.size(); i++) {
		cout << int_array[i] << endl;
	}

    return 0;
}
