#include <iostream>
using namespace std;

int main() {
int a, b;
char op;

cout << "enter a : " << endl;
cin >> a;
cout << "enter b : " << endl;
cin >> b;
cout << "enter op :";
cin >> op;

// else&&if calculator
// if (op == '+') {
//     cout <<  "a + b = " << (a+b) << endl;
// } else if (op == '-') {
//     cout <<  "a - b = " << (a-b) << endl;
// } else if (op == '*') {
//     cout <<  "a * b = " << (a*b) << endl;
// } else if (op == '/') {
//     cout <<  "a / b = " << (a/b) << endl;
// } else {
//     cout << "Invalad OP" << endl;
// }

// Switch
switch (op) {
    case '+' : cout <<  "a + b = " << (a+b) << endl;
    break;
    case '-' : cout <<  "a - b = " << (a-b) << endl;
    break;
    case '*' : cout <<  "a * b = " << (a*b) << endl;
    break;
    case '/' : cout <<  "a / b = " << (a/b) << endl;
    break;
    default : cout << "Invalad OP" << endl;
}

     return 0;
}