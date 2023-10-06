// In a mystical land known as Eldoria, ancient wizards use magical runes to cast powerful spells. These runes are represented by single characters, each possessing a unique magical property. However, the wizards have a challenge: they need these magical runes sorted in a specific order for their spells to work correctly.



// Write a program to help the wizards of Eldoria sort their magical runes based on their potency. Each rune is represented by a single character, and each character holds a unique level of magical power, determined by its position in the ASCII table.



// Your task is to implement a merge sorting logic and recursive function to arrange these magical runes in descending order of their magical potency.

// Input format :
// The first line of input consists of an integer n, representing the number of magical runes to be sorted.

// The second line contains n space-separated characters, each representing a magical rune.

// Output format :
// The output displays a single line containing the magical runes sorted in descending order of their magical potency, separated by spaces.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// 1 <= n <= 25

// Each character in the array is a single uppercase letter or a single lowercase letter.

// You are using GCC
#include <stdio.h>

#define MAX_ARRAY_LENGTH 100

void merge_descending(char arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    char leftArr[n1];
    char rightArr[n2];

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        rightArr[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArr[i] >= rightArr[j]) { // Use >= for correct merging
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void mergeSortDescending(char arr[], int left, int right) {
        if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortDescending(arr, left, mid);
        mergeSortDescending(arr, mid + 1, right);
        merge_descending(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    char arr[n];
    for (int i = 0; i < n; i++)
        scanf(" %c", &arr[i]);

    mergeSortDescending(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%c ", arr[i]);

    return 0;
}