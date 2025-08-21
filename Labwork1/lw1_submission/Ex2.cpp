/*
Exercise 2: Complete this given function void findMax(int *max, int a),
which assigns a value a to max if a > max.
*/

// Pseudo Code
/*
Begin:
    def findMax(a, b):
        if a > b:
        return a

     def main():
         n ← int(input())
         max ← 0
         for i in range(n):
             a ← int(input())
             findMax(max, a)
         print(max)
End
*/


// Implement Code
#include<iostream>
using namespace std;

void findMax(int &max, int a) {
    if (a > max) {
        max = a; // Assign the value of `a` to `*max` if `a` is greater than `*max`.
    }
}

int main() {
    cout << "Enter the size of the array: ";
    int size;
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array, each separated by a space: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int max = arr[0];
    for (int i = 1; i <= size; i++) {
        findMax(max, arr[i]);
    }

    cout << "The maximum number is " << max << endl;
    return 0;
}