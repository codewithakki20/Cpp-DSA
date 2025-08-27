#include<bits/stdc++.h>

using namespace std;

void permutaions(string str, string ans) {
    int n = str.size();
    if(n == 0) {
        cout << ans << "\n";
    }
    
    for(int i=0; i<str.size(); i++) {
        char ch = str[i];

       string nextStr = str.substr(0, i) + str.substr(i+1, n-i-1);

        permutaions(nextStr , ans + ch);//ith char choice to add in perm
    }
}

int main() {
    string str = "abc";
    string ans = "";
    permutaions(str, ans);
    return 0;
}