/*http://codeforces.com/problemset/problem/660/A
 * A. Co-prime Array
 * time limit per test1 second
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 */

//#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int64_t a[1010];
int64_t b[2020];

int64_t gcd(int64_t a, int64_t b) {
    if (b == 0) return a;
    a %= b;
    return gcd(b, a);
}

int main() {
    int n;
    int m = 0;
    cout << gcd(2,4) << "\n";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i && gcd(a[i], a[i-1]) != 1) {
            b[m] = 1;
            m++;
        } 
        b[m] = a[i];
        m++;
    }
    cout << m - n + 1<< "\n";
    for (int i = 0; i < m; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
    return 0;
}
