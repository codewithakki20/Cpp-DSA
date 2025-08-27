#include <iostream>
#include <vector>
using namespace std;

int fibonacci(int n)  {
    if(n == 0 || n == 1) {
        return n; //0, 1
    }
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    cout << "fibonacci num of n : " << fibonacci(3) << endl;
    return 0;
}

// Function Call
// fibonacci(3)
// ├─ fibonacci(2)
// │  ├─ fibonacci(1) → returns 1
// │  └─ fibonacci(0) → returns 0
// │      → fibonacci(2) = 1 + 0 = 1
// └─ fibonacci(1) → returns 1
//     → fibonacci(3) = 1 + 1 = 2


// Call Stack (Top to Bottom)
// ---------------------------
// fibonacci(3)       <-- Initial call
// ├─ fibonacci(2)    <-- Called by fibonacci(3)
// │  ├─ fibonacci(1) <-- Called by fibonacci(2), returns 1
// │  └─ fibonacci(0) <-- Called by fibonacci(2), returns 0
// ├─ fibonacci(1)    <-- Called by fibonacci(3), returns 1