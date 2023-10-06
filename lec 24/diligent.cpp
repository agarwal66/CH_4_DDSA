// As a diligent teacher, you have conducted a challenging exam for your students. Now that the papers have been graded, you are eager to find out which students performed the best and identify those who might need extra support.



// To efficiently rank your students based on their marks, you decide to create a computer program that sorts their exam marks in descending order using the Quick-Sort algorithm.

// Input format :
// The first line of input consists of an integer N, representing the number of students.

// The second line consists of N floating-point numbers, representing the marks of the students.

// Output format :
// The output prints the marks in descending order, placing the highest mark first and the lowest mark last.

// Code constraints :
// N > 0
#include <iostream>
#include <iomanip> 

using namespace std;

void printArray(float arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << fixed << setprecision(1) << arr[i] << " ";
    }
}

int partition(float arr[], int low, int high) {
    
   float pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        
        if (arr[j]>=pivot) {
            i++;
           
            float temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

   
    float temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(float arr[], int low, int high) {
    if (low < high) {
        int loc = partition(arr, low, high);

        
        quickSort(arr, low, loc - 1);
        quickSort(arr, loc + 1, high);
    }
}

int main() {
    int n;
    cin >> n;

    float* marks = new float[n];
    for (int i = 0; i < n; i++) {
        cin >> marks[i];
    }

    quickSort(marks, 0, n - 1);

    printArray(marks, n);

    delete[] marks;
    return 0;
}