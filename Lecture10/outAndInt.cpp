#include <iostream>  
using namespace std;

int main() {  
    int n;
    cout << "Enter length of array0: ";
    cin >> n;
    int arr[n]; 
    ///int n = sizeof(arr) / sizeof(int);  // n = 5

    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {       // ✅ fixed condition
        cin >> arr[i];
    }

    cout << "You entered: ";
    for (int i = 0; i < n; i++) {       // ✅ fixed condition
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
