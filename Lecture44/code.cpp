#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Graph {
    int V;
    list<int>* l;
public:
    Graph(int V) {
        this->V = V;
        l = new list<int>[V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void printGraph() {
        for (int u = 0; u < V; u++) {
            cout << u << " : ";
            for (int v : l[u]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void dfsHelper(int u, vector<bool> &vis) {
        vis[u] = true;
        cout << u << " ";
        for (int v : l[u]) {
            if (!vis[v]) {
                dfsHelper(v, vis);
            }
        }
    }

    void dfs(int start) {
        vector<bool> vis(V, false);
        cout << "\nDFS Traversal: ";
        dfsHelper(start, vis);
        cout << endl;
    }
};

int main() {
    Graph graph(7);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);
    graph.addEdge(5, 6);

    cout << "Adjacency List of Graph:\n";
    graph.printGraph();

   
    graph.dfs(0);

    cout << endl;
    return 0;
}
