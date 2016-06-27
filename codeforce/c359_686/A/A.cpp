#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int n, x;
    cin >> n >> x;
    int64_t cur = x;
    char op;
    int delta;
    int distress = 0;
    for (int i = 0;i < n; i++) {
        cin >> op >> delta;
        if (op == '+') {
            cur += delta;
        } else if (op == '-') {
            if (cur < delta) { distress++; }
            else {cur -= delta; }
        }
    }
    cout << cur << " " << distress;
    return EXIT_SUCCESS;
}
