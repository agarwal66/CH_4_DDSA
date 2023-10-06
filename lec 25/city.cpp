// You are developing software for a car rental agency that manages its vehicle fleet across two locations, City A and City B. Each location's vehicle fleet is represented as a Binary Search Tree (BST) containing unique vehicle IDs. 



// Your program needs to determine whether the vehicle fleets in both cities are identical or not.

// Input format :
// The first line of input consists of the space-separated vehicle IDs for City A, terminated by -1.

// The second line consists of the space-separated vehicle IDs for City B, terminated by -1.

// Output format :
// Print "Both vehicle fleets are identical" if the vehicle fleets in both cities are identical.

// Otherwise, print "Vehicle fleets are not identical"
#include <iostream>

using namespace std;

// BST node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Node
Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// Function to insert a node into a BST
Node* insert(Node* root, int data) {
    if (root == nullptr)
        return newNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Function to check if two BSTs are identical
bool areFleetsIdentical(Node* fleet1, Node* fleet2) {
    if (fleet1 == nullptr && fleet2 == nullptr)
        return true;
    else if (fleet1 == nullptr || fleet2 == nullptr)
        return false;
    else {
        if (fleet1->data == fleet2->data && areFleetsIdentical(fleet1->left, fleet2->left) &&
            areFleetsIdentical(fleet1->right, fleet2->right))
            return true;
        else
            return false;
    }
}

int main() {
    Node* cityAFleet = nullptr;
    Node* cityBFleet = nullptr;
    int vehicleID;

    while (1) {
        cin >> vehicleID;
        if (vehicleID == -1)
            break;
        cityAFleet = insert(cityAFleet, vehicleID);
    }

    while (1) {
        cin >> vehicleID;
        if (vehicleID == -1)
            break;
        cityBFleet = insert(cityBFleet, vehicleID);
    }

    if (areFleetsIdentical(cityAFleet, cityBFleet))
        cout << "Both vehicle fleets are identical" << endl;
    else
        cout << "Vehicle fleets are not identical" << endl;

    return 0;
}