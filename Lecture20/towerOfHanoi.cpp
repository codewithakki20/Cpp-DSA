#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char source, char dest, char helper) {
    if (n == 0) {
        return;
    }

    towerOfHanoi(n - 1, source, helper, dest);

    cout << "Move disk " << n << " from rod " << source << " to rod " << dest << endl;
   
    towerOfHanoi(n - 1, helper, dest, source);
}

int main() {
    int n = 3;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
