#include <iostream>
#include <string>
using namespace std;

//  Version 1 – Left to right using index
void removeDuplicates1(string str, string ans, int i, int map[26]) {
    if (i == str.size()) {
        cout << "ans1 : " << ans << endl;
        return;
    }

    char ch = str[i];
    int mapIdx = ch - 'a';

    if (map[mapIdx]) { // duplicate
        removeDuplicates1(str, ans, i + 1, map);
    } else { // non-duplicate
        map[mapIdx] = true;
        removeDuplicates1(str, ans + ch, i + 1, map);
    }
}

//  Version 2 – Right to left using substr
void removeDuplicates2(string str, string ans, int map[26]) {
    if (str.size() == 0) {
        cout << "ans2 : " << ans << endl;
        return;
    }

    int n = str.size();
    char ch = str[n - 1];
    int mapIdx = ch - 'a';

    str = str.substr(0, n - 1);

    if (map[mapIdx]) { // duplicate
        removeDuplicates2(str, ans, map);
    } else { // non-duplicate
        map[mapIdx] = true;
        removeDuplicates2(str, ch + ans, map);  
    }
}

int main() {
    string str = "appnnacollege";
    string ans = "";
    int map1[26] = {false};
    int map2[26] = {false};

    removeDuplicates1(str, ans, 0, map1);  // left to right
    removeDuplicates2(str, ans, map2);    // right to left
    return 0;
}
