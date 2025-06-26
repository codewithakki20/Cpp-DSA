#include <iostream>
using namespace std;

int main() {
    int x = 2, y = 5;
    int exp1 = (x * y / x); //  5
    int exp2 = (x * (y / x)); // 4
    cout << exp1 << ", " << exp2 << "\n";
    return 0;
}
