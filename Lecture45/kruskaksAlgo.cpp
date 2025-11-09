#include <bits/stdc++.h>
using namespace std;

class Edge {
public:
    int u;
    int v;
    int w;

    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

class Graph {
public:
    vector<Edge> edges;
    vector<int> par, rankv;
    int V;

    Graph(int V) {
        this->V = V;
        par.resize(V);
        rankv.resize(V);

        for(int i = 0; i < V; i++) {
            par[i] = i;
            rankv[i] = 0;
        }
    }

    int find(int x) {
        if (par[x] == x) return x;
        return par[x] = find(par[x]);
    }

    void unionByRank(int u, int v) {
        int pu = find(u);
        int pv = find(v);

        if (pu == pv) return;

        if (rankv[pu] == rankv[pv]) {
            par[pv] = pu;
            rankv[pu]++;
        } else if (rankv[pu] > rankv[pv]) {
            par[pv] = pu;
        } else {
            par[pu] = pv;
        }
    }

    void addEdge(int u, int v, int w) {
        edges.push_back(Edge(u, v, w));
    }

    void kruskals() {
        sort(edges.begin(), edges.end(), [](Edge &a, Edge &b) {
            return a.w < b.w;
        });

        int minCost = 0;

        for (auto &e : edges) {
            int pu = find(e.u);
            int pv = find(e.v);

            if (pu != pv) {
                unionByRank(pu, pv);
                minCost += e.w;
            }
        }

        cout << "min cost = " << minCost << endl;
    }
};

int main() {
    Graph graph(4);

    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    graph.kruskals();
    return 0;
}
