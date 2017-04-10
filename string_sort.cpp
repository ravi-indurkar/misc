#include <cstdio> // cannot use printf due to "string" class
#include <iostream>
#include <string>
#include <vector>

#include <algorithm> // needed for sort

using namespace std;
 
 
int main()
{
	string s1 = "S1";
	string s2 = "S2";
	string s3;

	s3 = s1 + s2;

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;

	printf("============================\n");

	vector <string> string_array;
	string_array.push_back("aaa");
	string_array.push_back("xxx");
	string_array.push_back("zzz");
	string_array.push_back("abcd");
	string_array.push_back("abc");
	string_array.push_back("xyz");
	string_array.push_back("bbb");
	string_array.push_back("yyy");
	string_array.push_back("cccc");
	cout << string_array[0] << endl;
	cout << string_array[1] << endl;
	cout << string_array[2] << endl;

	int i;
	cout << "Before sorting\n";
	for (i=0; i<string_array.size(); i++) {
		cout << string_array[i] << endl;
	}


	i = string_array.size();
	sort( &string_array[0], &string_array[i] );


	cout << "After  sorting\n";
	for (i=0; i<string_array.size(); i++) {
		cout << string_array[i] << endl;
	}

    return 0;
}
