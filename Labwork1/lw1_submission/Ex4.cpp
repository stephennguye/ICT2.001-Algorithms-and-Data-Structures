/*
Exercise 4:
Write a pseudo-code by commenting in the file then implement a program in to
enter a natural number n and verify whether n is sphenic.
Calculate the complexity of your program
*/

#include <iostream>
#include <cmath>
using namespace std;

// Check if number is Prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

// Check if number is Sphenic
bool isSphenic(int n) {
    int prime_count = 0; // Count of distinct prime factors
    int product = 1;     // Product of prime factors

    for (int i = 2; i <= n / 2; ++i) {
        if (n % i == 0 && isPrime(i)) {
            ++prime_count;
            product *= i;
            n /= i;

            if (n % i == 0) return false;

            if (prime_count > 3) return false;
        }
    }

    // If n > 1 after loop --> Another prime factor
    if (n > 1 && isPrime(n)) {
        ++prime_count;
        product *= n;
    }

    // Check for exactly 3 distinct primes
    return prime_count == 3;
}

int main() {
    int n;
    cout << "Enter a natural number: ";
    cin >> n;

    if (isSphenic(n)) {
        cout << n << " is a sphenic number" << endl;
    } else {
        cout << n << " is not a sphenic number" << endl;
    }

    return 0;
}

// Complexity: O(n^3)