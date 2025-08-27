#include <iostream>
using namespace std;

class Complex {
    int real;
    int img;

public:
    // Constructor
    Complex(int r = 0, int i = 0) {
        real = r;
        img = i;
    }

    // Operator Overloading: subtraction
    Complex operator - (const Complex& obj) {
        Complex res;
        res.real = this->real - obj.real;
        res.img = this->img - obj.img;
        return res;
    }

    // Display function
    void show() {
        cout << real << " + " << img << "i" << endl;
    }
};

int main() {
    Complex c1(5, 7);
    Complex c2(3, 2);
    Complex c3 = c1 - c2;
    c3.show();
    return 0;
}
