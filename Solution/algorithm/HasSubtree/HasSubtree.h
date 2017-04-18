#include "treenode.h"
namespace HasSubtree {
	class Solution {
	public:
		bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
		{
			if (!pRoot2)
				return false;
			else if (pRoot1 && pRoot2) {
				if (HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2))
					return true;
				else
					return sameTree(pRoot1, pRoot2);
			}
			else
				return false;
		}
		bool sameTree(TreeNode* pRoot1, TreeNode* pRoot2) {
			if (!pRoot2)
				true;
			else if (pRoot1 && pRoot2) {
				if (
					pRoot1->val == pRoot2->val&&
					sameTree(pRoot1->left, pRoot2->left) &&
					sameTree(pRoot1->right, pRoot2->right))
					return true;
				else
					return false;
			}
			return false;
		}
	};
}