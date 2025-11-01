#include <bits/stdc++.h>
using namespace std;

int subArrayCountWithK(vector<int> arr, int K) {
    unordered_map<int, int> m;
    m[0] = 1; // base case
    int sum = 0;
    int ans = 0;

    for (int j = 0; j < arr.size(); j++) {
        sum += arr[j];

        // Check if (sum - K) exists in the map
        if (m.count(sum - K)) {
            ans += m[sum - K];
        }

        // Increment count of current prefix sum
        m[sum]++;
    }

    return ans;
}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int K = -10;

    cout << "Subarray Count : "<< subArrayCountWithK(arr, K) << endl;

    return 0;
}
