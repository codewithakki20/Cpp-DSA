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

class Student {  // "<" overload
public : 
   string name;
   int marks;

   Student(string name, int marks) {
    this->name = name;
    this->marks = marks;
   }

   bool operator < (const Student &obj) const {
    return this->name < obj.name;
   }
};

int main()
{
    priority_queue<Student> pq;

    pq.push(Student("ankit", 50));
    pq.push(Student("ayush", 85));
    pq.push(Student("aman", 75));

    while(!pq.empty()) {
        cout << "top : " << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }
    
    return 0;
}
