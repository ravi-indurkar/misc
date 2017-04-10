
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_ {
	int dataA;
	int dataB;
	int dataC;
	struct Node_ *next;
} Node ;

void insert_at_head( Node ** node, Node *insertnode)
{
	insertnode->next = *node;
	*node = insertnode;
}


Node * remove_from_head( Node ** node)
{
	if ( *node == NULL) return *node;

	Node *firstNode;
	firstNode = *node;

	*node = firstNode->next;
	firstNode->next = NULL;
	return( firstNode );
}

Node * reverse_by_insrem_head(Node ** node)
{
	if ( *node == NULL) return *node;

	Node *newhead = NULL;
	Node *tmpnode;

	while ( *node ) {
		tmpnode = remove_from_head( node);
		insert_at_head(&newhead, tmpnode);
	}

	return( newhead);
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

	printf("=====\n");
	head = reverse_by_insrem_head( &head);

	for (i=0, tmpnode = head; tmpnode != NULL; tmpnode = tmpnode->next, i++) {
		printf("i=%d addr=0x%x next=0x%x dataA=%d dataB=%d dataC=%d\n", i, tmpnode, 
					tmpnode->next, tmpnode->dataA, tmpnode->dataB, tmpnode->dataC);
	}
}


