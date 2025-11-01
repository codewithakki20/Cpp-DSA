#include <bits/stdc++.h>
using namespace std;

bool validAnagram(string s, string t) {
    if (s.size() != t.size()) {
        return false;
    }

    unordered_map<char, int> freq;

    // Count frequency of each character in s
    for (char c : s) {
        freq[c]++;
    }

    // Decrease frequency for each character in t
    for (char c : t) {
        if (freq.count(c)) {
            freq[c]--;
            if (freq[c] == 0) {
                freq.erase(c);
            }
        } else {
            return false; 
        }
    }

    return freq.empty(); // if all counts matched
}

int main() {
    string s = "ankit";
    string t = "ankiy";

    cout << (validAnagram(s, t) ? "true" : "false") << endl;

    return 0;
}
