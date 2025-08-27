#include <iostream>
#include <vector>
using namespace std;

class Car {
    string name;
    string color;

public:
 Car(){
        cout << "constructor without params\n"; // non-parmaterized  constructor
    }
    Car(string name, string color){
        cout << "constructor is calles. object being ceated..\n";//parmaterized  constructor
        this->name = name;
        this->color = color;
    }
    void start() {
        cout << "car has started..";
    }

    void stop() {
        cout << "car has stopped\n";
    }

    //Getter
    string getName() {
        return name;
    }

    string getColor() {
        return color;
    }
};

int main() {
    Car c0; //non-parameter
    Car c1("maruti 800", "white");// parameter
    Car c2("fortuner", "pink");// parameter
    return 0;
}