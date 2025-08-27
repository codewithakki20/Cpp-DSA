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
        cout << "breathes\n";
    }
};

class Mammal : public Animal {
protected:
    string bloodType;

public:
    Mammal() {
        bloodType = "warm";
    }

    string getBloodType() {
        return bloodType;
    }
};

class Dog : public Mammal {
public:
    void taiWag() {
        cout << "a Dog wags its tail\n";
    }
};

int main() {
    Dog d1;

    d1.eat();
    d1.breathe();
    d1.taiWag();
    cout << "Blood Type: " << d1.getBloodType() << endl;

    return 0;
}
