#include <iostream>
using namespace std;

// Base class
class Person {
protected:
    string name; 
    int age;

public:
    // Parameterized constructor
    Person(string n, int a) {
        name = n;
        age = a;
    }
};

// Derived class
class Student : public Person {
private:
    string studentID;

public:
    // Constructor for Student which calls Person's constructor
    Student(string n, int a, string id) : Person(n, a) {
        studentID = id;
    }

    // Method to display student info
    void displayStudentInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Student ID: " << studentID << endl;
    }
};

int main() {
    Student student("Alice", 20, "S12345");
    student.displayStudentInfo();

    return 0;
}
