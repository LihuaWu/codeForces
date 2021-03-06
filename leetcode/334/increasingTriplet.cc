#include <assert.h>
#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        auto num_size = nums.size();
        if (num_size < 3) return false;
        int a = numeric_limits<int>::max();
        int b = numeric_limits<int>::max();

        for (auto& num : nums) {
            if (num < a ) {a = num; } 
            else if (a < num && num <= b) {b = num;}
            else if (b < num) return true;
        }
        return false;
    }
};

int main() {
    Solution s;
    auto f = [&](vector<int>& nums) ->bool {return s.increasingTriplet(nums); } ;

    vector<int> v;

    v = {1,2};
    assert(false == f(v));

    v = {1,2,3};
    assert(true == f(v));

    v = {1,2,3,4};
    assert(true == f(v));

    v = {4, 3, 2, 1};
    assert(false == f(v));

    v = {2,3,3,3, 2};
    assert(false == f(v));

    v = {5, 4, 4, 4, 5, 6};
    assert(true == f(v));

    v = {2, 3, 1, 5};
    assert(true == f(v));

    return 0;
}
