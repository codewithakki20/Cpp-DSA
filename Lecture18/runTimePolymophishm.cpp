#include <iostream>
#include <vector>
using namespace std;


// //functionOverloading
// class Parent {
//     public:
//     void show() {
//         cout << "parent class shoq..\n";
//     }
// };

// class Child : public Parent {
// public:
//    void show() {
//     cout << "child class show..\n";
//    }
// };

//Victual Function
class Parent {
    public:
    void show() {
        cout << "parent class shoq..\n";
    }

    virtual void hello() {
        cout << "parent hello\n";
    }
};

class Child : public Parent {
public:
   void show() {
    cout << "child class show..\n";
   }

    virtual void hello() {
        cout << "child hello\n";
    }
};

int main() {
    // Child child1;
    // child1.show();

    Child child1;
    Parent *ptr;
    ptr = &child1;// run time Binding
    ptr->hello();//Victual Function
    return 0;
}