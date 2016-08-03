//#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main(int argc, char **argv)
{
    string ori;
    cin >> ori;
    int pos = ori.find('e');
    string exp = ori.substr(pos+1);
    //cout << exp << "\n";

    string base = ori.substr(0, pos);
    ////cout << base << "\n";

    pos = base.find('.');
    size_t left = base.size() - pos - 1;

    istringstream iss(base);
    int base_int;
    iss >> base_int;

    istringstream iss3(exp);
    int exp_int;
    iss3 >> exp_int;

    string s;

    for (int i = 0; i < pos; i++) {
        s += base[i];
    }
    //cout << "s1:" << s << "\n";
    //cout << exp_int << "\n";
    int i = 0;
    for (i = 0; i < exp_int; i++) {
        if (i < left) {
            s += base[i+pos+1];
        } else {
            s += '0';
        }
    }
    if (exp_int < left) {
        s += '.';
        for (; i < left; i++) {
           s += base[i+pos+1];
        }
    }
    cout << s << "\n";
    return EXIT_SUCCESS;
}
