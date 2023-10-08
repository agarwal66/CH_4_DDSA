// Joseph is learning about binary trees and post-order traversals in his computer science class.



// He is given an assignment to write a program that constructs the post-order traversal of a binary tree from a list of integers. Can you help him solve this problem?

// Input format :
// The first line of input contains an integer n, representing the number of integers Joseph will provide to construct the binary tree.

// The second line contains n space-separated integers, representing the values of the nodes in the binary tree.

// Output format :
// The output displays a single line containing n space-separated integers, representing the post-order traversal of the binary tree.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 <= n <= 20

// 1 <= elements <= 1000
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int data) {
    if (root == nullptr) {
        return new Node(data);
    } else {
        Node* cur = new Node(data);

        if (root->left == nullptr) {
            root->left = cur;
        } else if (root->right == nullptr) {
            root->right = cur;
        } else {
            // If both left and right children are already present,
            // you can choose one side to insert the new node, e.g., left.
            root->left = insert(root->left, data);
        }

        return root;
    }
}

void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
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

    postOrder(root);
    return 0;
}