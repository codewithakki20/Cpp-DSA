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

    void addEdge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u); // Undirected edge
    }

    void printGraph() {
        cout << "Adjacency List of Graph:\n";
        for (int u = 0; u < V; u++) {
            cout << u << " -> ";
            for (int v : l[u]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    // DFS Traversal
    void dfsHelper(int u, vector<bool>& vis) {
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
        cout << "\nDFS starting from node " << start << ": ";
        dfsHelper(start, vis);

        // Handle disconnected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                cout << "\nDFS from disconnected component node " << i << ": ";
                dfsHelper(i, vis);
            }
        }
        cout << endl;
    }

    // BFS Traversal
    void bfsHelper(int start, vector<bool>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = true;

        cout << "BFS starting from node " << start << ": ";

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

    void bfs() {
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                bfsHelper(i, vis);
            }
        }
    }
};

int main() {
    Graph graph(10);

    graph.addEdge(0, 2);
    graph.addEdge(0, 5);

    graph.addEdge(1, 6);
    graph.addEdge(6, 4);
    graph.addEdge(4, 3);
    graph.addEdge(3, 8);
    graph.addEdge(3, 7);
    graph.addEdge(4, 9);

    graph.printGraph();

    cout << "\n--- BFS Traversal ---\n";
    graph.bfs();

    cout << "\n--- DFS Traversal ---\n";
    graph.dfs(0);

    return 0;
}
