#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = false) {
        this->V = V;
        this->isUndir = isUndir;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        if (isUndir)
            l[v].push_back(u);
    }

    void topoHelper(int src, vector<bool> &vis, stack<int> &s) {
        vis[src] = true;

        for (int v : l[src]) {
            if (!vis[v])
                topoHelper(v, vis, s);
        }
        s.push(src);
    }

    void topoSort() {
        vector<bool> vis(V, false);
        stack<int> s;

        for (int i = 0; i < V; i++) {
            if (!vis[i])
                topoHelper(i, vis, s);
        }

        // Print topological order
        cout << "Topological Order: ";
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }

    void calcIndegree(vector<int> &indeg) {
        for(int u=0; u<V; u++) {
            list<int> neighbors = l[u];
            for(int v : neighbors) {
                indeg[v]++;
            }
        }
    }

    void topoSort2() {
        vector<int> indeg(V, 0);
        calcIndegree(indeg);
        queue<int> q;
        //0 indeg nodes -> starting point
        for(int i=0; i<V; i++ ){
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        while (q.size() > 0)
        {
            int curr = q.front();
            q.pop();
            cout << curr << " ";

            list<int> neighbors = l[curr];
            for(int v : neighbors) {
                indeg[v]--;
                if(indeg[v] == 0) { // no pending dependecies
                    q.push(v);
                }
            }
        }
        
        cout << endl;

    }
};

int main() {
    Graph graph(6);

    graph.addEdge(2, 3);
    graph.addEdge(2, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.topoSort2();

    return 0;
}
