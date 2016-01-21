// Solving problem:
// http://www.geeksforgeeks.org/count-total-set-bits-in-all-numbers-from-1-to-n/
// The way to solve these sorts of problems is to write out the first few values, and look for a pattern
//
// Number  binary   # bits set   F(n)
// 1       0001     1            1
// 2       0010     1            2
// 3       0011     2            4
// 4       0100     1            5
// 5       0101     2            7
// 6       0110     2            9
// 7       0111     3            12
// 8       1000     1            13
// 9       1001     2            15
// 10      1010     2            17
// 11      1011     3            20
// 12      1100     2            22
// 13      1101     3            25
// 14      1110     3            28
// 15      1111     4            32
// It takes a bit of staring at, but with some thought you notice that the binary-representations of the first 8 and the last 8 numbers are exactly the same, except the first 8 have a 0 in the MSB (most significant bit), while the last 8 have a 1. Thus, for example to calculate F(12), we can just take F(7) and add to it the number of set bits in 8, 9, 10, 11 and 12. But that's the same as the number of set-bits in 0, 1, 2, 3, and 4 (ie. F(4)), plus one more for each number!
//
// #    binary
// 0    0 000
// 1    0 001
// 2    0 010
// 3    0 011
// 4    0 100
// 5    0 101
// 6    0 110
// 7    0 111
//
// 8    1 000  <--Notice that rightmost-bits repeat themselves
// 9    1 001     except now we have an extra '1' in every number!
// 10   1 010
// 11   1 011
// 12   1 100
// Thus, for 8 <= n <= 15, F(n) = F(7) + F(n-8) + (n-7). Similarly, we could note that for 4 <= n <= 7, F(n) = F(3) + F(n-4) + (n-3); and for 2 <= n <= 3, F(n) = F(1) + F(n-2) + (n-1). In general, if we set a = 2^(floor(log(n))), then F(n) = F(a-1) + F(n-a) + (n-a+1)
//
// This doesn't quite give us an O(log n) algorithm; however, doing so is easy. If a = 2^x, then note in the table above that for a-1, the first bit is set exactly a/2 times, the second bit is set exactly a/2 times, the third bit... all the way to the x'th bit. Thus, F(a-1) = x*a/2 = x*2^(x-1). In the above equation, this gives us
//
// F(n) = x*2x-1 + F(n-2x) + (n-2x+1)
// Where x = floor(log(n)). Each iteration of calculating F will essentially remove the MSB; thus, this is an O(log(n)) algorithm.


#include <iostream>

using namespace std;

int _getBits(int n) {
	int ret = 0;
	while (n > 0) {
		if (n % 2 == 1) {
			ret += 1;
		}
		n >>= 1;
	}
	return ret;
}

int CountBits1ToNVersion1(int n) {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ret += _getBits(i);
	}
	return ret;
}

int getLeftMostBitPos(int n) {
	int ret = 0;
	while (n > 0) {
		n >>= 1;	
		ret += 1;
	}
	return ret;
}

int getNextMostBitPos(int n, int m) {
	int tmp = 1 << m;
	while (n < tmp) {
		tmp >>= 1;
		m--;
	}
	return m;
}

int CountBits1ToNVersion2(int n); 

int _countSetBits(int n, int m) {
	if (n == 0) return 0;
	m = getNextMostBitPos(n, m);
	
	if (n == (1 << m + 1) - 1) {
		return (m + 1) * (1 << m);
	}
	n -= (1 << m);
	cout << "n is:" << n << " m is:" << m << "\n";
	return (n + 1) + m * (1 << (m-1)) + CountBits1ToNVersion2(n);
}

int CountBits1ToNVersion2(int n) {
	int m = getLeftMostBitPos(n);
	return _countSetBits(n, m);
	return 0;
}


int main() {
	for (int i = 25; i < 26; i++) {
		//cout << "i is: " << i  << " ret: "<< CountBits1ToNVersion1(i) << "left most:" << getLeftMostBitPos(i) << "\n"; 
		cout << "i is: " << i  << " ret: "<< CountBits1ToNVersion1(i) << " version2:" << CountBits1ToNVersion2(i) << "\n"; 
		//int m = getLeftMostBitPos(i);
		//cout << "i is:" << i << " equal: " << (1 << m) << " next: " << (1 << getNextMostBitPos(i, m)) <<  "\n";
	}


	return 0;
}
