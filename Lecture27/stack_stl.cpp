#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main() {
    //STL stack
    stack <string> s;

    s.push("akki");
    s.push("with");
    s.push("code");
    
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
