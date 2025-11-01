#include <bits/stdc++.h>
using namespace std;

class Car {
public:
    int idx;
    int distSq;

    Car(int idx, int distSq) {
        this->idx = idx;
        this->distSq = distSq; 
    }

   
    bool operator<(const Car &obj) const {
        return this->distSq > obj.distSq; 
    }
};

void nearbyCars(vector<pair<int, int>> pos, int K) {
    vector<Car> cars;

    for (int i = 0; i < pos.size(); i++) {
        int distSq = (pos[i].first * pos[i].first) + (pos[i].second * pos[i].second); 
        cars.push_back(Car(i, distSq));
    }

    priority_queue<Car> pq(cars.begin(), cars.end());

    cout << "Nearest " << K << " cars to origin:\n";
    for (int i = 0; i < K && !pq.empty(); i++) {
        Car top = pq.top();
        pq.pop();
        cout << "Car " << top.idx << " at (" << pos[top.idx].first << ", " << pos[top.idx].second << ")\n";
    }
}

int main() {
    vector<pair<int, int>> pos = {
        {3, 3},
        {5, -1},
        {-2, 4}
    };

    int K = 2;
    nearbyCars(pos, K);

    return 0;
}
