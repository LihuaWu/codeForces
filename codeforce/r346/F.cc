/*
http://codeforces.com/contest/659/problem/F
Polycarp and Hay
time limit per test4 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
*/

#include <string.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <limits>

int table[1010][1010], all[1001000], vis[1010][1010], g[1010][1010];
int dir[2][4] = {{0, 0, 1, -1}, {1, -1, 0, 0 }};

int n, m, cur, candidate, color, sum;
int64_t k;
bool flag;


using namespace std;

void dfs(int x, int y) {
    sum++;
    if (sum <= k / candidate) {
        g[x][y] = color;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int xx = x + dir[0][i];
        int yy = y + dir[1][i];
        if (xx < 0 || yy < 0 || xx >= n || yy >= m || table[xx][yy] < candidate || vis[xx][yy]) continue;
        dfs(xx, yy);
    }
}


int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
            all[i * m + j] = table[i][j];
        }
    }

    sort(all, all+n*m);
    flag = false;
    int total = n * m;

    for (cur = 0; cur < total; cur++) {
        if (cur > 0 && all[cur] == all[cur - 1]) continue; 
        candidate = all[cur];
        if (static_cast<int64_t>(candidate) * (total - cur) < k
             || k % candidate != 0) { continue; }

        memset(vis, 0, sizeof(vis));
        memset(g, 0, sizeof(g));
        color = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                //at least one hay is at candidate high.
                if (!vis[i][j] && table[i][j] == candidate) {
                    sum = 0;  
                    color++;
                    dfs(i, j);
                    if (static_cast<int64_t>(sum) * candidate >= k) {
                        flag = true; i = n; cur = total;
                        break;
                    }
                }
            }
        }
    }
    if (flag) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << (g[i][j] == color ? candidate : 0) << " ";
            }
            cout << "\n";
        }
    } else 
     cout << "NO\n";
    return 0;
}
