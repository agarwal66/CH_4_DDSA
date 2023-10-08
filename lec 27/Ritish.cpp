// Rithish is studying data structures and algorithms, and he's currently learning about binary search trees (BSTs). He wants to practice his skills by performing operations on a BST. Help him by designing a program that allows him to insert elements into a BST and perform two operations: post-order traversal and calculating the height of the tree.



// Note:

// The height of the tree is computed by finding the maximum height between the left and right subtrees of the root node and then adding 1 to that maximum height.

// Input format :
// The first line of input is an integer n, representing the number of elements to be inserted into the BST.

// The second line of input is an integer, where the i-th integer represents the value to be inserted into the BST.

// Output format :
// The output displays the following format:



// First, it should print "Post-order traversal: " followed by the post-order traversal of the BST.

// Then, it should print "Height of the tree: " followed by the height of the BST.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 <= n <= 20

// // 1 <= i <= 1000
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

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int getHeight(Node* root) {
    if (root == nullptr) {
        // An empty tree has height 0.
        return 0;
    } else {
        // Compute the height of the left and right subtrees.
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);

        // The height of the tree is the maximum of the heights of its subtrees, plus 1 for the root node.
        return max(leftHeight, rightHeight) + 1;
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

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << "\nHeight of the tree: " << getHeight(root) -1<< endl;

    return 0;
}