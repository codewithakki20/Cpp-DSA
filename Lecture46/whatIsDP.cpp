#include <bits/stdc++.h>
using namespace std;

// Overlapping Subproblems — Recursive Sum
int sum(int n) {
    if(n == 1)
        return 1;
    return sum(n - 1) + n;
}

// Optimal Substructure — Fibonacci with DP 
int fib(int n, vector<int> &f) {
    if(n == 0 || n == 1)
        return n;

    if(f[n] != -1)
        return f[n];

    f[n] = fib(n - 1, f) + fib(n - 2, f);
    return f[n];
}

int main() {
    int n = 6;

    // Sum
    cout << "Sum from 1 to " << n << " = " << sum(n) << endl;

    // Fibonacci
    vector<int> f(n + 1, -1);
    cout << "Fibonacci of " << n << " = " << fib(n, f) << endl;

    return 0;
}
