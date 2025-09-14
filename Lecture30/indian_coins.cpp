#include <bits/stdc++.h>
using namespace std;

int getMinChange(vector<int> coins, int V) {// O(n) 
    int ans = 0;
    int n = coins.size();

    for (int i = n - 1; i >= 0 && V > 0; i--) {
        if (V >= coins[i]) {
            ans += V / coins[i];
            V = V % coins[i];
        }
    }

    cout << "Min coins for change = " << ans << endl;
    return ans;
}

int main() {
    // vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000}; // Indian currency
    vector<int> coins = {2, 5, 70, 80}; // Indian currency
    int V = 216;

    getMinChange(coins, V);
    return 0;
}
