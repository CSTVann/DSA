#include <iostream>

int fibonacciRecursive(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

void printFibonacciSeries(int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << fibonacciRecursive(i) << " ";
    }
    std::cout << std::endl;
}

int main() {
    int terms;
    std::cout << "Enter the number of terms in the Fibonacci series: ";
    std::cin >> terms;

    std::cout << "Fibonacci series using recursion: ";
    printFibonacciSeries(terms);

    return 0;
}
