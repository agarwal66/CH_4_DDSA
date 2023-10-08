// Harish is learning about binary trees and postorder traversals in his computer science class. He is given an assignment to write a program that constructs the postorder traversal of a binary tree from an array of integers. Can you help him solve this problem?



// Note:



// The binary tree can have a maximum of 100 nodes.
// All node values in the binary tree are unique.
// For a node at index i in the input array: Its left child is at index 2 * i + 1, and its right child is at index 2 * i + 2.
// The array represents the binary tree's structure, with each index corresponding to a node and its value.
// Input format :
// The first line contains an integer n, representing the number of elements in the array.

// The second line contains n space-separated integers, arr [i], representing the values of the nodes in the binary tree. The elements are given in the order of a binary tree, where the i-th element is the value of the i-th node.

// Output format :
// The output displays a single line containing n space-separated integers, which represent the postorder traversal of the binary tree constructed from the input array.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 15

// 1 ≤ arr[i] ≤ 100
#include <iostream>
#include <cstring>

using namespace std;

const int MAX_NODES = 100;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

int ans[MAX_NODES];
int idx = 0;

void postorder(struct TreeNode* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " "; 
}

void fillArray(struct TreeNode* root) {
    postorder(root);
}

void postorderTraversal(struct TreeNode* root) {
   if(root == nullptr) {
       return;
   }
   postorderTraversal(root->left);
   postorderTraversal(root->right);
   cout << root->val << " ";
}

struct TreeNode* createTree(int arr[], int i, int n) {
    if(i >= n) {
        return nullptr;
    }
    TreeNode* newNode = new TreeNode(arr[i]);
    newNode->left = createTree(arr, 2 * i + 1, n);
    newNode->right = createTree(arr, 2 * i + 2, n);
    return newNode;
}

int main() {
    int n;
    cin >> n;

    int arr[MAX_NODES];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    TreeNode* root = createTree(arr, 0, n);

    postorderTraversal(root);

    return 0;
}
