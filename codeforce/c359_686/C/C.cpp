#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
    int n, m;
    cin >> n >> m;
    int len1(1), len2(1);
    for (int a = 7; a < n; a *= 7) { len1++; }
    for (int b = 7; b < m; b *= 7) { len2++; }
    int ans = 0;

    if (len1 + len2 <= 7) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                vector<int> used(7, 0);
                for (int a = i, k = 0; k != len1; a /= 7, k++) {
                    used[a%7] += 1;
                }
                for (int b = j, k = 0; k != len2; b /= 7, k++) {
                    used[b%7] += 1;
                }
                if (*max_element(used.begin(), used.end()) <= 1) {
                    ans++;
                }
            }
        }
    }
    cout << ans << "\n";
    return EXIT_SUCCESS;
}
