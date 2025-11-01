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

    void addEdge(int u, int v) { // undirected edge
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

    void dfs(int u, vector<bool> &vis) { // recursive DFS
        vis[u] = true;
        cout << u << " ";

        for (int v : l[u]) {  // iterate over all neighbors
            if (!vis[v]) {
                dfs(v, vis);
            }
        }
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

    vector<bool> vis(7, false);
    cout << "\nDFS Traversal: ";
    graph.dfs(0, vis);

    cout << endl;
    return 0;
}
