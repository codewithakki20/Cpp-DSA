#include <iostream>   
using namespace std;

//pass by value
void changeA(int a) {
    a = 20;
    cout << a << "\n";
}

//pass by rference using Pointer
void changeB(int *ptr) {
    *ptr = 20;
    cout << ptr << "\n";
}


int main() {
    int a = 10; 
    changeB(&a);

    cout << a << endl;
    

    return 0;
}
