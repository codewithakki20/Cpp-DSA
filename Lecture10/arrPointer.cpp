#include <iostream>
using namespace std;

// void printArr(int *ptr, int n) {
//     for(int i=0; i<n; i++) {
//         cout << *(ptr+i) << "\n";
//     }
// }


int main() {
// int arr[] = {1, 2, 3, 4, 5,};            // char literal stored in int
// int n = sizeof(arr) / sizeof(int);

// int *aptr = &ch;         // pointer to int

//1. incr & Decr operator 
// cout << aptr << "\n";    // prints address of ch
// aptr++;                  // moves pointer to next int (4 bytes ahead)
// cout << aptr << "\n";
// aptr--;                  // moves back to original address
// cout << aptr << "\n";

// 2. add & sub of constants
// cout << aptr << "\n";       // prints address of a
// aptr = aptr + 3;            // moves 3 * sizeof(int) bytes forward
// cout << (aptr - 3) << "\n"; // subtracts 3 ints (returns to original address)

//3. Add & sub of pointers
int arr[20] = {1, 3, 4, 5, 6};
int *ptr1 = arr;         // points to arr[0]
int *ptr2 = ptr1 + 3;    // points to arr[3]

// cout << *ptr2 << "\n";   // prints value at arr[3] → 5
// cout << *ptr1 << "\n";   // prints value at arr[0] → 1


// cout << ptr2 - ptr1;     // prints how many elements apart the pointers are

// Comparison 
cout << (ptr2 < ptr1) << "\n"; //  true : 1 / falsa : 0


// printArr(arr, n);

    return 0;
}
