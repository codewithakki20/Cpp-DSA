#include <iostream>
using namespace std;


 int sum(int a, int b) {
        return a + b;
    }

    double sum(double a, double b) {
        return a + b;
    }


int main() {
    
   cout<< sum(4, 5) << endl;
   cout << sum(2.5, 2.5) << endl;


    return 0;
}
