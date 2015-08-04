#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <typename Iterator>
inline bool same_string(Iterator a, Iterator b, size_t len) {
	bool same = true;
	for (int i = 0; i < len; i++) {
		if (*(a+i) != *(b+i)) {same = false; break; }
	}
	return same;
}

template <typename Iterator>
bool is_the_same(Iterator a, Iterator b, size_t len) {
	if (same_string(a, b, len)) {return true;}
	if (len & 0x01) return false;
	len >>= 1;
	return (is_the_same(a, b, len) && is_the_same(a + len, b+len, len) ) || (is_the_same(a, b+len, len) && is_the_same(a + len, b, len));
}

string string_hash(const string& a) {
	size_t len = a.size();
	if (len & 0x01) return a;
	string lhs = string_hash(a.substr(0, len >> 1));
	string rhs = string_hash(a.substr(len>> 1, len >> 1));
	if (lhs < rhs) return lhs + rhs;
	else return rhs + lhs;
}

int main() {
	std::string a, b;
	cin >> a >> b;
	
	cout << (string_hash(a) == string_hash(b) ? "YES" : "NO");
	return 0;
}
