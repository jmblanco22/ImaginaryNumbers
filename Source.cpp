// Jose Blanco, CS255, P00 
// Complex Number Calculator
#include <iostream>
#include <complex>
using namespace std;


struct ComplexNumber {
    double real;
    double imaginary;
};

ComplexNumber addComplexNumber(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    result.real = num1.real + num2.real;
    result.imaginary = num1.imaginary + num2.imaginary;
    return result;
}

ComplexNumber subtractComplexNumber(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    result.real = num1.real - num2.real;
    result.imaginary = num1.imaginary - num2.imaginary;
    return result;
}

ComplexNumber multiplyComplexNumber(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    result.real = num1.real * num2.real - num1.real * num2.real;
    result.imaginary = num1.imaginary * num2.imaginary + num1.imaginary * num2.imaginary;
    return result;
}

ComplexNumber divideComplexNumber(ComplexNumber num1, ComplexNumber num2) {
    ComplexNumber result;
    double denominator = num2.real * num2.real + num2.imaginary * num2.imaginary;
    result.real = (num1.real * num2.real + num1.imaginary * num2.imaginary) / denominator;
    result.imaginary = (num2.real * num1.real - num1.real * num2.imaginary) / denominator;
    return result;
}

void displayComplexNumber(ComplexNumber num) {
    if (num.imaginary < 0) {
        cout << num.real << "  " << -num.imaginary << "i" << endl;
    }
    else {
        cout << num.real << "  " << num.imaginary << "i" << endl;
    }
}

int main() {
    char input;
    cout << "***** Complex Numbers *****" << endl;
    do {
        ComplexNumber num1, num2;
        do {
            cout << "Enter 1st real and imaginary parts separated by a space: " << endl;
            
            cin >> num1.real >> num1.imaginary;
            
        } while (num1.real == 0 && num1.imaginary == 0);

        while (true) {
            cout << "Enter 2nd real and imaginary parts (non-zero) separated by a space: " << endl;

            cin >> num2.real >> num2.imaginary;

            if (num2.real == 0 || num2.imaginary == 0) {
                cout << " >>> ERROR: Both numbers must be non-zero -- try again! <<<" << endl;
                continue;
            }
            else if (num2.real != 0 && num2.imaginary != 0) {
                break;
            }

        }

        ComplexNumber add = addComplexNumber(num1, num2);
        ComplexNumber substract = subtractComplexNumber(num1, num2);
        ComplexNumber multiply = multiplyComplexNumber(num1, num2);
        ComplexNumber divide = divideComplexNumber(num1, num2);

        cout << "Results: " << endl;
        cout << "   Addition Results: ";
        displayComplexNumber(add);

        cout << "   Subtract Results: ";
        displayComplexNumber(substract);

        cout << "   Multiply Results: ";
        displayComplexNumber(multiply);

        cout << "   Division Results: ";
        displayComplexNumber(divide);
        cout << "Run again (y or Y) or any other character to end?" << endl;
        cin >> input;
    } while (input == 'Y' || input == 'y');
    return 0;
}