#include <bits/stdc++.h>
using namespace std;

class Stack {
    deque<int> deq;
public:
    void push(int data) {
        deq.push_front(data);
    }

    void pop() {
        if (!deq.empty()) 
            deq.pop_front();
    }

    int top() {
        return deq.front();
    }

    bool empty() {
        return deq.empty();
    }
};

int main() {
    Stack s;

    for (int i = 1; i <= 5; i++) {
        s.push(i);
    }

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}
