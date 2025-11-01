#include <iostream>
#include <queue>
using namespace std;

int main() {
    
    priority_queue<int> pq; // max heap
    priority_queue<int, vector<int>, greater<int>> pq1; // min heap

    // Max heap insert
    pq.push(2);
    pq.push(3);
    pq.push(10);
    pq.push(5);
    pq.push(9);

    cout << "Max Heap:" << endl;
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    // Min heap insert
    pq1.push(2);
    pq1.push(3);
    pq1.push(10);
    pq1.push(5);
    pq1.push(9);

    cout << "Min Heap:" << endl;
    while(!pq1.empty()) {
        cout << pq1.top() << " "; 
        pq1.pop();
    }
    cout << endl;

    return 0;  
}
