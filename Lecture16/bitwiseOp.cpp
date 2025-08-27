#include <iostream>
#include <vector>
using namespace std;

int main() {
    //bitwise AND &
    cout << "bitwise AND : " << (3 & 5) << endl;

    //bitwise OR |
    cout << "bitwise OR : " << (3 | 5) << endl;

    //bitwise XOR ^
    cout << "bitwise XOR : " << (3 ^ 5) << endl;

    //bitWise NOT(1's Complemwnt)
    cout << "bitwise NOT : " << (~6) << endl;

    //bitwise Left Shift << & Right Shift >> (binary Shift Operators)
    cout << "left shift : " << (7 << 2) << endl;
    cout << "right shift : " << (7 >> 2) << endl;



    return 0;
}