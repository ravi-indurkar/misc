#include <cstdio>
#include <cstdlib>

using namespace std;

class Entry_c {
public:
    Entry_c * next;
    int mydata;

    Entry_c( int a) : mydata(a), next(NULL) { }
};

class Head_c {
public:
    Entry_c *first;

    Head_c(void): first(NULL) { }
    Entry_c *generate_element( int inp_int);
    void insert( Entry_c *input_Entry);
    void print( );

};


Entry_c *Head_c::generate_element( int inp_int)
{
    Entry_c * pEntry;
    pEntry = new Entry_c(inp_int);
    return pEntry;
}

void Head_c::insert( Entry_c *input_Entry)
{

    Entry_c * curr_pEntry;

    if (first == NULL) {
        first = input_Entry;
    } else {
        int i;
        curr_pEntry = first;
        while (curr_pEntry->next) {
            curr_pEntry = curr_pEntry->next;
        }
        curr_pEntry->next = input_Entry;
    }

}

void Head_c::print( )
{
    Entry_c * curr_pEntry;
    curr_pEntry = first;
    printf("===============\n");
    while (curr_pEntry) {
        printf("mydata=%d\n", curr_pEntry->mydata);
        curr_pEntry = curr_pEntry->next;
    }
    printf("===============\n");
}

main()
{
    Head_c Head;
    Entry_c * pEntry;

    for (int i=1;i<5;i++) {
        pEntry = Head.generate_element( i );
        Head.insert( pEntry );
        Head.print();
    }
}


/* 

ca-bld-ol72-04: g++ -o x mylinklist.cc
ca-bld-ol72-04: ./x
===============
mydata=1
===============
===============
mydata=1
mydata=2
===============
===============
mydata=1
mydata=2
mydata=3
===============
===============
mydata=1
mydata=2
mydata=3
mydata=4
===============

*/


