#include <stdio.h>
#include <stdlib.h>
 
typedef struct Node_ {
	int data;
	struct Node_ *left;
	struct Node_ *right;
} Node ;

 
void print_preorder(Node *node)
{
    if (node == NULL) return;

    if (node->left) print_preorder(node->left);
    printf("%d ", node->data);
    if (node->right) print_preorder(node->right);
}

/**
void insert_node(Node **node, int data)
{

    if (*node == NULL ) {
        // node = newNode( data);
    }
    
}
*/

Node **find_leaf_node(Node **AddrOfnode)
{
	Node *node;
	node = *AddrOfnode;

	if ( (node->left == NULL) && (node->right== NULL)) {
		// we found the leaf
		return( AddrOfnode);
	}
	if (node->left) {
		return ( find_leaf_node( &node->left));
	} else {
		return ( find_leaf_node( &node->right));
	}
	return ( AddrOfnode );
}

void delete_node( Node **node)
{

	Node *node_to_remove;
	node_to_remove = *node;

	printf("deleting %d\n", node_to_remove->data);

	if (node_to_remove == NULL) return;

	/* is this a leaf node, simplest case */
	if ((node_to_remove->left==NULL) && (node_to_remove->right==NULL)) {
		*node = NULL;
		free (node_to_remove);
		return;
	}
	/* this is middle node but with only one child; still relatively easy case */
	if (((node_to_remove->left==NULL) && (node_to_remove->right!=NULL))  ||
		((node_to_remove->left!=NULL) && (node_to_remove->right==NULL)))
	{
		Node *nextNode;
		if ( node_to_remove->left  != NULL) nextNode = node_to_remove->left;
		if ( node_to_remove->right != NULL) nextNode = node_to_remove->right;
		*node = nextNode;
		free (node_to_remove);
		return;
	}
	/* this is middle node containing both children, most difficult case */
	if ((node_to_remove->left!=NULL) && (node_to_remove->right!=NULL)) {
		Node **addrleafNode;
		addrleafNode = find_leaf_node( &node_to_remove->left);
		Node *leafnode;
		leafnode = *addrleafNode;

		/* copy data; and simply delete leafnode */
		node_to_remove->data = leafnode->data;
		free( leafnode);
		*addrleafNode = NULL;
	}
}

Node * newNode( int data)
{
	Node * newnode = malloc(sizeof(Node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int main() 
{
    /* Constructed skewed binary tree is
                100
               /
              80
             / \
            70  90
           /    / \
          60   92  95
         /          \
        50           97
        
        */
    Node* root = NULL;
 
    // alternate style   insert_node( &root, 100);

    root = newNode(100);
    root->left = newNode(80);
    root->left->left = newNode(70);
    root->left->right = newNode(90);
    root->left->right->left = newNode(92);
    root->left->right->right = newNode(95);
    root->left->right->right->right = newNode(97);
    root->left->left->left = newNode(60);
    root->left->left->left->left = newNode(50);

    printf("preorder: "); print_preorder(root); printf("\n");

	// delete_node (&root->left); // 80
	// delete_node (&root->left->right); // 90
	// delete_node (&root->left->left->left); // 60
	delete_node (&root->left->right->right); // 95


    printf("preorder: "); print_preorder(root); printf("\n");
 
    return 0;
}
