#include<bits/stdc++.h>
using namespace std;

int gridWays(int row, int col, int n, int m, string ans) {
    // base case: reached destination
    if(row == n-1 && col == m-1) {
        cout << ans << "\n";
        return 1;
    }

    // boundary case: out of grid
    if(row >= n || col >= m) {
        return 0;
    }

    // move right
    int v1 = gridWays(row, col + 1, n, m, ans+"R");

    // move down
    int v2 = gridWays(row + 1, col, n, m, ans+"D");

    return v1 + v2;
}

int main() {
    int n = 4, m = 4;
    string ans = "";
    cout << gridWays(0, 0, n, m, ans) << endl;  // Expected output = 6
    
    return 0;
}
