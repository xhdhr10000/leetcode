// Author: xhdhr10000
// Date: 2019-12-19
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        if (!root) return ret;
        ret.push_back(root->val);
        auto left = preorderTraversal(root->left);
        ret.insert(ret.end(), left.begin(), left.end());
        auto right = preorderTraversal(root->right);
        ret.insert(ret.end(), right.begin(), right.end());
        return ret;
    }
};
