// You are working as a software engineer at a technology company, and your team is developing a utility tool for sorting binary numbers efficiently. The utility is designed to sort an array of integers based on the number of 1s in their binary representation. In case of two or more integers having the same number of 1s, you need to sort them in ascending order.



// Write a program that takes an array of integers as input and uses the Quick-Sort algorithm to sort the integers in ascending order based on the number of 1s in their binary representation.



// Example 1



// Input: 

// arr = [0,1,2,3,4,5,6,7,8]



// Output: 

// [0,1,2,4,8,3,5,6,7]



// Explanation: 

// [0] is the only integer with 0 bits.

// [1,2,4,8] all have 1 bit.

// [3,5,6] have 2 bits.

// [7] has 3 bits.

// The sorted array by bits is [0,1,2,4,8,3,5,6,7]



// Example 2



// Input: 

// arr = [1024,512,256,128,64,32,16,8,4,2,1]



// Output: 

// [1,2,4,8,16,32,64,128,256,512,1024]



// Explanation: 

// All integers have 1 bit in the binary representation, you should just sort them in ascending order.

// Input format :
// The first line of input consists of an integer N, representing the number of elements.

// The second line consists of N array elements, separated by space.

// Output format :
// The output prints the sorted integers in ascending order based on the number of 1s in their binary representation.

// Code constraints :
// N > 0
#include <stdio.h>
#include <stdlib.h>

int countOnes(int num) {
    int count = 0;
    while (num) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = countOnes(arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (countOnes(arr[j]) < pivot || (countOnes(arr[j]) == pivot && arr[j] < arr[high])) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    free(arr);
    return 0;
}