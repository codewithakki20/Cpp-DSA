#include<bits/stdc++.h>
using namespace std;

void printArr(vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

void MaxAreaHistogram(vector<int> height) { // O(n)
    int n = height.size();
    vector<int> nsl(n), nsr(n);
    stack<int> s;

    // Next Smaller to Left
    for (int i = 0; i < n; i++) {
        while (!s.empty() && height[s.top()] >= height[i]) {
            s.pop();
        }
        if (s.empty()) {
            nsl[i] = -1;
        } else {
            nsl[i] = s.top();
        }
        s.push(i);
    }

    // clear stack for NSR
    while (!s.empty()) s.pop();

    // Next Smaller to Right
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && height[s.top()] >= height[i]) {
            s.pop();
        }
        if (s.empty()) {
            nsr[i] = n;
        } else {
            nsr[i] = s.top();
        }
        s.push(i);
    }

    cout << "NSL: ";
    printArr(nsl);
    cout << "NSR: ";
    printArr(nsr);

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int ht = height[i];
        int width = nsr[i] - nsl[i] - 1;
        int area = ht * width;
        maxArea = max(maxArea, area);
    }

    cout << "Max area of histogram : " << maxArea << endl;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    MaxAreaHistogram(heights);
    return 0;
}
