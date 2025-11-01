#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isCycle(int src, vector<bool> &vis, vector<bool> &rec, vector<vector<int>>& adj) {
        vis[src] = true;
        rec[src] = true;

        for (int nbr : adj[src]) {
            if (!vis[nbr]) {
                if (isCycle(nbr, vis, rec, adj))
                    return true;
            } 
            else if (rec[nbr]) {
                return true;  // Cycle detected
            }
        }

        rec[src] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // Build adjacency list from prerequisites
        for (auto &p : prerequisites) {
            int course = p[0];
            int prereq = p[1];
            adj[prereq].push_back(course);
        }

        vector<bool> vis(numCourses, false);
        vector<bool> rec(numCourses, false);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (isCycle(i, vis, rec, adj))
                    return false; // Cycle found → cannot finish
            }
        }
        return true; // No cycle → can finish all courses
    }
};

int main() {
    Solution s;
    vector<vector<int>> prereq1 = {{1, 0}};
    vector<vector<int>> prereq2 = {{1, 0}, {0, 1}};

    cout << s.canFinish(2, prereq1) << endl; // Output: 1 (true)
    cout << s.canFinish(2, prereq2) << endl; // Output: 0 (false)
}
