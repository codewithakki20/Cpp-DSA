#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int si, int ei, int tar) {//0(logn)
    // base case
    if (si > ei) return -1; 

    int mid = si + (ei - si) / 2;

    if (arr[mid] == tar) {
        return mid;
    }

    if (arr[si] <= arr[mid]) {
        // left half sorted
        if (arr[si] <= tar && tar <= arr[mid]) {
            return search(arr, si, mid - 1, tar);
        } else {
            return search(arr, mid + 1, ei, tar);
        }
    } else {
        // right half sorted
        if (arr[mid] <= tar && tar <= arr[ei]) {
            return search(arr, mid + 1, ei, tar);
        } else {
            return search(arr, si, mid - 1, tar);
        }
    }
}

int main() {
    int arr[7] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;

    cout << "idx: " << search(arr, 0, n - 1, 2) << endl;
    return 0;
}
