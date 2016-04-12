/*
 * http://codeforces.com/problemset/problem/660/D
 * D. Number of Parallelograms
 * time limit per test4 seconds
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * */

#include <iostream>
#include <map>
#include <utility>

using namespace std;
const int size = 2010;
int x[size], y[size];
map<pair<int,int>, int> m;

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        for (int j = 0; j < i; j++) {
            ans += m[make_pair(x[i]+x[j], y[i]+y[j])];
            m[make_pair(x[i]+x[j], y[i]+y[j])]++;
        }
    }
    cout << ans << "\n";
    return 0;
}
