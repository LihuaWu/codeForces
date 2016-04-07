/*
 * http://codeforces.com/contest/659/problem/B
 * Qualifying Contest
 * time limit per test1 second
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * */

#include <assert.h>

#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int, string>>> rec(m);
    for (int i = 0; i < n; i++) {
        std::string surName;
        int region, score;
        cin >> surName >> region >> score;
        rec[region - 1].push_back(make_pair(score, surName));
    }

    for (int i = 0; i < m; i++) {
        auto& vec = rec[i];
        sort(vec.begin(), vec.end(), 
            [](const pair<int, string>& lhs,
                 const pair<int, string>& rhs )->bool {
                return lhs.first > rhs.first;
            }
        );
        assert(vec.size() >= 2);

        if (vec.size() == 2) {
            std::cout << vec[0].second << " " << vec[1].second << "\n";
        } else if (vec[1].first == vec[2].first) { std::cout << "?\n"; }
        else {
            std::cout << vec[0].second << " " << vec[1].second << "\n";
        }
    }

    return 0;
}
