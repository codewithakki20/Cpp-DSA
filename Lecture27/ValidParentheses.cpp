#include<bits/stdc++.h>

using namespace std;

bool isValid(string s) {
    stack<char> st;

    if(s.size() %2==1) {
        return false;
    }

    for(int i=0; i<s.size(); i++) {
        if(s[i]=='{' or s[i]=='[' or s[i]=='('){
            st.push(s[i]);
        } else {//closing bracket
        if(st.size()==0){
            return false;
        }else if (s[i]== ']' and st.top()!='[') {
            return false;
        } else if (s[i]==')' and st.top()!='(' ) {
            return false;
        }
        st.pop();
        }
    }

    if(st.size()==0) {
        return true;
    } else {
        return false;
    }
    }

int main() {
    cout << isValid("()[]{}") << endl;   // 1 (true)
    cout << isValid("(]") << endl;       // 0 (false)
    cout << isValid("([{}])") << endl;   // 1 (true)
    cout << isValid("(((") << endl;      // 0 (false)
    return 0;
}