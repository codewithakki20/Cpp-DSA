#include <bits/stdc++.h>
using namespace std;

// Recursive Brute Force
int fib(int n) {
    if (n == 0 || n == 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

//DP Memoization
int fibDP(int n, vector<int> &f) {
    if (n == 0 || n == 1)
        return n;

    if (f[n] != -1)
        return f[n];

    f[n] = fibDP(n - 1, f) + fibDP(n - 2, f);
    return f[n];
}

// DP Tabulation 
int fibDP2(int n) {
    vector<int> fib(n + 1, 0);
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
}

int main() {
    int n = 6;
    vector<int> f(n + 1, -1);

    cout << "Fibonacci (Recursive) of " << n << " = " << fib(n) << endl;
    cout << "Fibonacci (Memoization) of " << n << " = " << fibDP(n, f) << endl;
    cout << "Fibonacci (Tabulation) of " << n << " = " << fibDP2(n) << endl;

    return 0;
}
