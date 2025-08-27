#include <iostream>
#include <cstring>
using namespace std;

bool isAnagram(string str1, string str2) {
    if (str1.length() != str2.length()) {
        cout << "not valid anagrams\n";
        return false;
    }

    int count[26] = {0};

    // Count characters in str1
    for (int i = 0; i < str1.length(); i++) {
        count[str1[i] - 'a']++;
    }

    // Subtract characters in str2
    for (int i = 0; i < str2.length(); i++) {
        
        if (count[str2[i] - 'a'] == 0) {
            cout << "not valid anagrams\n";
            return false;
        }
        count[str2[i] - 'a']--;
    }

    cout << "valid anagrams\n";
    return true;
}

int main() {
    string str1 = "rat";
    string str2 = "tar";
    isAnagram(str1, str2);
    return 0;
}
