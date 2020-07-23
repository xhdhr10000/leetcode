// Author: xhdhr10000
// Date: 2020-07-23
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int> count;
        int max = -INT_MAX;
        vector<int> ret;

        if (root) traverse(root, count, max);
        for (auto it = count.begin(); it != count.end(); it++) {
            if (it->second == max) ret.push_back(it->first);
        }
        return ret;
    }
private:
    void traverse(TreeNode *root, map<int, int> &count, int &max) {
        if (root->left) {
            traverse(root->left, count, max);
            root->val += root->left->val;
        }
        if (root->right) {
            traverse(root->right, count, max);
            root->val += root->right->val;
        }
        count[root->val] = count.find(root->val) == count.end() ? 1 : count[root->val] + 1;
        max = std::max(max, count[root->val]);
    }
};
