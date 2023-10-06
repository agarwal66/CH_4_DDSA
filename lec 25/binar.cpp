// You are given a binary search tree (BST) and an integer k. Your task is to find the kth smallest element in the BST.



// Implement the function kthSmallest that takes the root of the BST and an integer k as input and returns the kth smallest element in the BST.

// Input format :
// The first line of input consists of a sequence of integers representing the elements of the BST. The input is terminated by -1.

// The second line consists of an integer k, representing the position of the desired smallest element.

// Output format :
// The output prints a single integer, which is the kth smallest element in the BST.
#include <iostream>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// Function to perform an in-order traversal and find the kth smallest element
void kthSmallestUtil(TreeNode* root, int k, int& count, int& result) {
    if (root == nullptr || count >= k) {
        return;
    }

    // Recursively traverse the left subtree
    kthSmallestUtil(root->left, k, count, result);

    // Increment the count
    count++;

    // If count reaches k, store the result
    if (count == k) {
        result = root->val;
        return;
    }

    // Recursively traverse the right subtree
    kthSmallestUtil(root->right, k, count, result);
}

// Function to find the kth smallest element in the BST
int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int result = 0;
    kthSmallestUtil(root, k, count, result);
    return result;
}

// Function to build a BST from user input
TreeNode* buildBST() {
    int val;
    TreeNode* root = nullptr;

    while (true) {
        std::cin >> val;

        if (val == -1) {
            break;
        }

        if (root == nullptr) {
            root = new TreeNode(val);
        } else {
            // Insert the value into the BST
            TreeNode* current = root;
            while (true) {
                if (val < current->val) {
                    if (current->left == nullptr) {
                        current->left = new TreeNode(val);
                        break;
                    }
                    current = current->left;
                } else {
                    if (current->right == nullptr) {
                        current->right = new TreeNode(val);
                        break;
                    }
                    current = current->right;
                }
            }
        }
    }

    return root;
}

int main() {
    // Build a binary search tree from user input
    TreeNode* root = buildBST();

    int k;
    std::cin >> k;

    int kth_smallest = kthSmallest(root, k);
    std::cout << kth_smallest;

    // Clean up memory
    delete root;

    return 0;
}