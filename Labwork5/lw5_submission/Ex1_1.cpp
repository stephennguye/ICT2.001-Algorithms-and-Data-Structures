#include <iostream>
using namespace std;

void insertSorted(int arr[], int n) {
    int last = arr[n - 1];
    int j = n - 2;

    while (j >= 0 && arr[j] > last) {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

// Recursive insertion sort
void recursiveInsertionSort(int arr[], int n) {
    if (n <= 1) return;
    recursiveInsertionSort(arr, n - 1);
    insertSorted(arr, n);
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    displayArray(arr, n);

    recursiveInsertionSort(arr, n);

    cout << "Sorted array:\n";
    displayArray(arr, n);
    return 0;
}
