#include "../common/fwd.h"

class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        map<string, map<string, int>> path;
        map<string, int> cnt;
        for (const auto& ticket : tickets) {
            path[ticket.first][ticket.second]++;
        }

        vector<string> ans;
        ans.push_back("JFK");
        dfs("JFK", tickets.size() + 1, path, ans); 
        return ans;
    }
private:
    bool dfs(string cur, int sentinal, 
             map<string, map<string,int>>& path, vector<string>& ans) {
        if (ans.size() == sentinal) return true;
        auto& next = path[cur];        
        for (auto i : next) {
            if (i.second != 0) {
                next[i.first]--;
                ans.push_back(i.first);
                if(dfs(i.first, sentinal,path, ans)) { return true; }
                next[i.first]++;
                ans.pop_back();
            }
        }
        return false;
    }
};


int main() {
    Solution s;
    
    auto f = [&](vector<pair<string, string>> tickets,
             vector<string> expected) -> bool
    {return expected == s.findItinerary(tickets); };
    
    auto getTicket = [](const std::string& key) -> vector<pair<string, string>> {
       istringstream iss(key); 
        vector<pair<string, string>> res; 
        while(iss.good()) {
            std::string from, to;
            iss >> from >> to;
            res.push_back(make_pair(from ,to));
        }
        return res;
    };

    vector<pair<string, string>> tickets;
    tickets = getTicket("MUC LHR JFK MUC");
    vector<pair<string, string>> expect;

    expect.push_back(make_pair("MUC", "LHR"));
    expect.push_back(make_pair("JFK", "MUC"));
    assert(expect == tickets);

    
    vector<string> expected;
    tickets = getTicket("MUC LHR JFK MUC SFO SJC LHR SFO");
    expected = {"JFK", "MUC", "LHR", "SFO", "SJC"};
    assert(f(tickets, expected));

    tickets = getTicket("JFK SFO JFK ATL SFO ATL ATL JFK ATL SFO");
    expected = {"JFK","ATL","JFK","SFO","ATL","SFO"};
    assert(f(tickets, expected));

    //[["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
    tickets = getTicket("JFK KUL JFK NRT NRT JFK");
    //["JFK","NRT","JFK","KUL"]
    expected = {"JFK", "NRT", "JFK", "KUL"};
    assert(f(tickets, expected));

    return 0;
}
