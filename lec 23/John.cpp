// John is a student who just received his test scores (floating-point numbers) for various subjects. He wants to organize his scores in descending order so that he can see his highest scores first. Can you help him write a program to sort his test scores in descending order?



// Your task is to write a program to sort John's test scores in descending order using the Merge Sort algorithm and a recursive function.

// Input format :
// The first line contains an integer, n, representing the number of test scores John has received.

// The next line contains n floating-point numbers separated by spaces, each representing John's test score.

// Output format :
// The output displays the sorted test scores in descending order, each rounded to two decimal places.



// Refer to the sample outputs for the exact format.

// Code constraints :
// 1 ≤ n ≤ 15

// 0.0 <= test score <= 100.0
#include <stdio.h>

void merge(float arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    float leftArr[n1];
    float rightArr[n2];

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

void mergeSort(float arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}
