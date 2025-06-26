#include <iostream>
using namespace std;

int ditSum(int n) {
    int res = 0;

    while (n >0)
    {
        res +=n % 10;
        n = n/10;
    }
    return res;
}


int main() {
    cout << ditSum(120) << endl;
    //  "Hello World" 
    return 0;
}
