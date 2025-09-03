#include<bits/stdc++.h>

using namespace std;

// problem nub. leetcode 1047
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;

        for(int i=0; i<s.length(); i++) {
            char ch = s[i];

            //stack has top element and it is same as current charcter
            if (st.size()>0 && st.top() == ch) {
                st.pop();

            // either stack was empty or top character was not same as current character
            } else {
                st.push(ch);
            }

        }

        string ans = "";

        while(st.size()>0){
            ans+= st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};



int main() {

    return 0;
}