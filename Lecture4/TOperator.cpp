#include <iostream>
using namespace std;

int main() {
    // isAdult check
    int age;
    cout << "Enter age: ";
    cin >> age;
    bool isAdult = (age >= 18) ? true : false;
    cout << "Is Adult? " << isAdult << endl;  // 1 = true, 0 = false

    // Largest of 2 numbers using ternary operator
    int a = 10;
    int b = 5;
    int largest = (a >= b) ? a : b;
    cout << "Largest is: " << largest << endl;

    // Odd or Even using ternary operator
    int num = 13;
    bool isEven = (num % 2 == 0) ? true : false;
    cout << "Is Even? " << isEven << endl;  // 1 = true, 0 = false

    return 0;
}
