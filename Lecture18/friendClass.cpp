#include <iostream>
#include <vector>
using namespace std;

//friend class
class A {
    string secret = "secret data..";
    friend class B;
    friend void revealSecret(A &obj);
};

class B {// becomes a friend class of A
public:
    void showSecret(A &obj) {
        cout << obj.secret << endl;
    }
};

//friend fux
void revealSecret(A &obj)  {
    cout << obj.secret << endl;
}  


int main() {
    A a1;
    B b1;

    // b1.showSecret(a1);
    revealSecret(a1);
    return 0;
}