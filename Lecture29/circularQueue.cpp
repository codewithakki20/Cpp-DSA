#include<bits/stdc++.h>
using namespace std;

class Queue {
    int* arr;
    int capacity;
    int currSize;
    int f, r;

public:
    Queue(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        currSize = 0;
        f = 0;
        r = -1;
    }

    void push(int data) {//O(n)
        if(currSize == capacity) {
            cout << "Queue is FULL\n";
            return;
        }
        r = (r + 1) % capacity;   // circular increment
        arr[r] = data;            // store element
        currSize++;
    }

    void pop() {//O(n)
        if(empty()) {
            cout << "Queue is EMPTY\n";
            return;
        }
        f = (f + 1) % capacity;   // circular increment
        currSize--;
    }

    int front() {//O(n)
        if(empty()) {
            cout << "Queue is EMPTY\n";
            return -1; // return invalid value
        }
        return arr[f];
    }

    bool empty() {
        return currSize == 0;
    }
};

int main() {
    Queue q(4);

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5); // prints "Queue is FULL" 

    cout << q.front() << endl;  // 1

    q.pop();
    cout << q.front() << endl;  // 2

    q.push(7);
    cout << q.front() << endl;  // 2

    return 0;
}
