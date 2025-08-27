#include <iostream>
#include <vector>
using namespace std;


class Animal {
public:    
     string color;
     void eat() {
        cout << "eats\n";
     }

     void breathe() {
        cout << "brathes\n";
     }
};

class Fish : public Animal {
public:
    int fins;

    void swin() {
        eat();
        cout << "swmis\n";
    }
};



int main() {
    Fish f1;
    f1.fins = 2;
    cout << f1.fins << endl;
    f1.swin();
    f1.eat();
    f1.breathe();
    return 0;
}