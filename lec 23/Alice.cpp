// Alice is working on a project that requires sorting and displaying the frequency of elements in an array. She needs your help to write a program to sort an array of positive integers and display the elements sorted by frequency in descending order. If two elements have the same frequency, they should be sorted in ascending order of their values.



// For this project, your task is to implement the logic of the merge sort and a recursive function.

// Input format :
// The first line contains an integer n, representing the number of elements in the array.

// The second line contains n space-separated integers, arr[i].

// Output format :
// The output prints a single line containing the sorted elements of the array separated by spaces.

// Code constraints :
// max_n = 100

// 1 ≤ n ≤ 25

// 1 <= arr[i] <= 100

// You are using GCC
#include <stdio.h>

const int MAX_N = 100;

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int index = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) { // Use <= for correct merging
            temp[index++] = arr[i++];
        } else {
            temp[index++] = arr[j++];
        }
    }

    while (i <= mid) {
        temp[index++] = arr[i++];
    }

    while (j <= right) {
        temp[index++] = arr[j++];
    }

    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

void mergeSort(int arr[], int temp[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge(arr, temp, left, mid, right);
    }
}

void countAndSortFrequency(int arr[], int n) {
    int freqArr[MAX_N][2] = {0};
    int values[MAX_N];

    int index = 0;
    for (int i = 0; i < n; i++) {
        int isAlreadyCounted = 0;
        for (int j = 0; j < index; j++) {
            if (values[j] == arr[i]) {
                freqArr[j][1]++;
                isAlreadyCounted = 1;
                break;
            }
        }
        if (!isAlreadyCounted) {
            values[index] = arr[i];
            freqArr[index][0] = arr[i];
            freqArr[index][1] = 1;
            index++;
        }
    }

    for (int i = 0; i < index; i++) {
        for (int j = i + 1; j < index; j++) {
            if (freqArr[i][1] < freqArr[j][1] || (freqArr[i][1] == freqArr[j][1] && freqArr[i][0] > freqArr[j][0])) {
                int temp = freqArr[i][0];
                freqArr[i][0] = freqArr[j][0];
                freqArr[j][0] = temp;

                temp = freqArr[i][1];
                freqArr[i][1] = freqArr[j][1];
                freqArr[j][1] = temp;
            }
        }
    }

    for (int i = 0; i < index; i++) {
        for (int j = 0; j < freqArr[i][1]; j++) {
            printf("%d ", freqArr[i][0]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX_N];

    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    countAndSortFrequency(arr, n);

    return 0;
}