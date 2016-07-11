#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
    string s;
    cin >> s;
    string p(s);
    reverse(p.begin(), p.end());
    cout << (s+p) << "\n";

    return EXIT_SUCCESS;
}
