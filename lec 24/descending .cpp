
// You are given a sequence of characters, and your task is to sort them in descending order using the Quick-Sort algorithm.



// Write a program that takes an integer N as input, representing the number of characters in the sequence. Then, read N characters as input. Implement the quick sort algorithm to sort the characters and print the sorted sequence.

// Input format :
// The first line of input consists of an integer N, representing the number of characters.

// The second line consists of N space-separated characters.

// Output format :
// The output prints the sorted characters in descending order.

// Code constraints :
// N > 0
// You are using GCC
#include <iostream>
using namespace std;

void printArray(char arr[], int size) {
    
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(char arr[], int low, int high) {
    
    char pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(arr[j]>=pivot){
            i++;
            char temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    char temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}


void quickSort(char arr[], int low, int high) {
    
   if(low<high){
        int loc = partition(arr,low,high);
        quickSort(arr,low,loc-1);
        quickSort(arr,loc+1,high);
    }
    
}
int main() {
    int n;
    cin >> n;

    char *characters = new char[n];

    for (int i = 0; i < n; i++) {
        cin >> characters[i];
    }

    quickSort(characters, 0, n - 1);
    printArray(characters, n);

    delete[] characters;
    return 0;
}