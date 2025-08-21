/*
Exercise 1: Write a pseudocode and implement a program in C 
to swap the first and last digits of a positive integer.
*/

// Pseudocode
/*
Begin:
    read(initial_num)
    lastDigit ← initial_num % 10;
    digits ← log10(initial_num);
    firstDigit ← initial_num / pow(10, digits);
    
    swap_num ← lastDigit * pow(10, digits);
    swap_num ← swap_num + initial_num % pow(10, digits);
    swap_num ← swap_num - lastDigit;
    swap_num ← swap_num + firstDigit;
End
*/

// Implement Code
#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int ini_num;
    cout << "Please enter a positive integer: ";
    cin >> ini_num;

    // Check if the number is a positive integer
    if (ini_num <= 0) {
        while (ini_num <= 0) {
            cout << "Please re-enter a positive integer: ";
            cin >> ini_num;
        }
    }

    else if (ini_num == 10) {
        cout << "The swapped number is: 01";
    }

    else {
        // Extracting first and last digit
        int swa_num;
        int last_digi = ini_num % 10;
        int digits = log10(ini_num);
        int first_digit = ini_num / pow(10, digits);

        // Swapping
        swa_num = last_digi;
        swa_num *= (int) round(pow(10, digits));
        swa_num += ini_num % ((int)round(pow(10, digits)));
        swa_num -= last_digi;
        swa_num += first_digit;

        cout << "The swapped number is: " << swa_num;
    }
    
    return 0;
}