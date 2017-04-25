#include "treenode.h"

namespace MirrorTree{
    class Solution {
    public:
        void Mirror(TreeNode *pRoot) {
            if(!pRoot)
                return;
            Mirror(pRoot->right);
            Mirror(pRoot->left);
            TreeNode *tmp = pRoot->right;
            pRoot->right = pRoot->left;
            pRoot->left = tmp;
        }
    };
}