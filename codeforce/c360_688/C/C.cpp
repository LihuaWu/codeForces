#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

vector<int> color;
vector<int> res[2];

bool dfs(int u, int colors = 2) {
    color[u] = colors;
    res[colors-1].push_back(u);
    for (auto & v : g[u]) {
        if (!color[v] && dfs(v, 3-colors)) {
            return true;
        }
        if (color[v] != 3-colors) {
            return true;
        }
    }
    return false;
}

int main(int argc, char **argv) {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    color.resize(n);
    for (int i = 0; i < n; i++) {
        if (g[i].size() == 0) continue;
        if (!color[i]) {
            bool ret = dfs(i);
            if (ret) {
                cout << -1 << "\n";
                return EXIT_SUCCESS;
            }
        } 
    }
    for (int i = 0; i < 2; i++) {
        cout << res[i].size() << "\n";
        for (auto & v : res[i]) {
            cout << (v+1) << " ";
        }
        cout << "\n";
    }
    return EXIT_SUCCESS;
}
