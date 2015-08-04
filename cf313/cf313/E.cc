#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

const int  MAX = 2e5+10;
const int  MOD = 1e9 + 7;

long long inv[MAX], f[MAX], g[MAX];

typedef pair<int, int> PII;

const int MN = 2e3 + 5;
PII p[MN];
int dp[MN];

void init() {
	inv[1] = 1;
	for (int i = 2; i < MAX; i++) {
		inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	}

	f[0] = 1;
	g[0] = 1;
	for (int i = 1; i < MAX; i++) {
		f[i] = f[i - 1] * i % MOD;
		g[i] = g[i - 1] * inv[i] % MOD;
	}
}

long long C(int n, int k) {
	if (k > n || k < 0) return 0;
	return f[n] * g[n - k] % MOD * g[k] % MOD;
}


int main() {
	init();
	int h, w, n;
	long long val;
	cin >> h >> w >> n;

	for (int i = 0; i < n; i++) {
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + n);
	p[n] = PII(h, w);

	for (int i = 0; i <= n; i++) {
		int x = p[i].first, y = p[i].second;
		val = C(x + y - 2, x - 1);
		for (int j = 0; j < i; j++) {
			int u = p[j].first, v = p[j].second;
			val -= dp[j] * C(x + y - u - v, x - u) % MOD;
		}
		dp[i] = (val % MOD + MOD ) % MOD;
	}
	cout << dp[n];
	
	return 0;
}
