#include<bits/stdc++.h>

using namespace std;

void pushAtBottom(stack<int> &s, int val){ //o(n)

    if(s.empty()) {
        s.push(val); //push at top = push at bottom
        return;
    }

    int temp = s.top();
    s.pop();
    pushAtBottom(s, val);
    s.push(temp);

}

void printStack(stack<int> s) {
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";
}

void reverse(stack<int> &s) {//O(n)
    if(s.empty()) {
       return;
    }

    int temp = s.top();
    s.pop();
    reverse(s);
    pushAtBottom(s, temp);
}

int main() {
    stack<int> s;

    s.push(3);
    s.push(2);
    s.push(1);
    printStack(s);

    reverse(s);
    printStack(s);

    return 0;
}