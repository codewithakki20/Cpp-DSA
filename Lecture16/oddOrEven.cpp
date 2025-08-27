#include <iostream>
#include <vector>
using namespace std;

void oddOrEven(int num){
    if(!(num & 1)) {
        cout << "Even\n";
    } else {
        cout << "Odd\n";
    }
}

int main() {
    oddOrEven(10);
    oddOrEven(1220);
    return 0;
}