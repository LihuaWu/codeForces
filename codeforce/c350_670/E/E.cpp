#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10;
int L[N], R[N], pos[N];
vector<int> v;

int n,m,p;
string t;
string s;


int main(int argc, char **argv) {
    cin >> n >> m >> p >> t >> s;
    p--;

    for (int i = 0; i < n; i++) {
        if (t[i] == '(') v.push_back(i);
        else {
            pos[i] = v.back(); 
            pos[v.back()] = i;
            v.pop_back();
        }
        L[i] = i-1;
        R[i] = i+1;
    }
    L[n] = n-1, R[-1] = 0;
    for (int i = 0; i < m; i++) {
        if (s[i] == 'L') p = L[p];
        else if (s[i] == 'R') p = R[p];
        else {
            if (t[p] == '(') {
                R[L[p]] = R[pos[p]], L[R[pos[p]]] = L[p], p = R[pos[p]];
            } else {
                L[R[p]] = L[pos[p]], R[L[pos[p]]] = R[p], p = R[p];
            }
        }
        if (p == n) p = L[n];
    }
    while (L[p] != -1) p = L[p];
    while (p != n) {
        cout << t[p];
        p = R[p];
    }
    cout << "\n";
    return EXIT_SUCCESS;
}
