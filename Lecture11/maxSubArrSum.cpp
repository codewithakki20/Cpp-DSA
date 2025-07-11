#include <iostream>  
#include <climits> 
using namespace std;

//brute-force approach T.C. O(n³)
void maxSubarraySum1(int *arr, int n) {
    int maxSum = INT_MIN;
    for (int st = 0; st < n; st++) {
        for (int end = st; end < n; end++) {
            int currSum = 0;
            for (int i = st; i <= end; i++) {
                currSum += arr[i];
            }
            cout << currSum << ", ";
            maxSum = max(maxSum, currSum);  
        }
        cout << endl;
    }
    cout << "Maximum subarray sum = " << maxSum << endl;  
}


//optimized T.C. O(n²) 
void maxSubarraySum2(int *arr, int n) {
    int maxSum = INT_MIN;

    for (int st = 0; st < n; st++) {
        int currSum = 0;
        for (int end = st; end < n; end++) {  
            currSum += arr[end];
            maxSum = max(maxSum, currSum);
        }
    }
    cout << "Maximum subarray sum = " << maxSum << endl;
}

// Kadane's Algorithm T.C. O(n)
void maxSubarraySum3(int *arr, int n) {
    int maxSum = INT_MIN;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        currSum += arr[i];
        maxSum = max(maxSum, currSum);
        if (currSum < 0)
            currSum = 0;  // reset the sum if it goes negative
    }

    cout << "Maximum subarray sum (Kadane's) = " << maxSum << endl;
}

int main() {  
    int arr[6] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr) / sizeof(int);

    maxSubarraySum3(arr, n);
    return 0;
}
