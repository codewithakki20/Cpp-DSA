#include <iostream>   
using namespace std;

void printArr(int arr[], int n) {
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        bool isSwap = false;
        cout << "outer loop" << endl;
        for(int j=0; j<n-i-1; j++) {
            cout << " inner loop" << endl;
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){
            return;
        }
    }
    printArr(arr, n);
}

int main() {
    int arr[10] = {20, 40, 13, 8, 232, 16, 14, 15, 18, 2};
    bubbleSort(arr, 10);
    return 0;
}
