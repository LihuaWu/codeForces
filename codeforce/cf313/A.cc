#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int n;
	cin >> n;
	bool flag = false;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		if (m == 1) {flag = true; break; }

	}

	if (flag) {cout << -1; }
	else {cout << 1;}
}
