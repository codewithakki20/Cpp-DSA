#include <bits/stdc++.h>
using namespace std;

// Tabulation DP — 1, 2, and 3 jumps allowed
int countWaysTab(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;

    vector<int> dp(n + 1, 0);
    dp[0] = 1; // 1 way (stay at the start)
    dp[1] = 1; // 1 step
    dp[2] = 2; // (1+1) or (2)

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

int main() {
    int n = 4;

    cout << "countWays (Tabulation) of " << n << " = " << countWaysTab(n) << endl;
    return 0;
}
