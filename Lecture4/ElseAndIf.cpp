#include <iostream>
using namespace std;

int main() {
    int marks;
    cout << "enter your marks : " << endl;
    cin >> marks;

    if (marks >=90) {
        cout << "A+" << endl;
    } else if (marks >= 80) {
        cout << "B+" << endl; 
    } else if (marks >= 70) {
        cout << "A" << endl;
    } else if (marks >= 60) {
        cout << "B" << endl;
    } else {
        cout << "C" << endl;
    }



     return 0;
}