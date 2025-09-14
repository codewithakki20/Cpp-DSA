#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q) {
    stack<int> s;

    // push all elements of queue into stack
    while (!q.empty()) {
        s.push(q.front());
        q.pop();
    }

    // push all elements back into queue from stack
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

int main() {
    queue<int> q;
    for (int i=1; i <=5; i++) {   // 1..5
        q.push(i);
    }

    reverse(q);

    for(int i=1; i<=5; i++) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
