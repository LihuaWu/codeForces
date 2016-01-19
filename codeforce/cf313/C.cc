
#include <iostream>

long long pow(int a) {
	return a * a;
}

using namespace std;

int main() {

	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;

	cout << pow(a + b + c) - pow(a) - pow(e) - pow(c);

	return 0;
}
