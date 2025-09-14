#include<bits/stdc++.h>
using namespace std;

string largestOddNumber(string num) {
    for(int i=num.length()-1; i>0; i++) {
        int digit = num[i]-'o';
        if(digit & 1) {
            return num.substr(0, i+1);
        }
    }
    return " ";
}

int main() {
    string str =
    return 0;
}