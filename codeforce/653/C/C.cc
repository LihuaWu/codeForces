/*
 * http://codeforces.com/problemset/status/653/problem/C
 * C. Bear and Up-Down
 * time limit per test2 seconds
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * */

#include <iostream>
#include <algorithm>
#include <vector>

int a[150010];
const int INF = 150010;
bool ok[150010];

using namespace std;

bool check(int n) {
    if (n & 0x1) { if (a[n] < a[n+1] && a[n-1] > a[n]) return true; } 
    else { if (a[n] > a[n+1] && a[n-1] < a[n]) return true; }
    return false;
}

int main() {
    int n ;
    vector<int> bad;
    cin >> n;
    for (int i = 1; i <=n; i++) {
        cin >> a[i];
    }
    a[0] = INF;
    if (n & 0x1) a[n+1] = INF; else a[n+1] = 0;

    for (int i = 1;i <= n; i++) {
        if (!check(i)) bad.push_back(i);
        else ok[i] = true;
    }
    if (bad.size() > 6) { cout << 0 << "\n"; return 0; }

    bool flag = false;
    int ans = 0;
    for (int index : bad) {
        for (int j = 1; j <= n; j++) if (ok[j] || j < index) {
            flag = true ;
            swap(a[index], a[j]);
            if (!check(index) || !check(j)) flag = false;
            for (int k : bad) { if (!check(k)) { flag = false; break; } }
            if (flag) ans++;
            swap(a[index], a[j]);
        }
    }
    cout << ans << "\n";
    return 0;
}
