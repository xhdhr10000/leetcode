// Author: xhdhr10000
// Date: 2019-05-14
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    struct TreeNode *left = NULL, *right = NULL;
    int count = 0;
    if (!root) return NULL;
    if (p == q) return p;
    if (root->left) left = lowestCommonAncestor(root->left, p, q);
    if (root->right) right = lowestCommonAncestor(root->right, p, q);
    if (root == p || left == p || right == p) count += 1;
    if (root == q || left == q || right == q) count += 2;
    if (count == 3) return root;
    if (count == 1) return p;
    if (count == 2) return q;
    if (left) return left;
    if (right) return right;
    return NULL;
}
