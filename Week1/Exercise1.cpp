#include <iostream>

// Power Function

double powerRecursive(double a, int n) {
    if (n == 0)
        return 1;
    else if (n > 0)
        return a * powerRecursive(a, n - 1);
    else
        return 1 / (a * powerRecursive(a, -n - 1));
}

double powerNonRecursive(double a, int n) {
    double result = 1.0;
    if (n >= 0) {
        for (int i = 0; i < n; ++i) {
            result *= a;
        }
    } else {
        for (int i = 0; i > n; --i) {
            result /= a;
        }
    }
    return result;
}

// Number Reversal

int reverseNumberRecursive(int num, int reversedNum) {
    if (num == 0)
        return reversedNum;
    else
        return reverseNumberRecursive(num / 10, reversedNum * 10 + num % 10);
}

int reverseNumberNonRecursive(int num) {
    int reversedNum = 0;
    while (num != 0) {
        reversedNum = reversedNum * 10 + num % 10;
        num /= 10;
    }
    return reversedNum;
}

int main() {
    // Power Calculation
    double base;
    int exponent;
    std::cout << "Enter the base: ";
    std::cin >> base;
    std::cout << "Enter the exponent: ";
    std::cin >> exponent;

    double recursivePowerResult = powerRecursive(base, exponent);
    double nonRecursivePowerResult = powerNonRecursive(base, exponent);

    std::cout << base << " raised to the power " << exponent << " using recursive method is: " << recursivePowerResult << std::endl;
    std::cout << base << " raised to the power " << exponent << " using non-recursive method is: " << nonRecursivePowerResult << std::endl;

    // Number Reversal
    int originalNumber = 379;
    int recursiveReversedNumber = reverseNumberRecursive(originalNumber, 0);
    int nonRecursiveReversedNumber = reverseNumberNonRecursive(originalNumber);

    std::cout << "Original Number: " << originalNumber << std::endl;
    std::cout << "Reversed Number using recursion: " << recursiveReversedNumber << std::endl;
    std::cout << "Reversed Number using non-recursion: " << nonRecursiveReversedNumber << std::endl;

    return 0;
}
