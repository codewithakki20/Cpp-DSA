#include <iostream>
#include <vector>
#include <queue>
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

    void bfs(int start = 0) { // O(V + E)
        queue<int> q;
        vector<bool> vis(V, false);

        q.push(start);
        vis[start] = true;

        cout << "\nBFS Traversal: ";
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            cout << u << " ";

            for (int v : l[u]) {
                if (!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
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

    graph.bfs(0);

    return 0;
}
