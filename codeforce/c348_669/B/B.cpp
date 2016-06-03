#include <bits/stdc++.h>
using namespace std;

int n;
const int  N = 1e5 + 10;
int d[N];
bool v[N];
string s;

int main(int argc, char **argv) {
    cin >> n >> s;
    memset(d, 0, sizeof d);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        v[i] = false;
    }
    bool flag = false;
    int cur = 0;
    while (true) {
        if (v[cur]) {flag = true; break; }
        v[cur] = true;
        if (s[cur] == '>') {
            int next = cur + d[cur];
            if (next >= n ) { flag = false; break; }
            else cur = next;
        } else {
            int next = cur - d[cur];
            if (next < 0) { flag = false; break; }
            else cur = next;
        }
    }
    cout << (flag ? "INFINITE" : "FINITE") << "\n";
    return EXIT_SUCCESS;
}
