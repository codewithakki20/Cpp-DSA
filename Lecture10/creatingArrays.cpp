#include <iostream>  
using namespace std;

int main() {  
    int marks[5] = {1, 2, 3, 4, 5};               // Declares an array of size 5 (indexes 0 to 4)
    int n = sizeof(marks) / sizeof(int);
    cout << sizeof(marks) / sizeof(int)<< endl;  
 
    return 0;
}
