/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* dfs(struct TreeNode *n, struct TreeNode *p, struct TreeNode *q) {
    struct TreeNode *ret = NULL;
    if (n->left) ret = dfs(n->left, p, q);
    if (ret && ret != p && ret != q) return ret;
    if (n->right) {
        struct TreeNode *t = dfs(n->right, p, q);
        if (ret && t) ret = n;
        else ret = t ? t : ret;
    }
    if (ret && (n == p || n == q)) ret = n;
    else if (n == p) ret = p;
    else if (n == q) ret = q;
    return ret;
}

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    return dfs(root, p, q);
}
