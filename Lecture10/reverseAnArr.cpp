#include <iostream>  
using namespace std;

void printArr(int *arr, int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << ",";
    }
}


int main() {  
   int arr[] = {5, 4, 3, 9, 2};
   int n = sizeof(arr) / sizeof(int);

//using extra space
//    int copyArr[n];
//    for(int i=0; i<n; i++){
//     int j = n-i-1;
//     copyArr[i] = arr[j];
//    }

//    for(int i=0; i<n; i++) {
//     arr[i] = copyArr[i];
//    }

// without using extra space
int st = 0, end = n-1;

while (st < end) 
{
 int temp = arr[st];
 arr[st] = arr[end];
 arr[end] = temp;
 st++;
 end--;
}


   printArr(arr, n);
    return 0;
}
