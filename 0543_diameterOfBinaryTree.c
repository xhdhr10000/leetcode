// Author: xhdhr10000
// Date: 2019-08-09
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int dfs(struct TreeNode *n, int *ans) {
    if (!n) return 0;
    int l = dfs(n->left, ans);
    int r = dfs(n->right, ans);
    *ans = MAX(*ans, l+r);
    return MAX(l,r)+1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    int ans = 0;
    dfs(root, &ans);
    return ans;
}
