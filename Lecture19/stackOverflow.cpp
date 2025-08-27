#include <iostream>
#include <vector>
using namespace std;

void func() {
    cout << "stack overflow...\n";
    func();
}

int main() {
    func();
    return 0;
}