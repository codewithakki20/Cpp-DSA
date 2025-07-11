#include <iostream>
using namespace std;

string decimalToBinary(int n) {
    
    string binary = "";

    while (n!=0)
    {
        if(n%2==0) {
        binary="0"+binary;
        } else {
            binary="1"+binary;
           
        } 
         n=n/2;
        
    }
    return binary;
    
}

int main() {
    int num = 15;
    cout << decimalToBinary(num) << endl;
    return 0;
}
