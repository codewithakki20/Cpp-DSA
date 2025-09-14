#include<bits/stdc++.h>
using namespace std;

void firstNonRepeat(string str) { // O(n)
    queue<char> Q;
    int freq[26] = {0};

    for(int i=0; i<str.size(); i++) {
        char ch = str[i];
        Q.push(ch);
        freq[ch-'a']++;

        // Remove all repeating characters from front
        while(!Q.empty() && freq[Q.front() - 'a'] > 1) {
            Q.pop();
        }

        // Print current answer
        if(Q.empty()) {
            cout << "-1 ";
        } else {
            cout << Q.front() << " ";
        }
    }
    cout << "\n";
}

int main() {
    string str = "aabccxb";

    firstNonRepeat(str); 
    return 0;
}
