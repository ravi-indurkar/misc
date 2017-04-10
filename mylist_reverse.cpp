#include <list>
#include <cstdio>

using namespace std;

int main()
{


	list<int> mylist;

	mylist.push_back(30);
	mylist.push_back(60);
	mylist.push_back(50);
	mylist.push_back(70);
	mylist.push_back(40);
	mylist.push_back(80);

	int i=0, val=0;
	list<int>::iterator itr;

	for (i=0, itr = mylist.begin(); itr != mylist.end() != 0; i++, itr++ ) {
		val = *itr;
		printf("i=%d  val=%d\n", i, val);
	}

	mylist.reverse();

	printf("Reverse\n");
	for (i=0, itr = mylist.begin(); itr != mylist.end() != 0; i++, itr++ ) {
		val = *itr;
		printf("i=%d  val=%d\n", i, val);
	}

}

