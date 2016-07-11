#include <bits/stdc++.h>
using namespace std;
int main(int argc, char **argv) {
    int n, d;
    cin >> n >> d;
    vector<int> v(d);
    vector<int> sum(d, 0);
    for (int i = 0; i < d; i++) {
        string s;
        cin >> s;
        assert(s.size() == n);
        bool flag = true;
        for (auto & c : s) {
            if (c != '1') { flag = false; break; }
        }
        v[i] = flag ? 0 : 1;
    }
    
    for (size_t i = 0; i < v.size(); i++) {
        if (i > 0 && v[i] > 0) { sum[i] = sum[i-1] + 1; }
        else sum[i] = v[i];
    }
    cout << *max_element(sum.begin(), sum.end()) << "\n";

    return EXIT_SUCCESS;
}
