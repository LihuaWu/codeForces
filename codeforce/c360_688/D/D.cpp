#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

int isP[N];

int cntP[N];

int main(int argc, char **argv) {
    for (int i = 2; i < N; i++) {
        if (!isP[i]) {
            for (int j = i; j < N; j += i) {
                isP[j] = i;
            }
        }
    }
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        while (c > 1) {
            int p = isP[c];
            int cnt = 0;
            while (c % p == 0) {
                c /= p;
                cnt++;
            }
            cntP[p] = max(cntP[p], cnt);
        }
    }

    bool flag = true;
    while (k > 1) {
        flag &= (cntP[isP[k]] > 0);
        cntP[isP[k]]--;
        k /= isP[k];
    }
    cout << (flag ? "Yes" : "No") << "\n";
    return EXIT_SUCCESS;
}
