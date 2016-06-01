#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int l[N];
int n;

int main(int argc, char **argv) {
    cin >> n;
//    cout << "n:" << n << "\n";
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    sort(l, l+n);
    int sum = 0;
    for_each(l, l+n-1, [&sum](int c) { sum += c; });
    cout << (abs(sum - l[n-1]) + 1);


    return EXIT_SUCCESS;
}
