#include <bits/stdc++.h>
using namespace std;

int n, m, q;

vector<pair<int, int>> op;
int a[105][105]; 

int main(int argc, char **argv) {
    cin >> n >> m >> q;
    int t;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 1 || t == 2) {
            int tmp;
            cin >> tmp;
            op.push_back(make_pair(t, tmp));
        } else {
            int r, c, v;
            cin >> r >> c >> v;
            a[r][c] = v;
        }
    }

    for (auto it = op.rbegin(); it != op.rend(); it++) {
        int type = it->first; int item = it->second; 
        if (type == 1) {
            int res = a[item][n];
            for (int i = n; i > 1; i--) {
                a[item][i] = a[item][i-1];
            }
            a[item][1] = res;
        } else {
            int res = a[n][item];
            for (int i = m; i > 1; i--) {
                a[i][item] = a[i-1][item];
            }
            a[1][item] = res;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return EXIT_SUCCESS;
}
