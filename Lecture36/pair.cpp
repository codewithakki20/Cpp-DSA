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

        while (parI >= 0 && vec[child] > vec[parI])
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

    if (l < vec.size() && vec[l] > vec[maxI])
        maxI = l;
    if (r < vec.size() && vec[r] > vec[maxI])
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

struct ComparePair
{
    bool operator () (pair<string, int> &p1, pair<string, int> &p2) {
        return p1.second < p2.second;
    }
};


int main()
{
    // priority_queue<pair<string, int>> pq; //default - maxheap;  " first"
    priority_queue<pair<string, int>, vector<pair<string, int>>, ComparePair> pq;

    pq.push(make_pair("ankit", 50));
    pq.push(make_pair("ayush", 85));
    pq.push(make_pair("aman", 75));

    while(!pq.empty()) {
        cout << "top : " << pq.top().first << ", " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}
