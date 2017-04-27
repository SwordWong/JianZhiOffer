#include "treenode.h"
#include <vector>
namespace FindPath{
	class Solution {
	public:
		vector<vector<int> > FindPath(TreeNode* root, int expectNumber) {
			vector<vector<int> > res;
			vector<int> path;
			if(root)
				FindPath(root, expectNumber, path, res);
			return res;
		}
		void FindPath(TreeNode* root, int expectNumber, vector<int> path, vector<vector<int> >& res) {
			path.push_back(root->val);
			if (!root->left && !root->right && root->val == expectNumber) {
				res.push_back(path);
				return;
			}
			int en_child = expectNumber - root->val;
			if(root->left)
				FindPath(root->left, en_child, path, res);
			if(root->right)
				FindPath(root->right, en_child, path, res);
		}
	};
}