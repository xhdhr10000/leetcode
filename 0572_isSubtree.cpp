// Author: xhdhr10000
// Date: 2020-05-07
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (isSame(s, t)) return true;
        if (s->left && isSubtree(s->left, t)) return true;
        if (s->right && isSubtree(s->right, t)) return true;
        return false;
    }
private:
    bool isSame(TreeNode *s, TreeNode *t) {
        if (!s && !t) return true;
        if ((!s && t) || (s && !t)) return false;
        return s->val == t->val && isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};
