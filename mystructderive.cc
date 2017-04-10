#include <cstdio>

using namespace std;

struct Queue {
	struct Queue_entry *first;
	struct Queue_entry *last;
};


struct Queue_entry {
	struct Queue_entry *prev;
	struct Queue_entry *next;
};

struct data_t {
	int data_t_int;
	char data_t_char;
	int data_t_int2;
};

// struct mytest_t : Queue_entry, data_t 
struct mytest_t : data_t, Queue_entry
	{
	int mytest_t_intabc;
	char mytest_t_mychar;
	char * mytest_t_mycharptr;
	int mytest_t_intxyz;
};

main() 
{

	struct mytest_t mytest;

	mytest.prev = (struct Queue_entry*)0x1234;
	mytest.next = (struct Queue_entry*)0x5678;

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

