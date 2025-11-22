#include <bits/stdc++.h>
using namespace std;

// Recursion
int knapsackRec(vector<int> &val, vector<int> &wt, int W, int n) {
    if (n == 0 || W == 0) return 0;

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if (itemWt <= W) {
        int include = knapsackRec(val, wt, W - itemWt, n - 1) + itemVal;
        int exclude = knapsackRec(val, wt, W, n - 1);
        return max(include, exclude);
    } else {
        return knapsackRec(val, wt, W, n - 1);
    }
}

//Memoization
int knapsackMemo(vector<int> &val, vector<int> &wt, int W, int n, vector<vector<int>> &dp) {
    if (n == 0 || W == 0) return 0;

    if (dp[n][W] != -1) return dp[n][W];

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if (itemWt <= W) {
        int include = knapsackMemo(val, wt, W - itemWt, n - 1, dp) + itemVal;
        int exclude = knapsackMemo(val, wt, W, n - 1, dp);
        dp[n][W] = max(include, exclude);
    } else {
        dp[n][W] = knapsackMemo(val, wt, W, n - 1, dp);
    }

    return dp[n][W];
}

//Tabulation
int knapsackTab(vector<int> &val, vector<int> &wt, int W, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if (itemWt <= j) {
                dp[i][j] = max(itemVal + dp[i-1][j-itemWt], dp[i-1][j]);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][W];
}


int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt  = {2, 5, 1, 3, 4};
    int W = 7;
    int n = val.size();

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));

    cout << "Recursion: " << knapsackRec(val, wt, W, n) << endl;
    cout << "Memoization: " << knapsackMemo(val, wt, W, n, dp) << endl;
    cout << "Tabulation: " << knapsackTab(val, wt, W, n) << endl;

    return 0;
}
