#include <iostream>
using namespace std;

int main() {

    // and &&
    cout << ((3 > 5) && (5 < 3)) << endl; //false

    // or || 
    cout << ((3 < 5) || (5 > 3)) << endl;// true

    //Not !
    cout << (!(3 > 5)) << endl;// true

    return 0;
}