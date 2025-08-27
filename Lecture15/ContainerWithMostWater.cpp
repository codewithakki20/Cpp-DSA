#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


//O(n^2)
int maxArea1(vector<int>& height) {
    int maxWater = 0;
    int n = height.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int width = j - i;
            int minHeight = min(height[i], height[j]);
            int currWater = width * minHeight;
            maxWater = max(maxWater, currWater);
        }
    }

    return maxWater;
}

int maxArea2(vector<int>& height) {
    int n = height.size();
         
        int maxWater = 0;
        int low = 0;
        int high = n-1;
        
    
        while (low < high) {
            int width = high - low;
            int minHeight = min(height[low], height[high]);
            maxWater = max(maxWater, width * minHeight);

            if (height[low] < height[high]) {
                low++;
            } else {
                high--;
            }
        }

        return maxWater;
    }

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Total water: " << maxArea2(height) << endl;
    return 0;
}
