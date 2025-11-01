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

    // Helper function for cycle detection
    bool undirCycleHelper(int src, int parent, vector<bool>& vis) {
        vis[src] = true;

        for (int v : l[src]) {
            if (!vis[v]) {
                if (undirCycleHelper(v, src, vis))
                    return true;
            } 
            else if (v != parent) { // If visited & not parent → cycle found
                return true;
            }
        }
        return false;
    }

    bool isCycleUndir() {
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (undirCycleHelper(i, -1, vis))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V = 5;
    Graph graph(V);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    // graph.addEdge(1, 2);
    graph.addEdge(0, 3);
    graph.addEdge(3, 4);
    

    graph.printGraph();

    cout << "\n--- Cycle Detection in Undirected Graph ---\n";
    cout << graph.isCycleUndir() << endl;

    return 0;
}
