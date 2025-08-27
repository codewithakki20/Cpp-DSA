#include <iostream>
#include <string>
using namespace std;

void binSrting1(int n, int lastPlace, string ans) {
    if (n == 0) {
        cout << ans << endl;
        return;
    }

    if(lastPlace != 1) {
        binSrting1(n-1, 0, ans+'0');
        binSrting1(n-1, 1, ans+'1');
    } else {
        binSrting1(n-1, 0, ans+'0');
    }    
}

void binSrting2(int n, string ans) {
    if (n == 0) {
        cout << ans << endl;
        return;
    }

    if(ans[ans.size()-1] != '1') {
        binSrting2(n-1, ans+'0');
        binSrting2(n-1, ans+'1');
    } else {
        binSrting2(n-1, ans+'0');
    }
}

int main() {
    string ans = "";
    // binSrting1(3, 0, ans);
    binSrting2(3, ans);
    return 0;
}