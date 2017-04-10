
#include <stdio.h>


typedef struct Node_ {
	int dataA;
	int dataB;
	int dataC;
	struct Node_ *next;
} Node ;


Node * FindnthToLast(Node * head, int n)
{

    if (n < 1 || head == null)
        return null;

	// start both at head
    Node *prev_ptr=head, *curr_ptr = head;

	//advance curr_ptr by n-1 nodes;    
    for (int i = 0; i < n - 1; ++i) {

        if (curr_ptr == null) {
            /* error, the linked list is less than n nodes long, */
            return null;
        }
        else                    //go to the next node
            curr_ptr = curr_ptr->next;
    }

	/* keep going until you hit a null node,
  	and then you've reached the end, and
  	prev_ptr will be pointing to the nth from
 	last node
	*/

    while (curr_ptr->next != null) {
        prev_ptr = prev_ptr->next;
        curr_ptr = curr_ptr->next;
    }

    return prev_ptr;

}


Node * newNode( int data)
{
	Node * newnode = malloc(sizeof(Node));
	newnode->dataA = data;
	newnode->dataB = data * 10;
	newnode->dataC = data * 100;
	newnode->next = NULL;
	return newnode;
}

int main()
{

	Node * head = NULL;

	head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);

	int i;
	Node *tmpnode;
	printf("before\n");
	for (i=0, tmpnode = head; tmpnode != NULL; tmpnode = tmpnode->next, i++) {
		printf("i=%d addr=0x%x next=0x%x dataA=%d dataB=%d dataC=%d\n", i, tmpnode, 
					tmpnode->next, tmpnode->dataA, tmpnode->dataB, tmpnode->dataC);
	}

	FindnthToLast();

	printf("after\n");
	for (i=0, tmpnode = head; tmpnode != NULL; tmpnode = tmpnode->next, i++) {
		printf("i=%d addr=0x%x next=0x%x dataA=%d dataB=%d dataC=%d\n", i, tmpnode, 
					tmpnode->next, tmpnode->dataA, tmpnode->dataB, tmpnode->dataC);
	}
}


