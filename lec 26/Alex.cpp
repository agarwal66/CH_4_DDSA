// Alex is a computer science enthusiast who is fascinated by data structures. Recently, Alex started learning about binary search trees and wants to implement a program that creates a binary search tree based on given inputs and then traverses the tree in preorder.



// You are tasked with helping Alex by creating a program that should be structured as follows:

// Define the necessary structures and functions.
// Accept input integers from Alex until a non-positive integer is given (less than 1).
// Build the binary search tree based on the input.
// Perform a preorder traversal of the binary search tree and display the node data in preorder.


// Note: An infinite line of integer input represents the nodes of the binary search tree. If any value less than 1 is encountered, the input loop has to break and print the preorder traversal of the tree.

// Input format :
// The input consists of space-separated positive integers, representing the nodes of a binary search tree.

// The program will continue indefinitely until a value less than 1 is encountered, indicating the end of the input.

// Output format :
// The output prints the pre-order traversal of the constructed binary search tree, separated by space.

// Code constraints :
// 0 < input integers <= 103
// You are using GCC
#include<bits/stdc++.h>
using namespace std;

struct Node
{
 int data;
  struct Node *left = NULL;
  struct Node *right = NULL;
} *root=NULL,*temp;

//Function to build the tree
void create(int input) {
    

   if (root == NULL)
    {
        root = new Node();
        root->data = input;
    }
    else
    {
        Node *current = root;
        while (true)
        {
            if (input < current->data)
            {
                if (current->left == NULL)
                {
                    current->left = new Node();
                    current->left->data = input;
                    break;
                }
                else
                {
                    current = current->left;
                }
            }
            else
            {
                if (current->right == NULL)
                {
                    current->right = new Node();
                    current->right->data = input;
                    break;
                }
                else
                {
                    current = current->right;
                }
            }
        }
    }
}



//Function to perform the preorder traversal
void preorder(struct Node *temp) {
    
  if(temp==NULL){
      return;
  }
  cout<<temp->data<<" ";
  preorder(temp->left);
  preorder(temp->right);
  
}

int main()
{
  int input;
  while(1)
  {
     cin>>input;
    if(input<1)
      break;
    create(input); 
  }
    preorder(root);
    return 0 ;
}