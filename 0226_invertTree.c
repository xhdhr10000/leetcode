// Author: xhdhr10000
// Date: 2019-08-10
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root){
    if (!root) return NULL;
    struct TreeNode *t = root->left;
    root->left = root->right;
    root->right = t;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}
