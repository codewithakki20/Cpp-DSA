#include <bits/stdc++.h>
using namespace std;

class Heap {
    vector<int> vec; // Max heap

public:
    void push(int val) {
        // Step 1: insert at the end
        vec.push_back(val);

        // Step 2: fix heap (heapify up)
        int child = vec.size() - 1;
        int parI = (child - 1) / 2;

        while (parI >= 0 && vec[child] < vec[parI]) { // O(log n)
            swap(vec[child], vec[parI]); // swap values, not indices
            child = parI;
            parI = (child - 1) / 2;
        }
    }

    int top() {
       return vec[0]; //heighes priority element 
    }

    bool empty() {
        return vec.empty();
    }
};

int main() {
    Heap heap;
    heap.push(50);
    heap.push(10);
    heap.push(100);

    cout << "top : " << heap.top() << endl; 
    return 0;
}
