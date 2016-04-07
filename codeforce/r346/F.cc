/*
http://codeforces.com/contest/659/problem/F
Polycarp and Hay
time limit per test4 seconds
memory limit per test512 megabytes
inputstandard input
outputstandard output
*/

#include <iostream>
#include <map>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> table(n, vector<int>(m));
    map<int, int> greaterThan;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> table[i][j];
            int& value = table[i][j];
            if (greaterThan.count(value) == 0) greaterThan[value] = 0;
            for (auto & i : greaterThan) {
                if (value >= i.first) {
                    i.second += 1;
                }
            }
        }
    }

    for (auto & i : greaterThan) {
        if (i.first * i.second >= k) {
            
        }
    }


    return 0;
}
