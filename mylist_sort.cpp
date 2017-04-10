#include <list>
#include <cstdio>
#include <cstdlib> // needed for rand()

using namespace std;

int main()
{

	list<int> int_list;


	int j;
	/* put few in back */
	for (j=0; j<5; j++) {
		int_list.push_back( rand());
	}
	/* put few in front */
	for (j=0; j<5; j++) {
		int_list.push_front( rand());
	}


	// variable "i" cannot be just a simple int, but a special "thing" of type "list"
	// int i;
	list<int>::iterator i;
	printf("Print original\n");
	for (i=int_list.begin(), j=0; i!=int_list.end(); i++) {
		printf("j=%d list-addr=0x%x list-data=%d \n", j, i, *i);
	}


	printf("Print sorted\n");
	int_list.sort();
	for (i=int_list.begin(), j=0; i!=int_list.end(); i++) {
		printf("j=%d list-addr=0x%x list-data=%d \n", j, i, *i);
	}


	printf("Print after reversal\n");
	int_list.reverse();
	for (i=int_list.begin(), j=0; i!=int_list.end(); i++) {
		printf("j=%d list-addr=0x%x list-data=%d \n", j, i, *i);
	}

}


