#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
int used[N];
bool prime[N];
vector<pair<int, int>> res;
int c[N];
int v[N];
bool visited[N];

void build_prime_table(int n) {
    for (int i = 0; i <= n; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;
    for (int i = 2; i*i <= n; i++) {
        if (!prime[i]) continue;
        for (int j = i*i; j <= n;  j += i) {
            prime[j] = false;
        }
    }
    for (int i = 1; i <= n; i++) {
        c[i] = c[i-1] + prime[i];
    }
}

int main(int argc, char **argv) {
    build_prime_table(100);
    int n;
    cin >> n;
    build_prime_table(n);
    cout << (n-1-(c[n]-c[n/2]))/2 << "\n";
    for (int i = n/2; i >= 2; i--) {
        if (prime[i]) {
            int cnt = 0;
            for (int j = i; j <= n; j += i) {
                if (!visited[j]) v[cnt++] = j;
            }
            for (int j = cnt-1; j > 0; j -= 2) {
                int vv = v[j-1];
                if (j == 2) vv = v[0];
                cout << v[j] << " " << vv << "\n";
                visited[v[j]] = true;
                visited[vv] = true;
            }
        }
    }
    return EXIT_SUCCESS;
}
