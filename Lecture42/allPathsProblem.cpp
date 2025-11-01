
#include <iostream>
#include <vector>
#include <queue>
#include <string>
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
        cout << "Adjacency List of Graph:\n";
        for (int u = 0; u < V; u++) {
            cout << u << " -> ";
            for (int v : l[u]) {
                cout << v << " ";
            }
            cout << endl;
        }
    }

    void pathHelper(int dest, int src, vector<bool> &vis, string &path) {
        if(src == dest) {
            cout << path << dest << endl;
            return;
        }

        vis[src] = true;
        path += to_string(src);
        list<int> neighbors = l[src];

        for(int v : neighbors) {
            if(!vis[v]) {
                pathHelper(v, dest, vis, path);
            }
        }

        path = path.substr(0, path.size()-1);
        vis[src] = false;


    }

   void printAllPaths(int src, int dest) {
    vector<bool> vis(V, false);
    string path = "";
    pathHelper(dest, src, vis, path); 
   }
};

int main() {
    int V = 6;
    Graph graph(V);

    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 1);
    graph.addEdge(4, 0);
    graph.addEdge(4, 1);
    graph.addEdge(5, 0);
    graph.addEdge(5, 2);

    graph.printAllPaths(5, 1);

    return 0;
}

