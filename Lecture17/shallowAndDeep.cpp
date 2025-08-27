#include <iostream>
#include <vector>
using namespace std;

class Car {
    public:
       string name;
       string color;
       int *mileage;
    
    Car(string name, string color) {
        this->name = name;
        this->color =color;
        mileage = new int;// Dynamic Allocation
        *mileage = 12;
    }

    // shallow custom copy constructor
    // Car(Car &original) {
    //     cout << "coping original to new..\n";
    //     name = original.name;
    //     color = original.color;
    //     mileage = original.mileage;
    // }

    // deep custom copy constructor
    Car(Car &original) {
        cout << "coping original to new..\n";
        name = original.name;
        color = original.color;
        mileage = new int;
        *mileage = *original.mileage;
    }
    
};

int main() {
    Car c1("maruti 800", "white");
    Car c2(c1);
     
    *c2.mileage = 10;
    cout << c2.name << endl;
    cout << c2.color << endl;
    cout << *c2.mileage << endl;
    

    cout << *c1.mileage << endl;
    return 0;
}