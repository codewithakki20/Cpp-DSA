#include <iostream>
#include <vector>
using namespace std;


class Animal {
public:
    void eat() {
        cout << "eats\n";
    }

    void breathe() {
        cout << "breathes\n";
    }
};

class Bird : public Animal {
public:
    void fly() {
        cout << "flying\n";
    }
};

class Mammal : public Animal {
public:
    void walk() {
        cout << "walks\n";
    }
};

class Dog : public Mammal {
public:
   void tailWag() {
    cout << "wagging tail\n";
}

};

int main() {
    Bird b1;
    b1.eat();
    b1.fly();

    Dog d1;
    d1.walk();
    d1.tailWag();
    return 0;
}