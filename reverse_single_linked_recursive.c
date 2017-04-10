
#include <stdio.h>
#include <stdlib.h>

typedef struct Node_ {
	int dataA;
	int dataB;
	int dataC;
	struct Node_ *next;
} Node ;


Node * reverse_list_recurse(Node * node)
{
	if ( node == NULL) return node;

	if ( node->next == NULL) {
		return node;
	} else {
		Node *tmpNode = reverse_list_recurse( node->next);
		node->next->next = node;
		node->next = NULL;
		return tmpNode;
	}
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

	head = reverse_list_recurse( head);

	for (i=0, tmpnode = head; tmpnode != NULL; tmpnode = tmpnode->next, i++) {
		printf("i=%d addr=0x%x next=0x%x dataA=%d dataB=%d dataC=%d\n", i, tmpnode, 
					tmpnode->next, tmpnode->dataA, tmpnode->dataB, tmpnode->dataC);
	}
}


