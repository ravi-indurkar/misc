#include <cstdio>
#include <list>
#include <cstdlib> // for rand()

using namespace std;

class myclass {

public:
	int house_number;
	int zip;

	myclass() {
		house_number=0;
		zip=0;
	}

	myclass( int house_ , int zip_ ) {
		house_number = house_;
		zip = zip_;
	}

	void myprint(void) {
		printf("This=%x house_number=%d, zip=%d\n", this, house_number, zip);
	}
};

int main()
{

	list<myclass> list_myclass;
	list<myclass *> list_of_pointers_to_myclass;

	myclass myclass_var1(1,2);
	myclass_var1.myprint();

	myclass *myclass_ptr2;
	myclass_ptr2 = new  myclass(3,4);
	myclass_ptr2->myprint();

	list_myclass.push_back( *myclass_ptr2 );
	list_myclass.push_back( myclass_var1 );

    // variable "i" cannot be just a simple int, but a special "thing" of type "list"
	// int i;
	list<myclass>::iterator ii;
	int j;
	for (ii=list_myclass.begin(), j=0; ii!=list_myclass.end(); ii++, j++) {
		printf("j=%d list-addr=0x%x list-data*=%d list-data->%d %d\n", j, ii, *ii, ii->house_number, ii->zip);
		ii->myprint();
	}


	myclass_var1.house_number = rand();
	myclass_var1.zip = rand();
	myclass_ptr2->house_number = rand();
	myclass_ptr2->zip = rand();


	printf("======Second similar list, but this is list of Pointers =====================================\n");
	/*** second similar list, but this is list of Pointers ****/


	/* insert push few in front */
	list_of_pointers_to_myclass.push_back( &myclass_var1 );
	list_of_pointers_to_myclass.push_back( myclass_ptr2 );
	for (j=0; j<3; j++) {
		list_of_pointers_to_myclass.push_back( new myclass( 10000+j, 100+j ) );
	}
	/* insert push few in back */
	for (j=0; j<3; j++) {
		list_of_pointers_to_myclass.push_front( new myclass( 40000+j, 400+j ) );
	}

	/* print them */
	list<myclass *>::iterator kk;
	for (kk=list_of_pointers_to_myclass.begin(), j=0; kk!=list_of_pointers_to_myclass.end(); kk++, j++) {
		// printf("j=%d list-addr=0x%x list-data->%d %d\n", j, kk, kk->house_number, kk->zip);
		printf("j=%d list-addr=0x%x %x\n", j, kk, *kk );
		myclass *ptr;
		ptr = *kk;
		ptr->myprint();
	}

	printf("&myclass_var1=%x myclass_ptr2=%x\n", &myclass_var1, myclass_ptr2);

	printf("======traverse reverse using while-loop =====================================\n");
	/* if we have to traverse reverse, for-loop skips last (ie. first) element
    ** so we need to use do while 
	**/
	kk=list_of_pointers_to_myclass.end();
	j=0;
	do {
		kk--;
		printf("j=%d list-addr=0x%x %x\n", j, kk, *kk );
		myclass *ptr;
		ptr = *kk;
		ptr->myprint();
		j++;
	} while (kk!=list_of_pointers_to_myclass.begin() );

	printf("======traverse reverse using for-loop =====================================\n");
	for (kk=list_of_pointers_to_myclass.end(), j=0; kk!=list_of_pointers_to_myclass.begin(); kk--, j++) {
		printf("j=%d list-addr=0x%x %x\n", j, kk, *kk );
		myclass *ptr;
		ptr = *kk;
		ptr->myprint();
	}


}


