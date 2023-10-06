// You are tasked with developing a software module for a critical application that involves binary trees. Your objective is to create a program that determines whether a given binary tree adheres to the Binary Search Tree (BST) property.



// In a Binary Search Tree (BST):

// Each node in the tree has a unique integer value.
// For any given node,
// All nodes in its left subtree have values less than the node's value.
// All nodes in its right subtree have values greater than the node's value.


// Your task is to implement a program that can take as input a binary tree and determine whether it is a valid BST according to the rules mentioned above.

// Input format :
// The first line of input consists of the root node's value as an integer.

// For each non-null node, there will be two inputs: the value of the left child (if exists) or -1 if there is no left child, the value of the right child (if exists) or -1 if there is no right child.

// Output format :
// Print "The given binary tree is a BST" if the input binary tree satisfies the BST properties.

// Otherwise, print "The given binary tree is not a BST".
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node has data, a pointer to the left child,
   and a pointer to the right child */
struct node {
    int data;
    struct node* left;
    struct node* right;
};

/* Function to check if the given tree is a binary search tree */
int isBST(struct node* node, int min, int max) {
    // Base case: an empty tree is a valid BST
    if (node == NULL)
        return 1;

    // Check if the current node's data is within the valid range
    if (node->data <= min || node->data >= max)
        return 0;

    // Recursively check the left and right subtrees
    return isBST(node->left, min, node->data) && isBST(node->right, node->data, max);
}

/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/* Function to build a binary tree from user input */
struct node* buildTree() {
    int data;
    struct node* root = NULL;

    scanf("%d", &data);

    if (data == -1)
        return NULL;

    root = newNode(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {
    struct node* root = buildTree();

    if (isBST(root, INT_MIN, INT_MAX))
        printf("The given binary tree is a BST\n");
    else
        printf("The given binary tree is not a BST\n");

    return 0;
}
