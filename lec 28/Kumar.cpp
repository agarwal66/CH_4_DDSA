
// Kumar is studying data structures and is currently learning about Binary Search Trees (BST). He wants to implement the operations of creating and displaying a Binary Search Tree.



// Write a program that takes a sequence of positive integers as input and constructs a Binary Search Tree using these integers. After constructing the BST, the program should display the nodes of the BST in ascending order.

// Input format :
// The input consists of a series of positive integers greater than zero, separated by a space.

// The input ends when -1 is entered.

// The integers represent the elements to be inserted into the binary search tree.

// Output format :
// The output displays the elements of the binary search tree in ascending order (sorted order), separated by space.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The input integers > 0.


// The number of elements in the binary search tree will be at most 100.
#include<iostream>
#include<cstdlib>
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
    if(root==NULL){
        root = newNode;
    }
    else{
        struct node*current = root;
        while(true){
            if(d < current->data){
                if(current->left == NULL){
                    current->left = newNode;
                    break;
                }
                else{
                    current = current->left;
                }
            }
                else{
                    if(current->right==NULL){
                        current->right = newNode;
                        break;
                    }
                    else{
                        current = current->right;
                    }
                }
            }
        }
    }

void display(struct node*root)
{
   if(root==NULL){
       return;
   }
   display(root->left);
   cout<<root->data<<" ";
   display(root->right);
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
  display(root);
  return 0;
}