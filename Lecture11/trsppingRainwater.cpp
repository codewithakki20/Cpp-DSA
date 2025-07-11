#include <iostream>
#include <climits>
using namespace std;

int trap(int height[], int n) {
    int leftMax[200000];
    int rightMax[200000];

    // Fill leftMax array
    leftMax[0] = height[0];
    for(int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Fill rightMax array
    rightMax[n - 1] = height[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int waterTrapped = 0;
    for(int i = 0; i < n; i++) {
        int currWater = min(leftMax[i], rightMax[i]) - height[i];
        if(currWater > 0) {
            waterTrapped += currWater;
        }
    }

    return waterTrapped;
}

int main() {
    int height[7] = {4, 2, 0, 6, 3, 2, 5};
    int n = sizeof(height) / sizeof(int);

    int result = trap(height, n);
    cout << "Total Water Trapped = " << result << " units" << endl;

    return 0;
}
