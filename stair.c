#include <stdio.h>

void print_stair( int x)
{

	int row, column, space;
	for (row=0; row<x; row++) {
		space = x-1-row;
		for (column=0; column<x; column++) {
			if ( column < space ) printf(" ");
			else printf("#");
		}
		printf("\n");
	}
	printf("\n");

}

int main()
{

	int inp;

	printf("Enter: "); scanf("%d", &inp);

	print_stair( inp);

}
