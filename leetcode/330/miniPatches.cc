#include "../common/fwd.h"

class Solution {
public:
    //now it can express [1,known_sum)
    int minPatches(vector<int>& nums, int n) {
        size_t known_sum = 1, patch = 0, i = 0;
        while (known_sum <= n) {
            if (i >= nums.size() || known_sum < nums[i]) {
                //add known_sum into the array to maxmize the span.
                known_sum += known_sum;
                patch++;
            } else {
                known_sum += nums[i];
                i++;
            }
        }
        return patch;
    }
};

int main() {
    Solution s;
    auto f = [&](initializer_list<int> nums, int n) {
        vector<int> v = nums;
        return s.minPatches(v, n);
    };

    assert(0 == f({1,2,2}, 5));
    assert(1 == f({1,3}, 6));
    assert(2 == f({1,5,10}, 22));
    assert(3 == f({1,5,10}, 23));
    assert(3 == f({}, 7));
    std::cout << f({1,2,31,43}, 2147483647) << "\n";

    return 0;
}
