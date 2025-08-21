/*
Exercise 1 : In this problem, we would like to implement the algorithm to calculate the digit sum of a given natural number that can be used in detecting errors
in message transmission or data storage.
    For example:
        N = 103509, the digit sum = 1 + 0 + 3 + 5 + 0 + 9 = 18.
*/

// 1. Write a pseudo-code to solve the above problem using Iteration.
/*
BEGIN

END
*/

#include <iostream>
using namespace std;

// Recursive function 
int sumOfNum(int num) {
    if (num == 0)
        return 0; // Base case: if num is 0, sum is 0
    return (num % 10) + sumOfNum(num / 10); 
}

int main() {
    int ini_num;
    cout << "Please enter a natural number: ";
    cin >> ini_num;

    while (ini_num <= 0) {
        cout << "Please re-enter a natural number: ";
        cin >> ini_num;
    }

    // 2. Write a program from the pseudo-code and solve the Problem using Iteration.
    int temp_num = ini_num; 
    int sum_num = 0;

    while (temp_num > 0) {
        sum_num += temp_num % 10; 
        temp_num /= 10;          
    }
    cout << "The solution to the problem using Iteration is: " << sum_num << endl;

    // 3. Calculate the complexity. Justify your answer
    cout << "The time complexity to the problem using Iteration is: O(log10(n))" << endl;

    // 4. Write a program to solve the Problem using Recursion (with Iteration if necessary).
    cout << "The solution to the problem using Recursion is: " << sumOfNum(ini_num) << endl;

    // 5. Calculate the complexity. Justify your answer.
    cout << "The time complexity to the problem using Recursion is: O(log10(n))" << endl;

    return 0;
}