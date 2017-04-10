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
    if (node ==NULL) return;

    if (node->left) print_preorder(node->left);
    printf("%d ", node->data);
    if (node->right) print_preorder(node->right);
}

void print_inorder(Node *node)
{
    if (node ==NULL) return;

    printf("%d ", node->data);
    if (node->left) print_inorder(node->left);
    if (node->right) print_inorder(node->right);
}

void print_postorder(Node *node)
{
    if (node ==NULL) return;

    printf("%d ", node->data);
    if (node->right) print_postorder(node->right);
    if (node->left) print_postorder(node->left);
}

void print_xxorder(Node *node)
{
    if (node ==NULL) return;

    if (node->left) print_xxorder(node->left);
    if (node->right) print_xxorder(node->right);
    printf("%d ", node->data);
}

void print_yyorder(Node *node)
{
    if (node ==NULL) return;

    if (node->right) print_yyorder(node->right);
    if (node->left) print_yyorder(node->left);
    printf("%d ", node->data);
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
 
    Node* root = newNode(100);
    root->left = newNode(80);
    root->left->left = newNode(70);
    root->left->right = newNode(90);
    root->left->right->left = newNode(92);
    root->left->right->right = newNode(95);
    root->left->right->right->right = newNode(97);
    root->left->left->left = newNode(60);
    root->left->left->left->left = newNode(50);
 
    printf("preorder: "); print_preorder(root); printf("\n");
    printf("Inorder: "); print_inorder(root); printf("\n");
    printf("postorder: "); print_postorder(root); printf("\n");
    printf("xxorder: "); print_xxorder(root); printf("\n");
    printf("yyorder: "); print_yyorder(root); printf("\n");
 
    return 0;
}
