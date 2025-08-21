/*
Exercise 2 :
Write a program in C/C++ to enter a natural number n and find all sphenic numbers
from 1 to n using Recursion. Calculate the complexity of the proposed algorithm.
*/

#include <iostream>
using namespace std;

// Check if a number is Prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Recursive function to find sphenic numbers
void findSphenic(int n, int start, int count, int product) {
    if (count == 3) {
        if (product <= n) {
            cout << product << " ";
        }
        return;
    }

    for (int i = start; i <= n; ++i) {
        if (isPrime(i)) {
            findSphenic(n, i + 1, count + 1, product * i);
        }
    }
}

int main() {
    int n;
    cout << "Enter a natural number: ";
    cin >> n;

    cout << "Sphenic numbers from 1 to " << n << " are: ";
    findSphenic(n, 2, 0, 1);
    cout << endl;

    return 0;
}