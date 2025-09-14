#include <bits/stdc++.h>
using namespace std;

class Queue {
    deque<int> deq;
public:
    void push(int data) {
        deq.push_back(data);
    }

    int front() {
        return deq.front();
    }

    void pop() {
        deq.pop_front();
    }

    bool empty() {
        return deq.empty();
    }
};

int main() {
    Queue q;

    for (int i = 1; i <= 5; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }

    return 0;
}
