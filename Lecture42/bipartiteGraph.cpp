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

    bool isBipartite() {
        queue<int> q;
        vector<int> color(V, -1);
        q.push(0);
        color[0] = 0;

        while (q.size() > 0) 
        {
            int curr = q.front();
            q.pop();
            list<int> neighbors = l[curr];

            for(int v : neighbors) {
                if(color[v] == -1) {
                    color[v] = !color[curr];
                    q.push(v);
                } else {
                    if(color[v] == color[curr]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main() {
    int V = 4;
    Graph graph(V);

    //non bipartite
    // graph.addEdge(0, 1);
    // graph.addEdge(0, 2);
    // graph.addEdge(0, 3);
    // graph.addEdge(1, 2);
    // graph.addEdge(3, 4);

    //bipartite
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);


    cout << graph.isBipartite() << endl;


    return 0;
}

