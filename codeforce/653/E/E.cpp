#include <bits/stdc++.h>

using namespace std;

set<pair<int, int>> s;
set<int> t;

int n, m, k, f1 = 0;
int tot;

bool f(int a, int b) {
    if (a > b) swap(a, b);
    return s.find(make_pair(a,b)) == s.end();

}

void dfs(int i) {
    vector<int> v;
    for(auto j : t) if(f(i,j)) v.push_back(j);
    for (auto j : v) t.erase(j);
    for (auto j : v) dfs(j);

}

int main(int argc, char **argv)
{
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i++) { t.insert(i); }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        f1 += (a == 1);
        s.insert(make_pair(a,b));
    }
    if (n - f1 <= k)  { cout << "impossible\n"; return 0; } 
    for (int i = 2; i <= n; i++) {
        if (t.find(i) != t.end() && f(1, i)) { dfs(i), tot++; }
    }
    if (t.size() >0 || tot > k) { cout << "impossible\n"; return 0; }
    cout << "possible\n";
    return EXIT_SUCCESS;
}
