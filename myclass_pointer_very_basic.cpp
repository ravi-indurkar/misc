#include <cstdio>

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

	myclass myclass_var;
	myclass_var.myprint();

	myclass *myclass_ptr;
	myclass_ptr = &myclass_var;
	myclass_ptr->myprint();

	myclass myclass_var1(1,2);
	myclass_var1.myprint();

	myclass *myclass_ptr1;
	myclass_ptr1 = new (myclass);
	myclass_ptr1->myprint();

	myclass *myclass_ptr2;
	myclass_ptr2 = new  myclass(3,4);
	myclass_ptr2->myprint();

}


