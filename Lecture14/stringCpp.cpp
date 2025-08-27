#include <iostream>
#include <cstring>
using namespace std;

int main() {
    //input from user
    // string str;
    // getline(cin, str);
    // cout << str << endl;

    //for each loop
    // string str = "code with akki";
    // for(int i=0; i<str.length(); i++){
    //     cout << str[i] << " ";
    // }
    // cout << "\n";

    // for(char ch : str) {
    //     cout << ch << ",";
    // }

    //member functions
    string str = "code with akki";
    
    cout << str.length() << endl;
    cout <<str.at(3) << endl;
    cout << str.substr(5,4) << endl;
    cout << str.find("akkii");
    return 0;
}