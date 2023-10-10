// Arun is developing a program that uses a Binary Search Tree (BST) to manage a collection of integers. He has written the code to create a BST and search for elements within it, but he needs your assistance in testing its functionality.



// You are tasked with helping Arun by designing a program that performs the following actions:



// Build a Binary Search Tree (BST) by adding integers to it one by one.
// Search for a specific integer in the BST to determine if it is present.
// Input format :
// The first n lines of input consist of a series of positive integers (greater than zero) separated by space.

// The input ends when -1 is entered.

// The last line of input consists of an integer representing the elements to be inserted into the binary search tree.

// Output format :
// The output displays one of the following messages:



// If the key is present in the binary search tree, print <key> is present in the BST.

// If the key is not present in the binary search tree, print <key> is not present in the BST.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// The input integers will be positive and greater than zero.

// The number of elements in the binary search tree will be at most 100.


// You are using GCC
#include<iostream>
#include<cstdlib>
using namespace std;
struct node
{
  int data;
  struct node*left;
  struct node*right;
};
struct node*root =nullptr;
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
bool iterativeSearch(struct node*root,int key){
    while(root!=NULL){
        if(key == root->data){
            return true;
        }
        else if(key < root->data){
            root = root->left ;
        }
        else{
            root = root->right;
        }
    }
    return false;
}
//Write Your Code

int main()
{
  int d,search;
  do
  {
    cin>>d;//3
    if(d > 0)
      append(d);
  }while(d != -1);//-1
  cin>>search;
  if(iterativeSearch(root,search))
    cout<<search<<" is present in the BST";
  else
    cout<<search<<" is not present in the BST";
  return 0;
}