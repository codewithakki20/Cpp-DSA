#include <bits/stdc++.h>
using namespace std;

int maxActivities(vector<int> start, vector<int> end) {
    int n = start.size();

    // Store activities as {end_time, index}
    vector<pair<int,int>> activities;
    for(int i = 0; i < n; i++) {
        activities.push_back({end[i], i});
    }

    // Sort by end time
    sort(activities.begin(), activities.end());

    cout << "Selecting activities:\n";

    // Select first activity
    int count = 1;
    int currEndTime = activities[0].first;
    cout << "A" << activities[0].second << " ";
    
    // Iterate through rest
    for(int i = 1; i < n; i++) {
        int idx = activities[i].second;
        if(start[idx] >= currEndTime) {
            cout << "A" << idx << " ";
            count++;
            currEndTime = end[idx];
        }
    }
    cout << "\n";
    
    return count;
}

int main() {
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end   = {2, 4, 6, 7, 9, 9};

    cout << "Maximum number of activities: " 
         << maxActivities(start, end) << endl;
    return 0;
}