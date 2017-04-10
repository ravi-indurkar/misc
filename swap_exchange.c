#include <stdio.h>

swap_using_add( int a, int b)
{
	printf("%s\n", __FUNCTION__);
	printf("Before a=%d b=%d\n", a, b);
	a = a+ b; 
	b = a -b;
	a = a -b;
	printf("After  a=%d b=%d\n", a, b);
}

AVOID_BAD_swap_using_muldiv( int a, int b)
{
	printf("%s\n", __FUNCTION__);
	printf("Before a=%d b=%d\n", a, b);
	a = a*b; 
	b = a/b; 
	a = a/b;
	printf("After  a=%d b=%d\n", a, b);
}

swap_using_xor( int a, int b)
{
	printf("%s\n", __FUNCTION__);
	printf("Before a=%d b=%d\n", a, b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("After  a=%d b=%d\n", a, b);
}

int main()
{

	int a,b;
	printf("Enter a: "); scanf("%d", &a);
	printf("Enter b: "); scanf("%d", &b);
	swap_using_add( a, b);
	AVOID_BAD_swap_using_muldiv( a, b);
	swap_using_xor( a, b);
}
