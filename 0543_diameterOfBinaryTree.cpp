// Author: xhdhr10000
// Date: 2020-03-10
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
    int diameterOfBinaryTree(TreeNode* root) {
        heightOfTree(root);
        return diameter;
    }
private:
    int heightOfTree(TreeNode* node) {
        if (!node) return 0;
        int left = heightOfTree(node->left);
        int right = heightOfTree(node->right);
        diameter = std::max(diameter, left + right);
        return std::max(left, right) + 1;
    }
    int diameter = 0;
};
