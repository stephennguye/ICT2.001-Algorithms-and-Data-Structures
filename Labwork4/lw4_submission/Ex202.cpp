#include <iostream>
#include <cmath>
using namespace std;

// Recursive function to check if a number is prime
bool isPrime(int n, int divisor = 2) {
    if (n <= 1) return false;
    if (divisor > sqrt(n)) return true; 
    if (n % divisor == 0) return false; 
    return isPrime(n, divisor + 1);     
}

// Recursive function to check if a number is sphenic
bool isSphenicRecursive(int n, int prime_count = 0, int factor = 2) {
    if (n == 1) return prime_count == 3; // Exactly 3 distinct prime factors
    if (prime_count > 3 || factor > n / 2) return false; // Exceeded 3 primes or no more factors

    if (n % factor == 0 && isPrime(factor)) {
        // Divide by the factor and check next
        return isSphenicRecursive(n / factor, prime_count + 1, factor + 1);
    }

    // Skip to the next potential factor
    return isSphenicRecursive(n, prime_count, factor + 1);
}

// Recursive function to list all sphenic numbers up to n
void listSphenicRecursive(int current, int limit) {
    if (current > limit) return; // Base case: stop at limit
    if (isSphenicRecursive(current)) cout << current << " ";
    listSphenicRecursive(current + 1, limit); // Check next number
}

int main() {
    int n;
    cout << "Please enter a natural number: ";
    cin >> n;

    while (n <= 0) {
        cout << "Please re-enter a natural number: ";
        cin >> n;
    }

    cout << "Sphenic numbers from 1 to " << n << " are: ";
    listSphenicRecursive(1, n);
    cout << endl;

    return 0;
}
