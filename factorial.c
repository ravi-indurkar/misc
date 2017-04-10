#include <stdio.h>
 
int factorial_iter( int x )
{
  int i, fact = 1;
 
  for (i = 1; i <= x; i++)
    fact = fact * i;

  return fact;
}


int factorial_recurse(int n)
{
    if (n >= 1)
        return n * factorial_recurse(n-1);
    else
        return 1;
}


int main()
{
    int n;
    printf("Enter a positive integer: ");
    scanf("%d", &n);
    printf("Factorial method 1. Iter  %d = %d\n", n, factorial_iter( n ));
    printf("Factorial method 2. Recur %d = %d\n", n, factorial_recurse( n ));
    return 0;
}

