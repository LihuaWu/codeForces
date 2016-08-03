//#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <map>
#include <stdlib.h>
#include <string.h>

using namespace std;

void findroot(int v, vector<int>& path) {
    while (v != 1) {
        path.push_back(v);
        v /= 2;
    }
}

void lca(int u, int v, vector<int>& path) {
    vector<int> n1, n2;
    findroot(u, n1);    
    findroot(v, n2);
    int i = 0;
    for (i = 0; i < n1.size() && i < n2.size(); i++) {
        if (n1[n1.size()-i-1] != n2[n2.size()-i-1]) {
            break;
        }
    }
    for (int j = i; j < n1.size(); j++) {
        path.push_back(n1[n1.size()-j-1]);
    }
    for (int j = i; j < n2.size(); j++) {
        path.push_back(n2[n2.size()-j-1]);
    }
}

map<int64_t, int> we;

int main(int argc, char **argv) {
    int q;
    cin >> q;
    //memset(we, 0, sizeof we);
    for(int i = 0; i < q; i++) {
        int t, v, u, w;
        cin >> t;
        if (t == 1) {
            cin >> v >> u >> w;
        } else {
            cin >> v >> u;
        }
        //cin >> t >> v >> u >> w;
        vector<int> path;
        lca(u, v, path);
        //for_each(path.begin(), path.end(), [](int c) { cout << c << " "; }); 
        //cout << "\n";
        //return 0;
//        cout << "t : " << t << "\n";
        if (t == 1) {
            for (auto & p : path) {
                we[p] += w;
            }
        } else if (t == 2) {
            int sum = 0;
            for (auto & p : path) {
                sum += we[p];
            }
            cout << sum << "\n";
        }
    }


    return EXIT_SUCCESS;
}
