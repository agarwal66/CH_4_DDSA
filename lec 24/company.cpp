// You are working as a software developer at a language processing company. As part of the company's text processing system, you need to sort a collection of words in reverse lexicographical (dictionary) order using the Quick-Sort algorithm.



// Write a program that takes an array of words as input and uses the QuickSort algorithm to sort the words in reverse lexicographical order.

// Input format :
// The first line of input consists of an integer N, representing the number of strings.

// The second line consists of N strings, separated by space.

// Output format :
// The output displays the words sorted in reverse lexicographical order.

// Code constraints :
// N > 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int partition(char *arr[], int low, int high) {
    char *pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        
        if (strcmp(arr[j], pivot) > 0) {
            i++;
           
            char *temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

   
    char *temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(char *arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char **words = (char **)malloc(n * sizeof(char *));
    for (int i = 0; i < n; i++) {
        words[i] = (char *)malloc(100 * sizeof(char));
        scanf("%s", words[i]);
    }

    quickSort(words, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%s ", words[i]);
        free(words[i]);
    }

    free(words);
    return 0;
}