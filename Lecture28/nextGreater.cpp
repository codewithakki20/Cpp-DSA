#include <bits/stdc++.h>
using namespace std;

void nextGreater(vector<int>& arr, vector<int>& ans) {
    stack<int> s;
    int idx = arr.size() - 1;

    ans[idx] = -1;
    s.push(arr[idx]);

    for (idx = idx - 1; idx >= 0; idx--) {
        int curr = arr[idx];
        while (!s.empty() && curr >= s.top()) {
            s.pop();
        }
        if (!s.empty()) ans[idx] = s.top();
        else ans[idx] = -1;

        s.push(curr);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> arr = {6, 8, 0, 1, 3};
    vector<int> ans(arr.size()); // same size as arr

    nextGreater(arr, ans);

    return 0;
}
