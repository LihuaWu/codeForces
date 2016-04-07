/*
 * http://codeforces.com/contest/659/problem/E
 * E. New Reform
 * time limit per test1 second
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    int n, m;
    vector<int> degree(n, 0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        degree[a - 1]++;
        degree[b - 1]++;
    }
    int cnt = 0;
    for (auto i : degree) {
        if (i == 0) ++cnt;
        
    }
    if (n <= m ) cout << cnt << "\n";
    else cout << n - m << "\n";
    return 0;
}
