#include <iostream>
#include <algorithm>
using namespace std;

void printArr(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Ascending Order
    int arr1[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    sort(arr1, arr1 + 8);         
    cout << "Ascending: ";
    printArr(arr1, 8);

    // Descending Order
    int arr2[8] = {1, 4, 1, 3, 2, 4, 3, 7};
    sort(arr2, arr2 + 8, greater<int>());         
    cout << "Descending: ";
    printArr(arr2, 8);

    return 0;
}
