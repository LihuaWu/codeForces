//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(int argc, char **argv) {
    int t, s, x;
    cin >> t >> s >> x;
    if (x - t < s) {
        cout << (x-t == 0 ? "YES" : "NO") << "\n"; 
    } else {
        cout << (((x-t) %s == 0 || ((x-t) %s == 1)) ? "YES" : "NO") << "\n"; 
        
    }
    return EXIT_SUCCESS;
}
