#include <bits/stdc++.h>
using namespace std;

// problem nub. leetcode 151
class Solution {
public:
    string reverseWords(string s) {
        string temp = "";
        stack<string> st;

        for (int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // not a space
            if (ch != ' ') {
                temp += ch;
            } else {
                if (temp.size() > 0) {
                    st.push(temp);
                    temp = "";
                }
            }
        }

        // when there is no spacr  after the last word and temp has the last word
        if (temp.size() > 0) {
            st.push(temp);
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += " ";
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "  hello   world  ";
    string s = "the sky is blue";
    string s = "a good   example";
    cout << sol.reverseWords(s) << endl; // Output: "world hello"
    return 0;
}
