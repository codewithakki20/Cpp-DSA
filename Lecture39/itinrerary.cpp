#include <bits/stdc++.h>
using namespace std;

void printItinerary(unordered_map<string, string> tickets) {
    // Step 1: Collect all destination cities
    unordered_set<string> to;
    for (auto ticket : tickets) { 
        to.insert(ticket.second);
    }

    // Step 2: Find the starting point (a city that is never a destination)
    string start = "";
    for (auto ticket : tickets) { 
        if (to.find(ticket.first) == to.end()) { 
            start = ticket.first;
            break;
        }
    }

    // Step 3: Print the itinerary
    cout << start;
    while (tickets.count(start)) {
        cout << " -> " << tickets[start];
        start = tickets[start];
    }
    cout << " -> destination\n";
}

int main() {
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);
    return 0;
}
