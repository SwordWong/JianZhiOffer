#include "RandomListNode.h"
namespace CloneRandomList {
	class Solution {
	public:
		RandomListNode* Clone(RandomListNode* pHead)
		{
			if (!pHead)
				return NULL;
			copyNodes(pHead);
			setRandom(pHead);
			RandomListNode* pHead_new = split(pHead);
			return pHead_new;
		}
		void copyNodes(RandomListNode* pHead) {
			RandomListNode*p = pHead;
			while (p) {
				RandomListNode* node = new RandomListNode(p->label);
				node->next = p->next;
				p->next = node;
				p = node->next;
			}
		}
		void setRandom(RandomListNode* pHead) {
			RandomListNode*p = pHead;
			RandomListNode*p_new = pHead->next;
			while (p_new) {
				if(p->random)
					p_new->random = p->random->next;
				RandomListNode* pnext = p_new->next;
				RandomListNode* pnext_new = NULL;
				if(pnext)
					pnext_new = pnext->next;
				p = pnext;
				p_new = pnext_new;
			}
		}
		RandomListNode* split(RandomListNode* pHead) {
			RandomListNode*p = pHead;
			RandomListNode*p_new = pHead->next;
			RandomListNode* head_new = p_new;
			while (p_new) {
				RandomListNode* pnext = p_new->next;
				RandomListNode* pnext_new = NULL;
				if (pnext)
					pnext_new = pnext->next;
				p->next = pnext;
				p_new->next = pnext_new;
				p = pnext;
				p_new = pnext_new;
			}
			return head_new;
		}
	};
}