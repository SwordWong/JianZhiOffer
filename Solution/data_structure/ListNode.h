#pragma once
#include <algorithm>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {
	}
};
ListNode* BuildList(vector<int> array) {
	if (array.empty())
		return NULL;
	ListNode* head = new ListNode(array[0]);
	ListNode* tail = head;
	for (int i = 1; i < array.size(); i++) {
		ListNode* node = new ListNode(array[i]);
		tail->next = node;
		tail = node;
	}
	return head;
}
void DeleteList(ListNode* head) {
	ListNode* p = head;
	while (!p) {
		ListNode* node = p;
		p = p->next;
		delete node;
	}
}
