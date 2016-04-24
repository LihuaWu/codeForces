/*
 * http://codeforces.com/problemset/problem/653/A
 * A. Bear and Three Balls
 * time limit per test2 seconds
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * */

#include <iostream>
#include <algorithm>

using namespace std;

int a[1010];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    int size = unique(a, a + n) - a;
    bool flag = false;
    for (int i = 0; i < size-2; i++) {
        if (a[i] + 1 == a[i+1] && a[i+1] + 1 == a[i+2]) {
            flag = true;
            break;
        }
    }
    cout << (flag ? "YES" : "NO") << "\n";
    return 0;
}
