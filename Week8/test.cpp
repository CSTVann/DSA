#include <iostream>
using namespace std;

int main() {
    char choice;
    string one;

    cout << "1:   Constant time — O(1)" << endl;
    cout << "2:   Logarithmictime—O(logn)" << endl;
    cout << "3:   Linear time — O(n)" << endl;
    cout << "4:   Quadratictime—O(n2)" << endl;
    cout << "5:   Linear time — O(n + m)" << endl;

    cout << "Enter your choice:  ";
    cin >> choice;

    switch (choice) {
        case '1':
            cin.ignore(); // Clear the newline character left in the input buffer
            cout<<"Enter the constant time — O(1):  ";
            getline(cin, one);
            cout <<"The Constant time — O(1):   "<< one <<endl;
            break;
        case '2':
            cout << "Two";
            break;
    }

    return 0;
}
