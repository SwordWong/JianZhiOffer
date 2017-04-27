#include "treenode.h"
namespace SearchTree2BiList {
	class Solution {
	public:
		TreeNode* Convert(TreeNode* pRootOfTree)
		{
			if (!pRootOfTree)
				return NULL;
			TreeNode* pHead, *pTail;
			Convert(pRootOfTree, pHead, pTail);
			return pHead;
		}
		void Convert(TreeNode* pRootOfTree, TreeNode* &h, TreeNode* &t) {
			if (!pRootOfTree) {
				h = t = NULL;
				return;
			}	
			TreeNode* node = pRootOfTree;
			h = t = node;
			TreeNode *h_left, *t_left;
			Convert(pRootOfTree->left, h_left, t_left);
			TreeNode *h_right, *t_right;
			Convert(pRootOfTree->right, h_right, t_right);
			node->left = t_left;
			node->right = h_right;
			if (t_left) {
				t_left->right = node;
				h = h_left;
			}	
			if (h_right) {
				h_right->left = node;
				t = t_right;
			}
		}
	};
}