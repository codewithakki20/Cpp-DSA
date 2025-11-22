#include <bits/stdc++.h>
using namespace std;

// Recursive Brute Force
int countWaysRec(int n) { //O(2ⁿ) & O(n)
    if (n == 0 || n == 1)
        return 1;

    return countWaysRec(n - 1) + countWaysRec(n - 2);
}

// Memoization DP
int countWaysMemo(int n, vector<int> &dp) {// O(n) & O(n)
    if (n == 0 || n == 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    dp[n] = countWaysMemo(n - 1, dp) + countWaysMemo(n - 2, dp);
    return dp[n];
}

// Tabulation DP
int countWaysTab(int n) { //O(n) & O(n)
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int main() {
    int n = 4;
    vector<int> dp(n + 1, -1);

    cout << "countWays (Recursive) of " << n << " = " << countWaysRec(n) << endl;
    cout << "countWays (Memoization) of " << n << " = " << countWaysMemo(n, dp) << endl;
    cout << "countWays (Tabulation) of " << n << " = " << countWaysTab(n) << endl;

    return 0;
}
