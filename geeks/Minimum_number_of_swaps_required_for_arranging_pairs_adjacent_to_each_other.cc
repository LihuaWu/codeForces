// solving problem: http://www.geeksforgeeks.org/minimum-number-of-swaps-required-for-arranging-pairs-adjacent-to-each-other/
//


//Minimum number of swaps required for arranging pairs adjacent to each other
//There are n-pairs and therefore 2n people. everyone has one unique number ranging from 1 to 2n. All these 2n persons are arranged in random fashion in an Array of size 2n. We are also given who is partner of whom. Find the minimum number of swaps required to arrange these pairs such that all pairs become adjacent to each other.
//
//Example:
//
//Input:
//n = 3  
//pairs[] = {1->3, 2->6, 4->5}  // 1 is partner of 3 and so on
//arr[] = {3, 5, 6, 4, 1, 2}
//
//Output: 2
//We can get {3, 1, 5, 4, 6, 2} by swapping 5 & 6, and 6 & 1
//Source: Google Interview Question
//
//We strongly recommend you to minimize your browser and try this yourself first.
//
//The idea is to start from first and second elements and recur for remaining elements. Below are detailed steps/
//
//1) If first and second elements are pair, then simply recur 
//   for remaining n-1 pairs and return the value returned by 
//   recursive call.
//
//2) If first and second are NOT pair, then there are two ways to 
//   arrange. So try both of them return the minimum of two.
//   a) Swap second with pair of first and recur for n-1 elements. 
//      Let the value returned by recursive call be 'a'.
//   b) Revert the changes made by previous step.
//   c) Swap first with pair of second and recur for n-1 elements. 
//      Let the value returned by recursive call be 'b'.
//   d) Revert the changes made by previous step before returning
//      control to parent call.
//   e) Return 1 + min(a, b)


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSwapUtil(int arr [], int pair [], vector<int>& index,
				 int i, int n) {
	if (i > n) return 0;
	if (pair[arr[i]] == arr[i + 1]) {
		return minSwapUtil(arr, pair, index, i + 2, n);
	} else {
		int pos = index[pair[arr[i]]];
		swap(arr[i + 1], arr[pos]);
		swap(index[arr[i + 1]], index[arr[pos]]);
		int a = minSwapUtil(arr, pair, index, i + 2, n);
		swap(arr[i + 1], arr[pos]);
		swap(index[arr[i + 1]], index[arr[pos]]);

		pos = index[pair[arr[i + 1]]];
		swap(arr[i], arr[pos]);
		swap(index[arr[i]], index[arr[pos]]);

		int b = minSwapUtil(arr, pair, index, i + 2, n);
		swap(arr[i], arr[pos]);
		swap(index[arr[i]], index[arr[pos]]);

		return 1 + min(a, b);
	}
}

int minSwaps(int n, int arr [], int pair []) {
	vector<int> index(2 * n + 1);
	for (int i = 1; i <= 2 * n; i++) {
		index[arr[i]] = i; 
	}
	return minSwapUtil(arr,  pair, index, 1, 2 * n);
}

int main() {

	int arr[] = {0, 3, 5, 6, 4, 1, 2};
 
    // if (a, b) is pair than we have assigned elements
    // in array such that pairs[a] = b and pairs[b] = a
    int pairs[] = {0, 3, 6, 1, 5, 4, 2};
    int m = sizeof(arr)/sizeof(arr[0]);
 
    int n = m/2;  // Number of pairs n is half of total elements
 
    // If there are n elements in array, then
    // there are n pairs
    cout << "Min swaps required is " << minSwaps(n, pairs, arr) << "\n";


	return 0;
}
