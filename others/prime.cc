#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

vector<size_t>  primes(size_t n) {
    vector<size_t> ret;
    if (n < 2)  return ret;
    vector<bool> not_a_prime(n + 1);
    not_a_prime[0] = true, not_a_prime[1] = true;
    int pos;
    for (int i = 2; i <=n; i++) {
        if (!not_a_prime[i]) {
            pos = i ;
            for (int j = 2; j * pos <= n; j++) {
                not_a_prime[j * pos] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!not_a_prime[i]) {
            ret.push_back(i);
        }
    }
    return ret;
}

int main() {
    vector<size_t> v = primes(101);
    size_t ret = 1;
    for (auto i : v) {
        std::cout << i << " ";
        ret *= i;
    }

    std::cout << "\nTotal size: " << v.size() << "\n";
    std::cout << "ret is: " << ret << "\n";
    int cnt = 0;
    size_t maxNum = numeric_limits<size_t>::max();
    while (maxNum) {
        maxNum /= 101;
        cnt++;
    }
    std::cout << "cnt:" << cnt << "\n";
    

    return 0;
}
