#include <iostream>
using namespace std;

int main() {
    int n;
    int res = 1;

    cout << "enter your factorial number: ";
    cin >> n;

    for(int i=n; i>0; i--) {
        res = res * i;
        
    }

    cout << "Your factorial number is " << res << endl;

    return 0;
}
