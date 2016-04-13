/*
 * http://codeforces.com/problemset/problem/653/B
 * time limit per test2 seconds
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * */

#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

int main() {
    map<char, vector<string>> dict;
    int n, q;
    cin >> n >> q;
    std::string a;
    char b;
    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        dict[b].push_back(a);
    }
    stack<pair<char, int>> s;
    s.push(make_pair('a',1));
    int cnt = 0;
    while (!s.empty()) {
        auto elem = s.top();s.pop();
        char key = elem.first;
        int  level = elem.second;
        if (level == n) { ++cnt; continue; }

        auto edges = dict[key];
        for (auto edge : edges) {
            char newKey = edge[0];
            s.push(make_pair(newKey, level + 1));
        }
    }
    cout << cnt << "\n";
    return 0;
}
