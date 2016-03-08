#include "../common/fwd.h"

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        for (int i = 0; i < x.size(); ++i) {
            if (i >= 3 && x[i] >= x[i-2] && x[i - 1] <= x[i - 3]) { return true; } 
            if (i >= 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) { return true; }
            if (i >= 5 
                && x[i] + x[i - 4] >= x[i - 2] && x[i - 2] >= x[i - 4]
                && x[i - 1] + x[i - 5] >= x[i - 3] && x [i - 3] >= x[i - 1]) {return true; }
        } 
        return false;
    }
};

int main() {
    Solution s;
    auto f = [&](initializer_list<int>&& x) ->bool {
        vector<int> v = x;
        return s.isSelfCrossing(v);
     };

    assert(true == f({2,1,1,2}));
    assert(false == f({1,2,3,4}));
    assert(true == f({1,1,1,1}));
    assert(false == f({3,3,3,2,1,1}));
    
	return 0;
}
