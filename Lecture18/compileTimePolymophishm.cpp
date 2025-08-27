#include <iostream>
#include <vector>
using namespace std;

//functionOverloading
// class Print {
// public:
//     void show(int x) {
//         cout << "int: " << x << endl;
//     }
//     void show(string str) {
//         cout << "string: " << str << endl;
//     }
// };

//operatorOverloading
class Complex {
    int real;
    int img;

public:
    Complex(int r, int i) {
        real = r;
        img = i;
    }

    void showNum() {
        cout << real << " + " << img << "i\n";
    }

    // Corrected operator+
    Complex operator + (Complex &c2) {
        int resReal = this->real + c2.real;
        int resImg = this->img + c2.img;
        Complex c3(resReal, resImg);
        return c3;
    }
};



int main() {
//functionOverloading
    // Print obj1;
    // obj1.show(21);
    // obj1.show("hello");

//operatorOverloading
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3 = c1 + c2;
    c3.showNum(); 
    return 0;
} 