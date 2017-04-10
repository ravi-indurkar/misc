#include <stdio.h>
     
int doreverse( int number) 
{
        int reverse_num = 0;
     
        while(number != 0){
          reverse_num = reverse_num*10 + number%10;
          number = number/10;
        }
             
        return reverse_num;
}


int isPalindrome(int number) 
{
        if (number == doreverse(number)){
            return 1;
        }
        return 0;
}
 

int main()
{

	int inp;

	printf("Enter: "); scanf("%d", &inp);

	if ( isPalindrome( inp) ) printf("Yes isPalindrome\n");
	else printf("No, Not isPalindrome\n");

}
