#include <iostream>
#include <vector>
using namespace std;


//static Variables
// class Example {
// public:
//    static int x;
// };

// int Example::x = 0;

//static Object
class Example {
public:
   Example() {
    cout << "constructor..\n";
   }

   ~Example() {
    cout << "destructor..\n";
   }
};



int main() {
    int a = 0;
    if(a == 0) {
       static Example eg1;
    }

    cout << "code ending.." << endl;
    return 0;
}