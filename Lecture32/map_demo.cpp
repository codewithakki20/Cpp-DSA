#include<iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<int, string> m;

    m[101] = "rahul c2 ";
    m[110] = "neha";
    m[131] = "rahul c2 ";

    for(auto it : m) {
        // cout << "key = " << it.first << "," << " value = " << it.second << endl;

        cout << "double = "  << it.first * 2 << endl;
       }
    return 0;
}