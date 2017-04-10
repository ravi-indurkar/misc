// C++ program to convert a left unbalanced BST to a balanced BST
//   dont use  #include <bits/stdc++.h>


#include <vector>

#include <cstdio>
using namespace std;
 
struct Node
{
    int data;
    Node* left,  *right;
};
 
/* This function traverse the skewed binary tree and
   stores its nodes pointers in vector nodes[] */
void store_node_into_vector_array(Node* root, vector<Node*> &nodes)
{
    // Base case
    if (root==NULL)
        return;
 
    // Store nodes in Inorder (which is sorted
    // order for BST)
    store_node_into_vector_array(root->left, nodes);
    nodes.push_back(root);
    store_node_into_vector_array(root->right, nodes);
}
 
/* Recursive function to construct binary tree */
Node* build_balanced_tree(vector<Node*> &nodes, int start,
                   int end)
{
    // base case
    if (start > end)
        return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    Node *root = nodes[mid];
 
    /* Using index in Inorder traversal, construct
       left and right subtress */
    root->left  = build_balanced_tree(nodes, start, mid-1);
    root->right = build_balanced_tree(nodes, mid+1, end);
 
    return root;
}
 
// This functions converts an unbalanced BST to
// a balanced BST
Node* unbalanced_to_balanced(Node* root)
{
    // Store nodes of given BST in sorted order
    vector<Node *> nodes;
    store_node_into_vector_array(root, nodes);
 
    // Constucts BST from nodes[]
    int n = nodes.size();
    return build_balanced_tree(nodes, 0, n-1);
}
 
// Utility function to create a new node
Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
 
/* Function to do preorder traversal of tree */
void print_preorder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    print_preorder(node->left);
    print_preorder(node->right);
}
 
int main()
{
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
 
    Node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);
 
    printf("Preorder print of balanced BST before: \n");
    print_preorder(root);
	printf("\n");

	/* do the work; unbalanced to balanced */
    root = unbalanced_to_balanced(root);
 
    printf("Preorder print of balanced BST after : \n");
    print_preorder(root);
	printf("\n");
 
    return 0;
}
