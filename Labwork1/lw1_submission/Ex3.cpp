/*
Exercise 3: Write a structure to represent complex numbers and
complete operators: add and multiply
*/

#include <iostream>
using namespace std;

// Define structure 
struct Complex {
    double real;
    double imag;

    // Constructor 
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overloading addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overloading multiplication
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    // Function to display complex number
    void display() const {
        cout << real;
        if (imag >= 0) cout << " + " << imag << "i";
        else cout << " - " << -imag << "i";
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);

    Complex sum = c1 + c2;
    Complex product = c1 * c2;

    cout << "First complex number: ";
    c1.display();
    cout << "\nSecond complex number: ";
    c2.display();
    cout << "\nSum is: ";
    sum.display();
    cout << "\nProduct is: ";
    product.display();
    cout << endl;

    return 0;
}
