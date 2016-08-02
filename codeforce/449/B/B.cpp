#include <bits/stdc++.h>
using namespace std;


#define N 100005
const int64_t INF = (1ll<<60); 

struct Edge { int v; int d; bool train; };
vector<Edge> g[N];
int64_t dist[N];
bool need[N]; // path that need to keep
bool visited[N];


int main(int argc, char **argv) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++) {
        int u, v, d;
        scanf("%d%d%d", &u, &v, &d);
        u--,v--;
        g[u].push_back({v, d, false});
        g[v].push_back({u, d, false});
    }
    for (int i = 0; i < k; i++) {
        int v, d;
        scanf("%d%d", &v, &d);    
        v--;
        g[0].push_back({v, d, true});
    }
    for(int i = 1; i < n; i++) {
        dist[i] = INF;
    }
    set<pair<int64_t, int>> q;
    q.insert({0, 0});
    int ans = k;
    while (!q.empty()) {
        int u = q.begin()->second;
        q.erase(q.begin());
        // 这里优先会先处理火车节点
        for (auto e : g[u]) {
//            q.insert({dist[e.v], e.v});
            if (dist[u] + e.d < dist[e.v]) {
                q.erase({dist[e.v], e.v});
                dist[e.v] = dist[u] + e.d;
                q.insert({dist[e.v], e.v});
                need[e.v] = e.train;
    
            } else if (dist[u] + e.d == dist[e.v] && !e.train) {
                need[e.v] = false;
            }
        }
    }
    for (int i = 0; i < n; i++) ans -= need[i];
    cout << ans << "\n";
    return EXIT_SUCCESS;
} = false;
