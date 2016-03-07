#include "../common/fwd.h"

class Solution {
public:
    bool isValidSerialization(string preorder) {
        int diff = 1;
        auto vec = split(preorder, ',');
        for (auto c : vec) {
            diff -= 1;
            if (diff < 0) return false;
            if (c != "#") diff += 2;
        }
        return diff == 0;
    }
    bool isValidSerialization2(string preorder) {
        auto vec = split(preorder, ',');
        vector<string> stack;
        int stack_size(0);
        for (auto c : vec) {
            stack.push_back(c);
            stack_size = stack.size();
            while ( stack_size >= 3 
                    && stack[stack_size - 1] == "#" 
                    && stack[stack_size - 2] == "#"
                    && stack[stack_size - 3] != "#") {

                for (int i = 0; i < 3; i++) { stack.pop_back(); }
                stack.push_back("#");
                stack_size = stack.size();
            }
        }
        return  stack_size == 1 && stack[0] == "#";
    }
private:
    vector<string> split(const string& s, const char& c) {
    string buff{""};
    vector<string> v;
    
    for(auto n:s)
    {
        if(n != c) buff+=n; 
        else if(n == c && buff != "") { v.push_back(buff); buff = ""; }
    }
    if(buff != "") v.push_back(buff);
    
    return v;
}

};


int main() {
    Solution s;

    //auto f = [&](string preorder) ->bool { return s.isValidSerialization(preorder); };
    auto f = [&](string preorder) ->bool { return s.isValidSerialization2(preorder); };

    string preorder;

    preorder = "9,3,4,#,#,1,#,#,2,#,6,#,#";
    assert(true == f(preorder));

    preorder = "9,#,#,3";
    assert(false == f(preorder));

    preorder = "9,#,92,#,#";
    assert(true == f(preorder));
    
    
    return 0;
}
