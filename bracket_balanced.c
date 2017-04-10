#include <stdio.h>
#include <string.h>


int main ()
{


	char buffer[100];
	char *ch;
	int i;
	int brace_count=0;
	int squarebracket_count=0;

	printf("Enter: "); scanf("%s", buffer);

 	ch = buffer;

	for (i=0; i<strlen(buffer); i++) {

		if (ch[i] == '(') {
			brace_count++;
		}
		if (ch[i] == ')') {
			brace_count--;
			if (brace_count <0 ) {
				printf("Error\n"); 
				break;
			}

		}
	}
	if ( brace_count == 0 ) printf("Brace Balanced\n");
	else printf("Brace Unbalanced\n");


}


