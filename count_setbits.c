#include <stdio.h>

int main()
{

	int input_val, bit_count;

	printf("Enter hex number: "); scanf("%x", &input_val);

	while (input_val) {


		if (input_val & 0x1 ) bit_count++;


		input_val = input_val >> 1;

	}

	printf("Set bit cound = %d\n", bit_count );

}
