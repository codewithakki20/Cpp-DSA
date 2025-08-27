#include <iostream>
#include <vector>
using namespace std;

bool isPowerOf2(int num) {
    if(!(num & (num-1))) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cout <<isPowerOf2(64) << endl;
    return 0;
}