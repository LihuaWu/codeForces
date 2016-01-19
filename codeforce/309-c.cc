#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int MAX = 1e6 + 5;
vector<pair<int,int> > E[MAX];
bool vis[MAX];
int group[MAX];

const int MOD = 1e9+7;

bool fail = false;

long long pow1(long long base, int exponent) {
	long long res = 1;
	while (exponent) {
		if (exponent & 1) res = res * base % MOD;
		base = base * base % MOD;
		exponent >>= 1;
	}
	return res;
}

void dfs(int x, int y) {
	if (fail) return;
	vis[x] = true;
	group[x]  = y;

	for (int i = 0; i < E[x].size(); i++) {
		int u = E[x][i].first;
		int v = E[x][i].second;

		int side = v == 1 ? y : 3 - y;
		if (!vis[u]) { dfs(u, side); }
	   	else {
			if (group[u] != side) fail = true;
		}
	}
}


int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		E[a].push_back(make_pair(b, c));
		E[b].push_back(make_pair(a, c));
	}
	int tot = 0;
	for (int i = 1; i <= n && !fail; ++i) {
		if (!vis[i]) {
			dfs(i, 1);
			tot++;
		}
	}

	if (fail) cout << 0;
	else cout << pow1(2, tot - 1);

	return 0;
}

