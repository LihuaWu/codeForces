/*
 * http://codeforces.com/contest/659/problem/A
 * A. Round House
 * time limit per test1 second
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 *
 * */

#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int ret = ((a + b) % n + n) % n;
    std::cout << (ret == 0 ? n : ret )<< "\n";
    return 0;
}
