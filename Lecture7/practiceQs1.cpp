#include <iostream>
using namespace std;

// find the prod of 2 num a&b 

// int prod(int a, int b) {
//  return a * b; 
 
// }

//print if a num is odd & even
bool isEven(int n) {
    if(n % 2 == 0) {
        return true;
    } else {
        return false;
    }
}



int main() {
    cout <<  isEven(20);
    return 0;
}
