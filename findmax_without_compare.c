#include <stdio.h>


int findmax_without_compare( int x, int y)
{
   int z = x - y;
   int i  = (z  >>  31)  &  0x1;
   int  max  =  x - i  *  z;
   return max;
}

int main()
{

	int num1, num2;
	int val;

	printf("Enter num1: "); scanf("%d", &num1);
	printf("Enter num2: "); scanf("%d", &num2);

	val = findmax_without_compare( num1, num2);
	printf("Max is %d\n", val);
}
