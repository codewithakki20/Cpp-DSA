#include <iostream>  
using namespace std;

int binSearch(int *arr, int n, int key) {
    int st = 0, end = n - 1;

    while (st <= end) {
        int mid = (st + end) / 2;
        if (arr[mid] == key) {
            return mid; // key found
        } else if (arr[mid] < key) {
            st = mid + 1; // search in right half
        } else {
            end = mid - 1; // search in left half
        }
    }
    return -1; // key not found
}

int main() {  
    int arr[] = {2, 4, 6, 8, 10, 12, 14, 16};
    int n = sizeof(arr) / sizeof(int);

    int index = binSearch(arr, n, 16); // key = 12
    cout << "Index: " << index << endl; // prints -1 if not found
    return 0;
}
