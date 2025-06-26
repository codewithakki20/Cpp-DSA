#include <iostream>
using namespace std;

int main() {
//sum of digits of a num 
    //  int n = 10829;
    //  int digSum = 0;
    //  while(n > 0) {
    //     int lastDig  = n % 10;
    //    digSum += lastDig;
    //     n = n / 10;
    //  }
    //  cout << "sum = " << digSum  << endl;

//sum of odd digits of a num 
    // int n = 123456789;
    //  int digSum = 0;
    //  while(n > 0) {
    //     int lastDig  = n % 10;
    //     if (lastDig % 2 != 0) {
    //          digSum += lastDig;
    //     }
       
    //     n = n / 10;
    //  }
    //  cout << "sum = " << digSum  << endl;

//num in reverse
// int n = 10829;

// while (n > 0)
// {
//     int lastDig = n % 10;
//     cout  << lastDig;
//     n /= 10;
// }
// cout << endl;

//Reverse a given num & print the result
int n = 10829;
int res = 0;

while (n > 0)
{
    int lastDig = n % 10;
    res = res * 10 + lastDig;
    n /= 10;
}
cout << "reverse = " << res << endl;


    return 0;
}
