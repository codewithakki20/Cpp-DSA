#include <iostream> 
#include <climits>  
using namespace std;

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countingSort(int arr[], int n){
    int minVal = INT_MAX, maxVal = INT_MIN; 
    
    // Step 1: Find min and max
    for(int i = 0; i < n; i++) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]); 
    }

    // Step 2: Create freq array 
    int freq[100000] = {0};  // Enough size for non-negative values
     //t.c. O(n)
    for(int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Step 3: Rebuild the array //t.c. O(range) = max - min
    for(int i = minVal, j = 0; i <= maxVal; i++) {  
        while (freq[i] > 0) {
            arr[j++] = i;
            freq[i]--;
        }
    }

    printArr(arr, n);
}

int main() {
    int arr[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    countingSort(arr, 8);
    return 0;
}
