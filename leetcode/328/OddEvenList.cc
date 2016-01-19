#include <assert.h>

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
		if (!head) return head;
		ListNode* pOdd = head;
		ListNode* p = pOdd->next;
		ListNode* pNext = NULL;
		while (p && (pNext = p->next)) {
			p->next = pNext->next;
			pNext->next = pOdd->next;
			pOdd->next = pNext;

			pOdd = pOdd->next;
			p = p->next;
		}
		return head;
    }
};

vector<int> ListToVec(ListNode* head) {
	vector<int> v;
	while(head) {
		v.push_back(head->val);
		head = head->next;
	}
	return v;
}

ListNode* VecToList(const vector<int>& v) {
	ListNode dummy(0);
	ListNode* p = &dummy;
	for (auto& i : v) {
		ListNode* node = new ListNode(i);
		p->next = node;
		p = p->next;
	}
	return dummy.next;
}

int main() {
	vector<int> v = {1,2,3,4,5,6,7,8};
	ListNode* list = VecToList(v);
	vector<int> v2 = ListToVec(list);
	assert(v == v2);

	Solution sl;

	ListNode* ret1 = sl.oddEvenList(list);	
	vector<int> v3 = ListToVec(list);
	vector<int> v4 = {1,3,5,7,2,4,6,8};
	assert(v4 == v3);
	

	vector<int> v5 = {1};
	ret1 = sl.oddEvenList(VecToList(v5));
	vector<int> v6 = ListToVec(ret1);
	assert(v5 == v6);

	vector<int> v7 = {};
	ret1 = sl.oddEvenList(VecToList(v7));
	vector<int> v8 = ListToVec(ret1);
	assert(v7 == v8);

	vector<int> v9 = {1,2,3};
	ret1 = sl.oddEvenList(VecToList(v9));
	vector<int> v10 = ListToVec(ret1);
	vector<int> v11 = {1,3,2};
	assert(v11 == v10);
	

	return 0;
}
