#pragma once
#include <stack>
#include "ListNode.h"
using namespace std;
namespace FindKthToTail {
	class Solution {
	public:
		ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
			if (k < 1)
				return NULL;
			ListNode* fast = pListHead;
			ListNode* slow = NULL;
			int count = 0;
			while (fast) {	
				count++;
				if (count == k)
					slow = pListHead;
				if(count > k)
					slow = slow->next;
				fast = fast->next;
			}
			return slow;
		}
	};
}