#include <iostream>
#include <cstring>
using namespace std;

void funcInt() {
    int *ptr = new int;
    *ptr = 5;

    cout << *ptr;

    delete ptr;
}

void func() {
    int size;
    cin >> size;

    int *ptr = new int[size];


  int x = 1;
     for(int i=0; i<size; i++) {
        ptr[i] = x;
        cout << ptr[i] << " ";
        x++;
    }
    cout << endl;

    delete [] ptr; //free
}

int main() {
    funcInt();
    
   
    //  int size;
    //  cin >> size;

    //  int *arr = new int[size];

    //  int x = 1;
    //  for(int i=0; i<size; i++) {
    //     arr[i] = x;
    //     cout << arr[i] << " ";
    //     x++;
    //  }

    //  cout << endl;
    return 0;
}