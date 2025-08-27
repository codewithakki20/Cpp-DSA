#include <iostream>
#include <vector>
using namespace std;

class Student {  
    public:
    string name;
    float cgpa;

    void getPercentage() {
        cout << (cgpa * 10) << "%\n";
    }
};


int main() {
    Student s1;
    s1.name = "Ankit";
    s1.cgpa = 9.0;

    cout << s1.name << endl;
    cout << s1.cgpa << endl;
    return 0;
}