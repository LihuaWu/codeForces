#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{
    int64_t n, m, k;
    cin >> n >> m >> k;

    int64_t ans(0);
    if (n + m < k + 2)  {
        ans = -1;
    } else {
        if (n > m) swap(n, m);
        if (k <= n-1) {
            int64_t val1 = (n/1) * (m/(k+1));
            int64_t val2 = (n/(k+1)) * (m / 1);
            ans = max(val1, val2);
        } else {
            if (k <= m-1) {
                int64_t val1 = (n / 1) * (m/(k+1));
                int64_t val2 = (n / n) * (m/(k+2-n));
                ans = max(val1, val2);
            } else {
                int64_t val1 = (n/(k+2-m)) * (m/m);
                int64_t val2 = (n/n) * (m/(k+2-n));
                ans = max(val1, val2);
            }
        }
    }
    cout << ans << "\n";
    return EXIT_SUCCESS;
}
