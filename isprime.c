#include <stdio.h>

int isPrime(int number)
{
		int i;
        for (i=2; i<number; i++) {
           if ( number%i == 0) {
               return 0; 
           }
        }
        return 1; 
}


int main()
{

	int x, inp, i;

	printf("Enter any number: "); scanf("%d", &inp);

	x = isPrime( inp);
	if ( x) printf("Prime\n");
	else printf("Not prime\n");

	printf("Printing all primes till this number\n");
	for (i=0; i<inp; i++ ) {
		x = isPrime( i);
		if ( x)  {
			printf("%d ", i);
		}
	}
	printf("\n");
}
