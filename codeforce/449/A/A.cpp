#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv)
{
    int64_t n, m, k;
    cin >> n >> m >> k;

    if (n + m < k + 2)  {
        std::cout << -1 << "\n";
        return 0;
    }

    if (n > m) swap(n, m);
    int64_t ans = 0;
    int64_t y = 1;
    for (int64_t x = 1; x <= n &&  x * y <= n * m; x++) {
        y = k + 2 - x;
        if (y < 1) break; 
        int64_t val = (n / x) * (m / y);
        if ( val > ans) {
            ans = val;
        }
    }
    cout << ans << "\n";


    return EXIT_SUCCESS;
}
