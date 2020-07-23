// Author: xhdhr10000
// Date: 2020-04-22
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        queue<pair<TreeNode*, int>> q;
        int current_level = 0;

        if (root) q.push(make_pair(root, 0));
        while (!q.empty()) {
            TreeNode *n = q.front().first;
            int level = q.front().second;
            q.pop();
            if (q.empty() || q.front().second > current_level) {
                ret.push_back(n->val);
                current_level = level + 1;
            }
            if (n->left) q.push(make_pair(n->left, level+1));
            if (n->right) q.push(make_pair(n->right, level+1));
        }

        return ret;
    }
};
