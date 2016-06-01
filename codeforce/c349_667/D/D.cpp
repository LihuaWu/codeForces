#include <bits/stdc++.h>
using namespace std;

const int N = 5e3 + 5;
int dis[N][N];

vector<vector<int>> g;
vector<vector<pair<int, int>>> d;
vector<vector<pair<int, int>>> r;

int n, m;

void bfs(int s) {
    vector<bool> visited(n+1);
    for (int i = 1; i <= n; i++) { dis[s][i] = -1; }
    queue<int> q;
    q.push(s);
    dis[s][s] = 0;
    visited[s] = true;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        for (int i = 0; i < g[cur].size(); i++) {
            int p = g[cur][i];
            if (visited[p]) continue;
            q.push(p);
            dis[s][p] = dis[s][cur] + 1;
            visited[p] = true;
        }
    }
}

int main(int argc, char **argv) {
    cin >> n >> m;
    g.resize(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) { bfs(i);}

    d.resize(n+1);
    r.resize(n+1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] <= 0) continue;
            d[i].push_back(make_pair(dis[i][j], j));
            r[j].push_back(make_pair(dis[i][j], i));
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(begin(d[i]), end(d[i]));
        sort(begin(r[i]), end(r[i]));
    }
    int av = 1, bv=1, cv=1, dv=1, sum=0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dis[i][j] <= 0) continue;
            int ai = max(0, static_cast<int>(r[i].size())-3);
            int di = max(0, static_cast<int>(d[j].size())-3);
            for (int k = ai; k < r[i].size(); k++) {
                int p = r[i][k].second;
                if (p == i || p == j) continue;
                for (int kd = di; kd < d[j].size(); kd++) {
                    int pd = d[j][kd].second;
                    if (pd == i || pd == j || pd == p) continue;
                    int tmpSum = dis[i][j] + r[i][k].first + d[j][kd].first;
                    if (tmpSum > sum) {
                        sum = tmpSum;
                        av = p; bv = i; cv = j; dv = pd; 
                    }
                }
            }
        }
    }
    cout << av << " " << bv << " " << cv << " " << dv << "\n";
    return EXIT_SUCCESS;
}
