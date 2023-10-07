// Imagine you are a computer scientist working on a cutting-edge project involving binary trees. As part of your research, you are analyzing the in-order traversal of a specific binary tree. Your task is to determine the value of the node that appears at the nth position in the in-order traversal sequence.



// To accomplish this, you are given a binary tree with various nodes. Each node has a unique value associated with it. Your goal is to navigate through the tree using the in-order traversal algorithm, which involves visiting the left subtree, then the current node, and finally the right subtree.



// By implementing an efficient algorithm, you should be able to find the node that appears at the nth position in the in-order traversal sequence of the given binary tree.





// Input format :
// The input consists of an integer value, n, which represents the position of the node in the in-order traversal sequence that needs to be found.

// Output format :
// The output prints the value of the node that appears at the nth position in the in-order traversal sequence.

// Code constraints :
// 1 <= n <= 5
// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

//Function to create a new node
struct Node* newNode(int data) {
 struct Node* newNode = new struct Node;
 newNode->data=data;
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
   
}

//Function to find the nth inorder node
void NthInorder(struct Node* node, int n,int& count) {
    
    if(node==NULL || count>=n){
        return;
    }
    NthInorder(node->left,n,count);
    count++;
   
    if(count==n){
        cout<<node->data<<" ";
        return;
    }
    NthInorder(node->right,n,count);
}

int main()
{
    struct Node* root = newNode(10);
    root->left = newNode(20);
    root->right = newNode(30);
    root->left->left = newNode(40);
    root->right->right = newNode(50);

    int n,count=0;
    cin >> n;

    NthInorder(root, n,count);
    return 0;
}