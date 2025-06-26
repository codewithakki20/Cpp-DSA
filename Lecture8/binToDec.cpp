#include <iostream>
using namespace std;

void binToDec(int bitNum) {
    int n = bitNum;
    int decNum = 0;
    int pow = 1;

    while(n > 0) {
        int lastDig = n % 10;          // Extract last binary digit
        decNum += lastDig * pow;       // Add to decimal
        pow *= 2;                    // Increase power of 2
        n = n / 10;                    // Remove last digit
    }

    cout << "Decimal: " << decNum << endl;
}

int main() {
    binToDec(110010);  // ✅ Corrected function name
    return 0;
}
