#include <cstdio>

using namespace std;

class Queue_entry {
public:
	Queue_entry *prev;
	Queue_entry *next;
};

class Queue {
public:
	Queue_entry *first;
	Queue_entry *last;
};

class data_t {
public:
	int data_t_int;
	char data_t_char;
	int data_t_int2;
};

// class mytest_t : Queue_entry, data_t 
class mytest_t : public data_t, public Queue_entry
	{
public:
	int mytest_t_intabc;
	char mytest_t_mychar;
	char * mytest_t_mycharptr;
	int mytest_t_intxyz;
};

main() 
{
	class mytest_t mytest;

	mytest.prev = (Queue_entry*)0x1234;
	mytest.next = (Queue_entry*)0x5678;

	mytest.data_t_int = 0x11;
	mytest.data_t_char = 0x22;
	mytest.data_t_int2 = 0x33;

	mytest.mytest_t_intabc = 0xaa;
	mytest.mytest_t_mychar = 0x44;
	mytest.mytest_t_mycharptr = (char *)0xcc;
	mytest.mytest_t_intxyz = 0xdd;

	printf("&mytest=0x%lx  &queue=0x%lx &data_t=0x%lx &mytest_t_intabc=0x%lx \n", &mytest, &mytest.prev, &mytest.data_t_int, &mytest.mytest_t_intabc );

	printf("\n");

	
}

/*
g++ -o x myclassoffset.cc
./x
&mytest=0x7fff1e1622e0  &queue=0x7fff1e1622f0 &data_t=0x7fff1e1622e0 &mytest_t_intabc=0x7fff1e162300 

*/

