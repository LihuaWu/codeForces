#include <bits/stdc++.h>
using namespace std;


const int N = 1e4 + 10;
bool d[N][2];
set<string> ans;


int main(int argc, char **argv) {
    string s;
    cin >> s;

    size_t s_size = s.size();
    memset(d, 0, sizeof d);
    d[s_size][0] = d[s_size][1] = true;

    for (int i = s_size-2; i >=5; i--) {
        if (d[i+2][1] || (d[i+2][0] && s.substr(i, 2) != s.substr(i+2, 2))) {
            d[i][0] = true;
            ans.insert(s.substr(i, 2));
        }
        if (d[i+3][0] || (d[i+3][1] && s.substr(i, 3) != s.substr(i+3, 3))) {
            d[i][1] = true;
            ans.insert(s.substr(i, 3));
        }
    }
    cout << ans.size() << "\n";
    for (auto & i : ans) { cout << i << "\n"; }
    return EXIT_SUCCESS;
}
