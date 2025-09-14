#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1;
    queue<int> q2;

public:
    void push(int data) {
        // Step 1: Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 2: Push new element into q1
        q1.push(data);

        // Step 3: Move everything back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        // if (q1.empty()) {
        //     cout << "Stack is EMPTY\n";
        //     return;
        // }
        q1.pop();
    }

    int top() {
        // if (q1.empty()) {
        //     cout << "Stack is EMPTY\n";
        //     return -1; // invalid value
        // }
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
