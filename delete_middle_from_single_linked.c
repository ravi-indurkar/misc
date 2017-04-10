
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_ {
	int dataA;
	int dataB;
	int dataC;
	struct Node_ *next;
} Node ;


// Cleaver algo; Instead of deleting this_node_to_delete; Just copy the
// contents of the nextNode and delete the nextNode
void delete_middle_node(Node * node_to_delete)
{

    if ( node_to_delete == NULL)
        return ;

	// before copying, we need to remember the addr of nextNode for deleteing nextNode
	Node *save_addr_of_nextNode_and_delete; 
	save_addr_of_nextNode_and_delete = node_to_delete->next;

	// before deleting next node, just simply copy from next into this
	*node_to_delete = *save_addr_of_nextNode_and_delete;
	free( save_addr_of_nextNode_and_delete );
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
	for (i=0, tmpnode = head; tmpnode != NULL; tmpnode = tmpnode->next, i++) {
		printf("i=%d addr=0x%x next=0x%x dataA=%d dataB=%d dataC=%d\n", i, tmpnode, 
					tmpnode->next, tmpnode->dataA, tmpnode->dataB, tmpnode->dataC);
	}

	for (i=0, tmpnode = head; tmpnode != NULL; tmpnode = tmpnode->next, i++) {
		if ( i == 2 ) {
			printf("delete i=%d addr=0x%x\n", i, tmpnode);
			delete_middle_node( tmpnode );
		}
	}
	for (i=0, tmpnode = head; tmpnode != NULL; tmpnode = tmpnode->next, i++) {
		printf("i=%d addr=0x%x next=0x%x dataA=%d dataB=%d dataC=%d\n", i, tmpnode, 
					tmpnode->next, tmpnode->dataA, tmpnode->dataB, tmpnode->dataC);
	}
}


