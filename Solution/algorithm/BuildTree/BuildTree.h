#pragma once
#include "TreeNode.h"
#include <vector>
using namespace std;
/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
namespace BulidTree {
	class Solution {
	public:
		TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
			
			TreeNode* root = buildBinaryTree(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
			
			return root;
		}
	private:
		TreeNode* buildBinaryTree(vector<int> pre, int s_pre, int e_pre,
			vector<int> vin, int s_vin, int e_vin) {
			if (s_pre > e_pre || s_vin > e_vin)
				return NULL;
			TreeNode *node = new TreeNode(pre[s_pre]);
			int ip = findPos(pre[s_pre], vin);
			int len_left = ip - s_vin;
			int len_right = e_vin - ip;
			node->left = buildBinaryTree(pre, s_pre + 1, s_pre + len_left, vin, s_vin, ip - 1);
			node->right = buildBinaryTree(pre, e_pre - len_right + 1, e_pre, vin, ip + 1, e_vin);
			return node;
		}
		int findPos(int val, const vector<int> &arr) {
			for (int i = 0; i < arr.size(); i++) {
				if (arr[i] == val)
					return i;
			}
			return -1;
		}
	};
}
