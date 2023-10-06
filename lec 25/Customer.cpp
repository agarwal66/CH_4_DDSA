// You are working on a critical customer database system for a large e-commerce platform. 



// The database stores customer information, like their unique customer IDs, in a binary tree structure. Ensuring data integrity is paramount, as duplicate customer IDs can lead to serious data inconsistencies and operational issues. 



// Your task is to develop a program that checks whether the binary tree containing customer IDs has any duplicate values. Detecting duplicates is essential to maintain the accuracy of customer records.

// Input format :
// The first line of input consists of an integer representing the value of the root node.

// For each node in the tree, there are two integers,

// Left child data: an integer representing the value of the left child node. Use -1 to indicate no left child.

// Right child data: an integer representing the value of the right child node. Use -1 to indicate no right child.

// Output format :
// Print "Yes" if there are any duplicate customer IDs in the binary tree.

// Otherwise, print "No".
#include <iostream>

// Define the structure for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to count the number of nodes in the binary tree
int nodeCount(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + nodeCount(root->left) + nodeCount(root->right);
}

// Function to create a new binary tree node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to build a binary tree from user input
Node* buildBinaryTree() {
    int data;
    std::cin >> data;

    if (data == -1) {
        return nullptr; // Return nullptr for an empty node
    }

    Node* root = createNode(data);

    root->left = buildBinaryTree();
    root->right = buildBinaryTree();

    return root;
}

// Function to check if a binary tree has duplicate values
bool hasDuplicateValuesUtil(Node* root, int* prev_values, int* prev_index) {
    if (root == nullptr) {
        return false;
    }

    // Check if the current node's data matches any previous value.
    for (int i = 0; i < *prev_index; i++) {
        if (prev_values[i] == root->data) {
            return true;
        }
    }

    // Store the current node's data in the array of previous values.
    prev_values[(*prev_index)++] = root->data;

    // Recursively check for duplicate values in left and right subtrees.
    return hasDuplicateValuesUtil(root->left, prev_values, prev_index) ||
           hasDuplicateValuesUtil(root->right, prev_values, prev_index);
}

bool hasDuplicateValues(Node* root) {
    int prev_index = 0;
    int numNodes = nodeCount(root);

    int* prev_values = new int[numNodes]; // Dynamically allocate memory

    bool result = hasDuplicateValuesUtil(root, prev_values, &prev_index);

    delete[] prev_values; // Free dynamically allocated memory

    return result;
}

int main() {
    Node* root = nullptr;

    root = buildBinaryTree();

    if (hasDuplicateValues(root)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }

    return 0;
}