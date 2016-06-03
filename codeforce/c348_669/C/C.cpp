#include <bits/stdc++.h>
using namespace std;

int n, m, q;

int a[105][105]; 
pair<int, int> idx[105][105];

int main(int argc, char **argv) {
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            idx[i][j] = make_pair(i, j);
        }
    }
    int t;
    for (int i = 0; i < q; i++) {
        cin >> t;
        if (t == 1) {
            int item;
            cin >> item;
            for (int i = 1; i < m; i++) { swap(idx[item][i], idx[item][i+1]); }
        } else if (t == 2) {
            int item;
            cin >> item;
            for (int i = 1; i < n; i++) { swap(idx[i][item], idx[i+1][item]); }
        } else {
            int r, c, v;
            cin >> r >> c >> v;
            a[idx[r][c].first][idx[r][c].second] = v;
 //           cout << "r:" << r << " c:" << c << " l:" << idx[r][c].first << " r:" << idx[r][c].second  << " v:" <<  a[idx[r][c].first][idx[r][c].second] << "\n"; 
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
