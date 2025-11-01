#include <bits/stdc++.h>
using namespace std;

void majorityElement(vector<int> nums) {
    unordered_map<int, int> m;

    for (int i = 0; i < nums.size(); i++) {
        m[nums[i]]++;
    }

    for (auto p : m) {
        if (p.second > nums.size() / 3) {
            cout << p.first << " ";
        }
    }

    cout << endl;
}

int main() {
    vector<int> nums = {1, 3, 2, 5, 1, 3, 1, 5, 1};
    vector<int> nums1 = {1, 2};

    majorityElement(nums);

    return 0;
}
