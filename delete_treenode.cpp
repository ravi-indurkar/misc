// C++ program to print the tree
#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    Node* left,  *right;
};
 
 
// Utility function to create a new node
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void print_preorder(Node *node)
{
    if (node == NULL) return;

    if (node->left) print_preorder(node->left);
    printf("%d ", node->data);
    if (node->right) print_preorder(node->right);
}

void insert_node(Node **node, int data)
{

    if (*node == NULL ) {
        node = newNode( data);
    }
    
}

void delete_node( Node *node)
{
}

Node *find_leaf_node(Node *node)
{
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
 
    /*
    alternate style
    Node* root = newNode(100);
    root->left = newNode(80);
    root->left->left = newNode(70);
    root->left->right = newNode(90);
    root->left->right->left = newNode(92);
    root->left->right->right = newNode(95);
    root->left->right->right->right = newNode(97);
    root->left->left->left = newNode(60);
    root->left->left->left->left = newNode(50);
    *******/

    Node* root = NULL;

    insert_node( &root, 100);

 
    printf("preorder: "); print_preorder(root); printf("\n");
 
    return 0;
}
