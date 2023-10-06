// You work in a large warehouse where products are numbered from 0 to N-1. Your task is to identify any products that appear twice in the inventory list and report them in ascending order. This helps ensure accurate inventory management.



// For instance, if you have N = 4 products with IDs {0, 1, 3, 2}, and no duplicates exist, you report -1. However, if you have N = 5 products with IDs {1, 1, 2, 2, 3}, you must report the duplicates in ascending order: 1 2. This ensures your warehouse maintains efficient inventory control. The input products must be listed in ascending order.



// Now design a program using recursion to solve the given problem statement. 

// Input format :
// The first line contains an integer N, the size of the array.

// The second line contains N space-separated integers a[0], a[1], ..., a[N-1], representing the elements in the array in ascending order.

// Output format :
// The output should be a space-separated list of integers.

// If there are elements that occur twice in the given array, list them in ascending order.

// If no such elements are found, the output should be "-1" to indicate that there are no duplicates.



// Refer to the sample output for exact format specifications.

// Code constraints :
// 1 <= N <= 25

// 0 <= a[i] <= N-1, for each valid i. The input should be in ascending order.
#include <iostream>
using namespace std;

// Function to find and print duplicate elements in a sorted array
int findAndPrintDuplicates(int arr[], int n, int prev) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == prev) {
            // Found a duplicate element
            cout << arr[i] << " ";
            count++;
        }
        prev = arr[i];
    }

    if (count == 0) {
        // No duplicates found
        return -1;
    } else {
        // Duplicates found, so return the count of duplicates
        return count;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findAndPrintDuplicates(arr, n, -1);

    if (result == -1) {
        cout << "-1";
    }

    return 0;
}