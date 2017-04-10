#include <stdio.h>

int isAnagram(char *a, char *b, int len)
{
	int i;
	int true_len = len-1; // ignore the last NULL;

	for (i=0; i<len; i++ ) {
		if ( a[i] != b[true_len - 1  - i] ) return 0;
	}
	return 1;
}


int main()
{

	int x;

	x = isAnagram( "abc", "cba", sizeof("abc"));
	if ( x) printf("Yes\n");
	else printf("No\n");

	x = isAnagram( "Abc", "cba", sizeof("abc"));
	if ( x) printf("Yes\n");
	else printf("No\n");
}
