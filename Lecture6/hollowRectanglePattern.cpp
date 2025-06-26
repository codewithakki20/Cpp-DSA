#include <iostream>
using namespace std;

int main() {
    int n = 4;

    //outer loop
    for(int i=1; i<=n; i++) {
        cout << "*";

        //inner loop
        for (int j=1; j<=n-1; j++) {
            if (i==1 || i==n){
                cout<< "*";
            } else {
                cout << " ";
            }
        }
        cout << "*" << endl;
    }
 
    return 0;
}
