#include <iostream>  
using namespace std;

int main() {  
    int arr[] = {1, 5, 10, 9, 12};
    int n = sizeof(arr) / sizeof(int);

    int max = arr[0];
    int min = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
            // cout << "Assigning value " << arr[i] << " to max\n";
        }
        if (arr[i] < min){
            min =arr[i];
        }
    }

    cout << "Max = " << max << endl;
    cout << "Min = " << min << endl;

    return 0;
}
