#include <iostream>
#include <vector>

// 求区间和

using namespace std;

int normalVersion(vector<int>& nums, int lower, int upper) {
	int size = nums.size();
	vector<int64_t> sums(size, 0);
	for (int i = 0; i < size; i++) {
		sums[i] = nums[i] + sums[i - 1];
	}

	int ans = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) {
			if ((sums[j] - sums[i] + nums[i] >= lower) && (sums[j] - sums[i] + nums[i] <= upper)) {
				ans++;
			}
		}
	}
	return ans;
}

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
       return 0; 
    }
};

int main() {
	vector<int> v = {-2, 5, -1};
	int ret = normalVersion(v, -2, 2);
	cout << "ret is:" << ret << "\n";

	return 0;
}
