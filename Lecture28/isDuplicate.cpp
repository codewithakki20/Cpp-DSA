#include<bits/stdc++.h>
using namespace std;

bool isDuplicate (string str) {
    stack<char> s;

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        if(ch != ')') { // push everything except ')'
            s.push(ch);
        } else { // closing bracket found
            if(s.top() == '(') {
                return true; // duplicate found
            }

            // pop until '('
            while(!s.empty() && s.top() != '(') {
                s.pop();
            }

            if(!s.empty()) {
                s.pop(); // pop the opening '('
            }
        }
    }

    return false; // no duplicates found
}

int main() {
    string str1 =  "((a+b))";         // 1 (duplicate)
    string str2 =  "((a+b) + (c+d))"; // 0 (no duplicate)

    cout << isDuplicate(str1) << endl;
    cout << isDuplicate(str2) << endl;

    return 0;
}
