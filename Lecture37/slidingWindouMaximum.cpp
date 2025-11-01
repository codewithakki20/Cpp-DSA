#include <bits/stdc++.h>
using namespace std;

void slidingWindowMax(vector<int> arr, int K) {
    // Max heap: pair<value, index>
    priority_queue<pair<int, int>> pq;

    int n = arr.size();

    // First window
    for (int i = 0; i < K; i++) {
        pq.push({arr[i], i});
    }

    cout << pq.top().first << " ";

    // Process rest of the windows
    for (int i = K; i < n; i++) {
        // Remove elements that are outside the current window
        while (!pq.empty() && pq.top().second <= i - K) {
            pq.pop();
        }

        // Push current element
        pq.push({arr[i], i});

        // Top of max-heap is the max of the current window
        cout << pq.top().first << " ";
    }
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int K = 3;
    slidingWindowMax(arr, K);
    return 0;
}
