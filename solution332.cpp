//
// Created by zhang on 2021/9/6.
//
#include "common-header.h"
class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        map<string, vector<string>> adjacent;
        for(auto &ticket : tickets) {
            adjacent[ticket[0]].emplace_back(ticket[1]);
        }
        map<string, set<int>> usedTickets;
        for(auto &row : adjacent) {
            sort(row.second.begin(), row.second.end(), less<>());
        }
        vector<string> curLocations;
        stack<int> nextIndexes;
        curLocations.emplace_back("JFK");
        nextIndexes.emplace(0);
        int ticketsRemain = tickets.size();
        while (!curLocations.empty()) {
            if(ticketsRemain == 0) {
                return curLocations;
            }
            const string &curLocation = curLocations.back();
            int &index = nextIndexes.top();
            vector<string> &destinations = adjacent[curLocation];
            if(index >= destinations.size()) {
                curLocations.pop_back();
                nextIndexes.pop();
                ticketsRemain++;
                usedTickets[curLocations.back()].erase(nextIndexes.top() - 1);
            } else {
                if(usedTickets[curLocation].find(index) == usedTickets[curLocation].end()) {
                    usedTickets[curLocation].insert(index);
                    curLocations.emplace_back(destinations[index]);
                    nextIndexes.emplace(0);
                    ticketsRemain--;
                }
                index++;
            }
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<vector<string>> tickets = {{"JFK","KUL"},{"JFK","NRT"},{"NRT","JFK"}};
    vector<string> test = {"SFO", "ATL"};
    sort(test.begin(), test.end(), less<>());
    solution.findItinerary(tickets);
}