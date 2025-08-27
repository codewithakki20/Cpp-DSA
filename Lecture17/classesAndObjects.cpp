#include <iostream>
#include <vector>
using namespace std;

class Student {
    //Properties
    string name;
    float cgpa;

    //Methods
    void getPercentage() {
        cout << (cgpa * 10) << "%\n";
    }
};

class User {
    string username;
    string password;
    string bio;

    void deactivate() {
        cout << " deleting acc\n";
    }

    void editBio(string newBio) {
        bio = newBio;

    }
};

int main() {
    Student s1;//object
    cout << sizeof(s1) << endl;

    User u1;
    cout << sizeof(u1) << endl;
    return 0;
}