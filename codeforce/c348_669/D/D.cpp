#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv) {
    int n, q;
//    cin >> n >> q;
    scanf("%d%d", &n, &q);
    int odd = 0, even = 1;
    int t, step;
    for (int i = 0; i < q; i++) {
//        cin >> t;
        scanf("%d", &t);
        if (t == 1) {
 //           cin >> step;
            scanf("%d", &step);
            step %= n;
            odd = (odd + step + n) % n;
            even = (even + step + n) % n;
        } else {
            if (odd % 2 == 0) {
                odd = (odd + 1 + n) % n;
                even = (even - 1 + n) % n;
            } else {
                odd = (odd - 1 + n) % n;
                even = (even + 1 + n) % n;
            }
        }
    }
    int a[n];
    for (int i = 0; i < n; i += 2) {
        a[(odd + i) % n] = i+1;
        a[(even + i) % n] = i+2;
    }

    for (int i = 0; i < n; i++) {
//        cout << a[i] << " ";
        printf("%d ", a[i]);
    }
    return EXIT_SUCCESS;
}
