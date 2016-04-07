/*
 * http://codeforces.com/contest/659/problem/C
 * C. Tanya and Toys
 * time limit per test1 second
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * */

#include <vector>
#include <iostream>
#include <iterator>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    set<int> alreadyHas;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        alreadyHas.insert(t);
    }

    vector<int> willBuy;
    for (int i = 1; i <= 10e9; i++) {
        if (alreadyHas.count(i) == 0) {
            if (m >= i) {
                willBuy.push_back(i);
                m -= i;
            } else {
                break;
            }
        }
    }
    std::cout << willBuy.size() << "\n";
    copy(begin(willBuy), end(willBuy), ostream_iterator<int>(cout, " "));
    std::cout << "\n";


    return 0;
}
