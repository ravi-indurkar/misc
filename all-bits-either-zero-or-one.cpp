#include <cstdio>

using namespace std;

class myclass {

public:
	void myfunc( void);

};


void myclass::myfunc(void)
{
	int i;
	long long inputvar=0;
	int answer=0;
	printf("Code to see if ALL bit from bit45 thru bit50 are either all 0 or all 1 \n");
	printf("Enter Hex: ");
	scanf("%llx", &inputvar);
	printf("inputvar=%llx\n", inputvar);

	if ( (inputvar & 0x0007e00000000000) == 0x0007e00000000000 ) {
		printf("set\n");
	} else {
		printf("Not set\n");
	}


	printf("==================================================\n");
	printf("Code to see if ALL bit from bit3, bit4, bit5 are either all 0 or all 1 \n");
	answer =  inputvar & 0x3C ;
	if ((  (inputvar & 0x3C) == 0x3C) || ( (inputvar & 0x3C) == 0  ) ) {
		printf("set\n");
	} else {
		printf("Not set\n");
	}

}

int main()
{

	myclass myvar;

	myvar.myfunc();


}

