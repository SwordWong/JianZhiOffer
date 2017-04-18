#pragma once
#include "ListNode.h"
namespace ReverseList {
	class Solution {
	public:
		ListNode* ReverseList(ListNode* pHead) {
			ListNode* pHead_new = NULL;
			ListNode* p = pHead;
			while (p) {
				ListNode* p_next = p->next;
				p->next = pHead_new;
				pHead_new = p;
				p = p_next;
			}
			return pHead_new;
		}
	};
}
