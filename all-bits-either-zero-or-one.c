#include <stdio.h>

int main()
{
	int i;
	long long inputvar=0;
	int answer=0;
	printf("Code to see if ALL bit from bit45 thru bit50 are either all 0 or all 1 \n");
	printf("Enter Hex: ");
	scanf("%llx", &inputvar);
	printf("inputvar=%llx\n", inputvar);

	/* we have to check for all 111111   and all 000000 */

	/* check all 111111 */
	if ( (inputvar & 0x0007e00000000000) == 0x0007e00000000000 ) {
		printf("all bits are all 11111\n");
	} else {
		printf("all bits are not 111111\n");
	}
	/* check all 000000 */
	if ( (inputvar & 0x0007e00000000000) == 0 ) {
		printf("all bits are all 00000\n");
	} else {
		printf("all bits are not 00000\n");
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


