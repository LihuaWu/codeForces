// Solving problem: http://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/
//
// Given an integer array of n integers, find sum of bit differences in all pairs that can be formed from array elements. Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y. 
// For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).
// 
// Examples:
// 
// Input: arr[] = {1, 2}
// Output: 4
// All pairs in array are (1, 1), (1, 2)
//                        (2, 1), (2, 2)
// Sum of bit differences = 0 + 2 +
//                          2 + 0
//                       = 4
// 
// Input:  arr[] = {1, 3, 5}
// Output: 8
// All pairs in array are (1, 1), (1, 3), (1, 5)
//                        (3, 1), (3, 3) (3, 5),
//                        (5, 1), (5, 3), (5, 5)
// Sum of bit differences =  0 + 1 + 1 +
//                           1 + 0 + 2 +
//                           1 + 2 + 0 
//                        = 8
// 

#include <assert.h>

#include <iostream>
#include <vector>

using namespace std;

int _getBits(int num) {
	int ret = 0;
	while (num > 0) {
		if (num & 0x01) {
			ret++;
		} 
		num >>= 1;
	}
	return ret;
}

int normalVersion(const vector<int>& nums) {
	int size = nums.size();
	int ret = 0;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			 ret += _getBits(nums[i] ^ nums[j]);
		}
	}
	return ret << 1;
}

int EfficientVersion(const vector<int>& nums) {
	int size = nums.size();
	int ret = 0;
	for (int i = 0; i < 32; i++) {
		int count = 0;
		for (int j = 0; j < size; j++) {
			if (nums[j] & (1 << i) ) { count++;}
		}
		ret += count * (size - count) * 2;
	}
	return ret;
}

int main() {
	vector<int> v = {1,2};
	int ret = normalVersion(v);
	assert(ret == 4);
	ret = EfficientVersion(v);
	assert(ret == 4);


	v = {1,3,5};
	ret = normalVersion(v);
	assert(ret == 8);
	ret = EfficientVersion(v);
	assert(ret == 8);


	

	return 0;
}
