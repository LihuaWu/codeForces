// http://www.geeksforgeeks.org/find-closest-leaf-binary-tree/
//Find the closest leaf in a Binary Tree
// Given a Binary Tree and a key ‘k’, find distance of the closest leaf from ‘k’.
// 
// Examples:
// 
//               A
//             /    \    
//            B       C
//                  /   \  
//                 E     F   
//                /       \
//               G         H
//              / \       /
//             I   J     K
// 
// Closest leaf to 'H' is 'K', so distance is 1 for 'H'
// Closest leaf to 'C' is 'B', so distance is 2 for 'C'
// Closest leaf to 'E' is either 'I' or 'J', so distance is 2 for 'E' 
// Closest leaf to 'B' is 'B' itself, so distance is 0 for 'B' 
// We strongly recommend to minimize your browser and try this yourself first
// The main point to note here is that a closest key can either be a descendent of given key or can be reached through one of the ancestors.
// The idea is to traverse the given tree in preorder and keep track of ancestors in an array. When we reach the given key, we evaluate distance of the closest leaf in subtree rooted with given key. We also traverse all ancestors one by one and find distance of the closest leaf in the subtree rooted with ancestor. We compare all distances and return minimum.
// 
// C++JavaPython
// A C++ program to find the closesr leaf of a given key in Binary Tree
//


#include <string>
#include <algorithm>
#include <iostream>

using namespace std;
struct Node {
	string val;
	Node* left;
	Node* right;
	Node(const string& value) : val(value) {}
};

int findMinDistance(Node* root) {
	int left = 0, right = 0;
	if (!root) return 0;

	if (!root->left && !root->right) {
		return 0;
	} else {
		if (root->left) {
			left = findMinDistance(root->left);
		}
		if (root->right) {
			right = findMinDistance(root->right);
		}

		if (root->left && root->right) { return 1 + min(left, right); }
		else if (root->right) { return 1 + right; }
	 	else { return 1 + left; }
	}
}

int findCloset(Node* root, Node* node) {
	int subTreeDist = findMinDistance(node);
}

int main() {
	Node* root = new Node("A");
	root->left = new Node("B");
	root->right = new Node("C");
	root->right->left = new Node("E");
	root->right->right = new Node("F");	
	root->right->left->left = new Node("G");
	root->right->left->left->left = new Node("I");
	root->right->left->left->right= new Node("J");
	root->right->right->right = new Node("H");
	root->right->right->right->left = new Node("K");


	cout << findMinDistance(root) << "\n";
	cout << findMinDistance(root->left) << "\n";
	cout << findMinDistance(root->right) << "\n";
	cout << findMinDistance(root->right->left) << "\n";


	return 0;
}
