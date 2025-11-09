#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<pair<int, int>> * l; // = int, int : neighbor + wt
    bool isUdir;
public:
    Graph(int V, bool isUndir = true) {
        this-> V = V;
        l = new list<pair<int, int >> [V];
        this->isUdir = isUndir;
    }

   void addEdge(int u, int v, int wt) {
    l[u].push_back(make_pair(v, wt));
    if(isUdir)
        l[v].push_back(make_pair(u, wt));
   }

   //Prim's algp
   void primsAlgo(int src) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    //(wt + v ) ->min heep
    vector<bool> mst(V, false);

    pq.push(make_pair(0, src));
    int ans = 0;

    while (pq.size() > 0) {
        int u = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if(!mst[u]) {
            mst[u] = true;
            ans+= wt;
            list<pair<int, int>> neighbors = l[u];
            for(pair<int, int> n : neighbors) {
                int v = n.first;
                int currWt = n.second;
                pq.push(make_pair(currWt, v));
            }
        }
    }
    
   cout << "final cost of MST = " << ans << endl;
   }
};

int main () {
    //Prim's algp graph
    int V = 4;
    Graph g(V);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 15);
    g.addEdge(0, 3, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(2, 3, 50);

    g.primsAlgo(0);

    return 0;
}