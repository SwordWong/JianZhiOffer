#include "ListNode.h"
using namespace std;
namespace MergeList{
	class Solution {
	public:
		ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
		{
			ListNode* false_head = new ListNode(0);
			ListNode* tail = false_head;
			ListNode* p1 = pHead1;
			ListNode* p2 = pHead2;
			while (p1 && p2) {
				if (p1->val < p2->val) {
					ListNode* p_next = p1->next;
					tail->next = p1;
					tail = p1;
					p1->next = NULL;
					p1 = p_next;
				}
				else {
					ListNode* p_next = p2->next;
					tail->next = p2;
					tail = p2;
					p2->next = NULL;
					p2 = p_next;
				}
			}
			while (p1) {
				ListNode* p_next = p1->next;
				tail->next = p1;
				tail = p1;
				p1->next = NULL;
				p1 = p_next;
			}
			while (p2) {
				ListNode* p_next = p2->next;
				tail->next = p2;
				tail = p2;
				p2->next = NULL;
				p2 = p_next;
			}
			return false_head->next;
		}

	};
}