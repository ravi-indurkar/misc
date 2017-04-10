#include <stdio.h>

int fibo_sum( int inp)
{

	if (inp==0) return 0;
	if (inp==1) return 1;
	return ( fibo_sum(inp-1)  + fibo_sum(inp-2) );
}


void fibo_print_series( int inp)
{
	int sum_to_print, tmp;

	if (inp == 0) {
		printf("0 ");
		return;
	}
	if (inp == 1) {
		printf("1 ");
		return;
	}
	for (tmp=0; tmp<=inp; tmp++ ) {
		sum_to_print = fibo_sum( tmp );
		printf("%d ", sum_to_print);
	}
}

int main()
{

	int inp, answer;

	printf("Enter: "); scanf("%d", &inp);

	answer = fibo_sum(inp);
	printf("Fibo-sum: %d\n", answer);


	fibo_print_series( inp);
	printf("\n");

}
