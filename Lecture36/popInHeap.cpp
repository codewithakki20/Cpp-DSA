#include <bits/stdc++.h>
using namespace std;

class Heap
{
    vector<int> vec;

public:
    void push(int val)
    {
        vec.push_back(val);

        int child = vec.size() - 1;
        int parI = (child - 1) / 2;

        while (parI >= 0 && vec[child] < vec[parI])
        {
            swap(vec[child], vec[parI]);
            child = parI;
            parI = (child - 1) / 2;
        }
    }

    void heapify(int i)
{
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int maxI = i;

    if (l < vec.size() && vec[l] < vec[maxI])
        maxI = l;
    if (r < vec.size() && vec[r] < vec[maxI])
        maxI = r;

    if (maxI != i) { 
        swap(vec[i], vec[maxI]);
        heapify(maxI);
    }
}


    void pop()
    { // step 1
        swap(vec[0], vec[vec.size() - 1]);
        // step 2
        vec.pop_back();
        // step 3
        heapify(0);
    }

    int top()
    {
        return vec[0];
    }

    bool empty()
    {
        return vec.empty();
    }
};

int main()
{
    Heap heap;
    heap.push(9);
    heap.push(4);
    heap.push(8);
    heap.push(1);
    heap.push(2);
    heap.push(5);

    while(!heap.empty()) {
    cout << "top : " << heap.top() << endl;
    heap.pop();
    }

    // cout << "top : " << heap.top() << endl;
    // heap.top();
    return 0;
}
