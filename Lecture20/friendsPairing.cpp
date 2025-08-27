#include <iostream>
#include <vector>
using namespace std;

int friendsPairing(int n) {
    if(n == 1 || n == 2) {
        return n;
    }

    //single
    int ans1 = friendsPairing(n-1);

    //pair
    int ans2 = (n-1) * friendsPairing(n-2);

    return  ans1 + ans2;
}

int main() {
    cout << friendsPairing(4) << endl;
    return 0;
}