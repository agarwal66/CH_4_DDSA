
// Vinith is working on a programming assignment that involves binary search trees (BSTs). He needs to implement a program that constructs a BST from a given list of integers and then calculates two important pieces of information: the post-order traversal of the tree and the sum of all nodes within the tree.

// Input format :
// The first line of input contains an integer n, representing the number of integers Vinith will provide to construct the BST.

// The second line contains n space-separated integers, data, representing the values to be inserted into the BST.

// Output format :
// The first line should display the post-order traversal of the binary search tree.

// The second line should display the sum of all nodes in the binary search tree.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 20

// 1 ≤ data ≤ 1000
// You are using GCC
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) : data(d), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    } else {
        Node* cur;
        if (data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
        return root;
    }
}

void postOrder(Node* root) 
{
  if(root==NULL){
      return;
  }
  postOrder(root->left);
  postOrder(root->right);
  cout<<root->data<<" ";
}

int sumOfNodes(Node* root) 
{
   if(root==NULL){
       return 0;
   }
   int leftsum = sumOfNodes(root->left);
   int rightsum = sumOfNodes(root->right);
   return root->data + leftsum+rightsum;
}

int main() {
    Node* root = nullptr;

    int n;
    int data;

    cin >> n;

    while (n-- > 0) {
        cin >> data;
        root = insert(root, data);
    }

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;
    
    int totalSum = sumOfNodes(root);
    cout << "Sum of all nodes: " << totalSum << endl;

    return 0;
}