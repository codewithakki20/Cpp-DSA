#include <iostream>
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

class Fish : public Animal {
public:
    void swim() {
        eat();
        cout << "swims\n";
    }
};

class Mammal : public Animal {
public:
    void walk() {
        cout << "walks\n";
    }
};

int main() {
    Bird b1;
    b1.eat();
    b1.fly();

    Fish f1;
    f1.swim();

    Mammal m1;
    m1.breathe();
    m1.walk();

    return 0;
}
