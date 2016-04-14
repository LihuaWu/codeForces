#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> f;

int n, m, k;

bool check(int a, int b) {
    return f.count(make_pair(a,b)) != 0 ||
        f.count(make_pair(b, a)) != 0;

}

const int size = 3e5 + 10;
bool vis[size];

int cnt = 0;
int tot = 0;
int maxDegree = 0;

void dfs(int i, int pred) {
    if (!vis[i]) {
        vis[i] = true;
        ++cnt;
        for (int j = pred; j <= n; j++) {
            if (!vis[j] && !check(i, j)) {
                dfs(j, pred);
            }
        }
    } 
}

int main(int argc, char **argv)
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        f.insert(make_pair(a,b));
    }
    dfs(1, 1);
    bool ret = true ;
    if (cnt != n) { ret = false; }
    else {
        bzero(vis, size);
        for (int i = 2; i <= n; i++) {
            if (!vis[i] && !check(i, 1)) {
                dfs(i, 2);
                ++tot;
            }
        }

        for (int i = 2; i <= n; i++) {
            if (!check(i, 1)) { ++maxDegree; }
        }
        //cout << "k: " << k << " tot:" << tot << " maxDegree:" << maxDegree << "\n";
        if (k < tot || k > maxDegree) {
            ret = false;
        }
    }

    cout << (ret ? "possible" : "impossible") << "\n";

    return EXIT_SUCCESS;
}
