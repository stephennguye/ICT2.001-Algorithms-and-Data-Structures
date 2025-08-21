/*
Exercise 1: Suppose that we use a List data structure to represent unbounded
integers.
    - the first element refers to the sign: 1 is positive and -1 is negative.
    - each element in the list represents one digit of these integers.
*/

#include <iostream>
using namespace std;

// Pseudocode for Digit Sum Calculation
/*
begin
    Procedure DigitSumIterative(N)
        Initialize sum ← 0
        While N > 0 do
            digit <-- N % 10    // Extract the last digit
            sum <-- sum + digit
            N <-- N // 10      // Remove the last digit
        End While
        Return sum
    End Procedure

    Procedure DigitSumRecursive(N)
        If N == 0 Then
            Return 0
        Else
            Return (N % 10) + DigitSumRecursive(N // 10)
        End If
    End Procedure
end
*/

// Iterative Function to Calculate Digit Sum
int digit_sum_iterative(int N) {
    int total = 0;
    while (N > 0) {
        total += N % 10;
        N /= 10;
    }
    return total;
}

// Recursive Function to Calculate Digit Sum
int digit_sum_recursive(int N) {
    if (N == 0)
        return 0;
    else
        return N % 10 + digit_sum_recursive(N / 10);
}

int main() {
    int N1 = 103509;
    int N2 = 9512;

    cout << "Digit sum of " << N1 << " (Iterative): " << digit_sum_iterative(N1) << endl;
    cout << "Digit sum of " << N1 << " (Recursive): " << digit_sum_recursive(N1) << endl;
    cout << "Digit sum of " << N2 << " (Iterative): " << digit_sum_iterative(N2) << endl;
    cout << "Digit sum of " << N2 << " (Recursive): " << digit_sum_recursive(N2) << endl;

    return 0;
}
