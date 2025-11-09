#include <iostream>
#include <vector>
#include<graph>
#include <list>
using namespace std;

class Edge {
public: 
    int v;
    int wt;

    Edge(int v, int wt) {
        this->v = v;
        this->wt = wt;
    }
};

int main() {
    int V = 6;
    vector<vector>Edge>> graph(v);

    graph[0].push_back(Edge(1, 2));
    graph[0].push_back(Edge(2, 4));

    graph[1].push_back(Edge(2, 1));
    graph[1].push_back(Edge(3, 7));

    graph[2].push_back(Edge(4, 3));

    graph[3].push_back(Edge(5, 1));

    graph[3].push_back(Edge(3, 2));
    graph[3].push_back(Edge(2, 5));

    graph[4].push_back(Edge(5, 2));
    graph[4].push_back(Edge(2, 5));

    graph[5].push_back(Edge(3, 1));
    graph[5].push_back(Edge(4, 5));

    

    return 0;
}
