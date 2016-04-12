/*
 * http://codeforces.com/problemset/problem/660/C
 * C. Hard Process
 * time limit per test1 second
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * */

#include <iostream>
#include <algorithm>

using namespace std;

const int size = 3e5 + 10;
int a[size];
int b[size];

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0;i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            b[i] = (a[i] == 0);
        } else {
            b[i] = b[i - 1] + (a[i] == 0);
        }
    }
    int max = 0, start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        int c = upper_bound(b, b + n, k + b[i - 1]) - b - i;
        if (max < c) {
            max = c, start = i, end = start + c;
        }
    }
    cout << max << "\n";
    for (int i = 0; i < n; i++) {
        if (i < start || i >= end ) cout << a[i];
        else cout << 1;
        if (i != n - 1) cout << " ";
    }
    cout << "\n";
    return 0;

}
