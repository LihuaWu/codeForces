#include <bits/stdc++.h>
using namespace std;

const double PI = atan(1)*4;

int main(int argc, char **argv)
{
    double d, h, v, e;
    cin >> d >> h >> v >> e;

    double a_speed = v * 4.0 / (PI*d*d);
    if (e > a_speed) cout << "NO";
    else {
        cout << "YES\n";
        double time = h * 1.0 / (a_speed - e); 
        cout << setprecision(13) << time << "\n";
    }
    return EXIT_SUCCESS;
}
