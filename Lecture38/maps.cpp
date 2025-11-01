#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main() {
    map<string, int> m;

    m["China"] =  150;
    m["India"] = 50;
    m["US"] = 40;
    m["Nepal"] = 10;
    m["India"] = 200;

    for(pair<string , int> country: m) {
        cout << country.first<< ", " << country.second << endl;
    }

   

    if(m.count("Ankit")) {
        cout << "Ankit exists\n";
    } else {
        cout << "Ankit dosen't exists\n";
    }
    return 0;
}