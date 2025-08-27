#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int si, int mid, int ei) {
    vector<int> temp;
    int i = si;
    int j = mid + 1;

    // Merge the two halves
    while (i <= mid && j <= ei) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    // Copy remaining elements from left half
    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    // Copy remaining elements from right half
    while (j <= ei) {
        temp.push_back(arr[j++]);
    }

    // Copy sorted temp array back into original array
    for (int idx = si, x = 0; idx <= ei; idx++, x++) {
        arr[idx] = temp[x];
    }
}

void mergeSort(int arr[], int si, int ei) { // tc -> O(n log n), sc -> o(n)
    if (si >= ei) return; // Base case

    int mid = si + (ei - si) / 2;

    mergeSort(arr, si, mid);     // Sort left half
    mergeSort(arr, mid + 1, ei); // Sort right half

    merge(arr, si, mid, ei);     // Merge sorted halves
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {6, 3, 7, 5, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArr(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArr(arr, n);

    return 0;
}
