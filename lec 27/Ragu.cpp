// Ragu is studying binary search trees (BSTs) and postorder traversals in his computer science class. He has been given an assignment to write a program that constructs a BST from a sequence of positive integers and then performs a postorder traversal of the tree. Can you help him complete this task?



// Note:

// The Binary Search Tree may not be balanced.

// The binary search tree is not necessarily balanced.

// The binary search tree can have a maximum of 1000 nodes.

// Input format :
// The input consists of a sequence of positive integers, each on a separate line, where each integer d represents a node's value. The sequence ends when Ragu enters -1, indicating the end of the input.

// Output format :
// The output displays the postorder traversal of the constructed binary search tree.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 <= input elements <= 100

// The input will be terminated by entering '-1'.
#include <iostream>
#include <cstdlib>
using namespace std;
struct node
{
  int data;
  struct node*left;
  struct node*right;
};
struct node*root;
void append(int d)
{
  
     struct node* newNode = new node;
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        struct node* current = root;
        while (true)
        {
            if (d < current->data)
            {
                if (current->left == NULL)
                {
                    current->left = newNode;
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
                    current->right = newNode;
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
void postorder(struct node*root)
{
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
  int d;
  do
  {
    cin>>d;
    if(d > 0)
      append(d);
  }while(d != -1);
  cout<<"Post order Traversal:"<<endl;
  postorder(root);
  return 0;
}