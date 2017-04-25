#include "treenode.h"
#include <vector>
#include <queue>
namespace PrintFromTopToBottom{
	class Solution {
	public:
		vector<int> PrintFromTopToBottom(TreeNode* root) {
			vector<int> res;
			queue<TreeNode*> q;
			if(root)
				q.push(root);
			while (!q.empty()) {
				TreeNode* node = q.front();
				q.pop();
				res.push_back(node->val);
				if (node->left)
					q.push(node->left);
				if (node->right)
					q.push(node->right);
			}
			return res;
		}
	};
}