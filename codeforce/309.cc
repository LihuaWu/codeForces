 //From::http://codeforces.com/contest/553/problem

#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>
#include <list>
#include <utility>

using namespace std;
//A. Kyota and Colored Balls

int64_t comb(int64_t n, int64_t m, vector<vector<int64_t> >& A) {
        int64_t Mod = 1000000007;
        if (A[n][m] != -1) return A[n][m];

        if (n == 0 || m == 0) return 1;
        if (n < 0 || m < 0) throw std::runtime_error("m and n should be greater than zero.");
        if (n <= m) return 1;

        A[n][m] = (comb(n - 1, m - 1, A) + comb(n - 1, m, A)) % Mod;
        return A[n][m];

}

void ColoredBalls() {
        int64_t Mod = 1000000007;
        int64_t N;
        cin >> N;
        int64_t total = 0;
        int64_t res = 1;
        vector<vector<int64_t> > A(1010, vector<int64_t>(1010, -1));
        for (int64_t i = 0; i < N; ++i) {
                int64_t cur;
                cin >> cur;
                total += cur;

                res = (res * comb(total - 1, cur - 1, A) % Mod) % Mod;
        }
        cout << res;
}

//B. Kyoya and Permutation.

vector<int64_t> f(100, -1);
int64_t fib(int n) {
	if (n <= 0) throw std::runtime_error("n must be greater than zero.");
	else if (n == 1 || n == 2) {
		f[n] = 1;
	} else if (n > 2 && f[n] == -1) {
		f[n] = fib(n -1) + fib(n - 2);
	}
	return f[n];
}

void cal(list<int>& v, int n, int64_t k) {
	if (n <= 0) return;
	int64_t pivot = fib(n);
	if (k <= pivot) {
		cal(v, n-1, k);
		for_each(v.begin(), v.end(), [](int& c) { c += 1;});
		v.push_front(1);
	} else {
		cal(v, n-2, k - pivot);
		for_each(v.begin(), v.end(), [](int& c) { c += 2; });
		v.push_front(1);
		v.push_front(2);
	}
}

//classic solution for B.
//#include <bits/stdc++.h>
//using namespace std;
//
//#define ll long long
//const int N = 55;
//
//ll dp[N];
//
//int main(){
//
//    int n;
//    ll k;
//
//    dp[0] = 1, dp[1] = 1;
//    for(int i = 2; i < N; i++)  dp[i] = dp[i - 1] + dp[i - 2];
//
//    cin>>n>>k;
//
//    for(int i = 1; i <= n; i++){
//        if(k > dp[n - i])   cout<<i + 1<<" "<<i<<" ", k -= dp[n - i], i++;
//        else cout<<i<<" ";
//    }
//    return 0;
//}


void KthPerm() {
	int n;
	int64_t k;
	cin >> n >> k;

	list<int> v;
	cal(v, n, k);
	for_each(v.begin(), v.end(), [](int c) {cout << c << " "; });
}

// C Love Triangles
//考察二分图
// 题解分析: http://codeforces.com/blog/entry/18842

int main() {
      //  ColoredBalls();
	  //KthPerm();
	  LoveTriangleSolution sol;
        return 0;
}





















