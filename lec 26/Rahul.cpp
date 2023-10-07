// Rahul is working on a program for a tree manipulation application. Your task is to help Rahul implement a program that converts a given binary tree into its mirror image using preorder traversal. 



// Your program should traverse the binary tree in a preordered manner and swap the left and right subtrees of each node to achieve the mirror image. 



// Write a function that performs the conversion to the mirror image using a preorder traversal approach. The function should take the root of the binary tree as input and modify the tree to obtain its mirror image.

// Input format :
// The first line of input consists of an integer N, representing the number of nodes in the binary tree.

// The second line consists of N space-separated integers representing the values of the nodes.

// Output format :
// The first line of output should display the preorder traversal of the original binary tree.

// The second line should display the preorder traversal of the binary tree after converting it into its mirror image.

// Code constraints :
// 1 <= node values <= 200
// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = new struct Node;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to build the tree
struct Node* insertNode(struct Node* root, int data) {
    
    
    if (root == NULL) {
        struct Node* newNode = createNode(data);
        return newNode;
    }
    if(data<root->data){
    root->left = insertNode(root->left,data);
    }
    else if(data>root->data){
    root->right = insertNode(root->right,data);
    }
    return root;
}

//Function to perform the preorder traversal
void preorderTraversal(struct Node* root) {
    
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    
}

//Function to find the mirror image of the tree
void mirrorImage(struct Node* root) {
    
    if(root==NULL){
        return ;
    }
    struct Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    mirrorImage(root->left);
    mirrorImage(root->right);
}

int main() {
    struct Node* root = NULL;
    int n, data;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> data;
        root = insertNode(root, data);
    }

    cout << "Original tree: ";
    preorderTraversal(root);
    cout << endl;

    mirrorImage(root);

    cout << "Mirror Image: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}