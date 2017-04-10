#include <vector>
#include <cstdio>

using namespace std;

int main()
{

	vector<int> int_array;

	int i;

	printf("size=%d capa=%d\n", int_array.size(), int_array.capacity());
	for (i=0; i<10; i++) {
		int_array.push_back(i+1);
	}

	for (i=0; i<10; i++) {
		printf("i=%d array=%d\n", i, int_array[i]);
	}

	printf("size=%d capa=%d\n", int_array.size(), int_array.capacity());

}


