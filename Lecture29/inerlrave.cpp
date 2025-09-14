#include <bits/stdc++.h>
using namespace std;

void interleave(queue<int>& org) {
    int n = org.size();
    queue<int> first;

    // Step 1: Store first half into `first`
    for (int i = 0; i < n / 2; i++) {
        first.push(org.front());
        org.pop();
    }

    // Step 2: Interleave elements
    while (!first.empty()) {
        org.push(first.front());
        first.pop();

        org.push(org.front());
        org.pop();
    }
}

int main() {
    queue<int> org;
    for (int i = 1; i <= 10; i++) {   // numbers 1..10
        org.push(i);
    }

    interleave(org);

    while (!org.empty()) {
        cout << org.front() << " ";
        org.pop();
    }
    cout << endl;

    return 0;
}
