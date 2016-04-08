/*
 * http://codeforces.com/contest/659/problem/E
 * E. New Reform
 * time limit per test1 second
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
Solution: deep first search. finding cycle.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(int curNode, int parentNode,
         const vector<vector<int>>& edges,
         vector<bool>& visited, bool& isCycle) {
    visited[curNode] = true;
    for (auto& node : edges[curNode]) {
        if (!visited[node]) {
            dfs(node, curNode, edges, visited, isCycle);
        } else if (node != parentNode) {
            isCycle = true;
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector< vector<int>> edges(n);
    vector<bool> visited(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a - 1].push_back(b - 1);
        edges[b - 1].push_back(a - 1);
    }

    int ret = 0;
    for (int i = 0; i < n; i++) {
        bool isCycle = false;
        if (!visited[i]) {
            dfs(i, -1, edges, visited, isCycle);
            ret += (!isCycle); 
        }
    }
    cout << ret << "\n";
    return 0;
}
