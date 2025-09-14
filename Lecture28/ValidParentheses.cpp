#include<bits/stdc++.h>
using namespace std;

// leetcode 20
bool isValid(string str) {//O(n)
    stack<char> s;

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        if(ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else {
            if(s.empty()) {  // if no opening bracket available
                return false;
            }

            char top = s.top();
            if((top == '(' && ch == ')') ||
               (top == '[' && ch == ']') ||
               (top == '{' && ch == '}')) {
                s.pop(); // valid pair
            } else {
                return false;
            }
        }
    }

    // If stack is empty, all brackets matched
    return s.empty();
}

int main() {
    string str1 =  "([}])";   // false
    string str2 =  "([{}])";  // true

    cout << isValid(str1) << endl; // 0
    cout << isValid(str2) << endl; // 1
    return 0;
}
