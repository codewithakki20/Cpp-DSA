#include <iostream>  
using namespace std;

void printSubArrays(int *arr, int n) {
    for(int st=0; st<n; st++) {
        for(int end=st; end<n; end++) {
            // cout << "(" << st << "," << end << ") ";
            for(int i=st; i<=end; i++){
                cout << arr[i];
            }
            cout << ", ";
        }
        cout << endl;
    }
}

int main() {  
    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    printSubArrays(arr,n);
    return 0;
}
