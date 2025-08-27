#include <iostream>
#include <vector>
using namespace std;

//waf to update the ith bit in anum according to given value (0 or 1)
void clearIthBit(int num, int i) {
    int bitMask = (~0) << i;
    num = num & bitMask;

    cout << num << endl;
}


int main() {
   clearIthBit(15, 2);
    return 0;
}