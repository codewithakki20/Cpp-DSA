#include <iostream>
#include <vector>
using namespace std;

int conutSetBits(int num) {
    int count = 0;

    while (num > 0)
    {
        int lastDit = num & 1;
        count += lastDit;

        num = num >> 1;
    }
    cout << count << endl;
    return count;
}

int main() {
    conutSetBits(31);
    return 0;
}