
/**********************
 
./pre_post_inorder
Enter number of elements: 5
Enter number 0: 6
Enter number 1: 3
Enter number 2: 9
Enter number 3: 8
Enter number 4: 2
 2  3  6  8  9 
 6  3  2  9  8 
 9  8  6  3  2 

************************/


#include <stdio.h>
#include <stdlib.h>

typedef struct _mystr {
	int data;
	struct _mystr *right;
	struct _mystr *left;
} mystr_t;

void my_insert( mystr_t **entry, int val);
void my_print_inorder( mystr_t *entry);
void my_print_preorder( mystr_t *entry);
void my_print_postorder( mystr_t *entry);


int main ()
{

	mystr_t *head=NULL;

	printf("Enter number of elements: ");
	int num_entry;
	scanf("%d", &num_entry);

	int i, value;
	for (i=0; i<num_entry; i++) {
		printf("Enter number %d: ", i); 
		scanf("%d", &value);
		my_insert( &head, value);
	}

	my_print_preorder( head );
	printf("\n");
	my_print_inorder( head );
	printf("\n");
	my_print_postorder( head );
	printf("\n");

}

void my_insert( mystr_t **entry, int val)
{

	mystr_t *tmpentry;

	if ( *entry == NULL ) {	
		tmpentry = (mystr_t*)malloc( sizeof(mystr_t));
		*entry = tmpentry;
		tmpentry->data = val;
		tmpentry->right = NULL;
		tmpentry->left = NULL;
	} else {

		tmpentry = *entry;

		if ( tmpentry->data < val ) {
			my_insert( &tmpentry->right, val);
		} else if ( tmpentry->data > val ) {
			my_insert( &tmpentry->left, val);
		} else {
			printf("Duplicate value = %d\n", val);
		}
	}
}

void my_print_preorder( mystr_t *entry)
{
	if (entry->left) my_print_preorder(entry->left);
	printf(" %d ", entry->data);
	if (entry->right) my_print_preorder(entry->right);
}


void my_print_inorder( mystr_t *entry)
{
	printf(" %d ", entry->data);
	if (entry->left) my_print_inorder(entry->left);
	if (entry->right) my_print_inorder(entry->right);
}


void my_print_postorder( mystr_t *entry)
{
	if (entry->right) my_print_postorder(entry->right);
	printf(" %d ", entry->data);
	if (entry->left) my_print_postorder(entry->left);
}

