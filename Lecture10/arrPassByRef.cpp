#include <iostream>  
using namespace std;

void printArr(int arr[], int n) {
  for(int i=0; i<n; i++) {
    cout << arr[i] << endl;
  }
  cout << endl;
}

int main() {  
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(int);
  cout << "array size = " << sizeof(arr) << endl;

  printArr(arr, n);

  return 0;
}
