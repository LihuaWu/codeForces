#include <bits/stdc++.h>
using namespace std;

int64_t gcd(int64_t a, int64_t b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int64_t lcm(int64_t a, int64_t b) {
    int64_t g = gcd(a, b);
    if (g) {
        return a / g * b;
    }
    return 0;
}


int main(int argc, char **argv) {
    int64_t n, k;
    cin >> n >> k;
    int64_t ans = 1;
    for (int i = 0; i < n; i++) {
        int64_t c; cin >> c; 
        ans = gcd(k, lcm(ans, c));
        if (ans == k) {
            cout << "Yes\n";

            return EXIT_SUCCESS;
        }
    }
    cout << "No" << "\n";

}
