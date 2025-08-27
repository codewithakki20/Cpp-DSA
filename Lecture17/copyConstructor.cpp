#include <iostream>
#include <vector>
using namespace std;

class Car {
    public:
       string name;
       string color;
    
    Car(string name, string color) {
        this->name = name;
        this->color =color;
    }

    //custom copy constructor
    Car(Car &original) {
        cout << "coping original to new..\n";
        name = original.name;
        color = original.color;
    }
    
};

int main() {
    Car c1("maruti 800", "white");

    Car c2(c1);
    cout << c2.name << endl;
    cout << c2.color << endl;
    return 0;
}