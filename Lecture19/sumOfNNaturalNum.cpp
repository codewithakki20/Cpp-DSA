#include <iostream>
#include <vector>
using namespace std;

int sum(int n) {
    if(n == 1) {
        return 1;
    }
    return n  + sum(n-1);
}

int main() {
    cout << "sum of N : " << sum(5) << endl;
    return 0;
}