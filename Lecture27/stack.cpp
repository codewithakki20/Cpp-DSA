#include <bits/stdc++.h>
using namespace std;

//create stack using vector
template <class T>
class Stack {
    vector<T> vec;

public: 
    // push element to stack
    void push(T val) { // O(1)
        vec.push_back(val);
    }

    // pop element from stack
    void pop() { // O(1)
        if (isEmpty()) {
            cout << "Stack is empty.\n";
            return;
        }
        vec.pop_back();
    }

    // return top element
    T top() { // O(1)
        // if (isEmpty()) {
        //     cout << "Stack is empty.\n";
        //     return -1;
        // }
        int lastIdx = vec.size() - 1;
        return vec[lastIdx];
    }

    // check if empty
    bool isEmpty() { // O(1)
        return vec.size() == 0;
    }
};

int main() {
    Stack <string> s;

    s.push("code");
    s.push("with");
    s.push("akki");

    while (!s.isEmpty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
