#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    class Info {
    public:
        int u;
        int cost;
        int stops; // src to u

        Info(int u, int cost, int stops) {
            this->u = u;
            this->cost = cost;
            this->stops = stops;
        }
    };

    int findCheapestPrice(int V, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<Info> q;
        vector<int> dist(V, INT_MAX);

        dist[src] = 0;
        q.push(Info(src, 0, 0));

        while (!q.empty()) {
            Info curr = q.front();
            q.pop();

            // if number of stops exceeds limit, skip
            if (curr.stops > k) continue;

            for (auto& flight : flights) {
                if (flight[0] == curr.u) {
                    int v = flight[1];
                    int wt = flight[2];

                    // if found cheaper cost within allowed stops
                    if (curr.cost + wt < dist[v]) {
                        dist[v] = curr.cost + wt;
                        q.push(Info(v, dist[v], curr.stops + 1));
                    }
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};

int main() {
    Solution sol;

    int n = 4;
    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 0, 100},
        {1, 3, 600},
        {2, 3, 200}
    };
    int src = 0;
    int dst = 3;
    int k = 1;

    int ans = sol.findCheapestPrice(n, flights, src, dst, k);
    cout << "Cheapest Price: " << ans << endl;
    return 0;
}
