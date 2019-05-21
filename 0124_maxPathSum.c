// Author: xhdhr10000
// Date: 2019-05-20
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAXINT 0x7fffffff
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
int traverse(struct TreeNode *root, int *ans) {
    int left = -MAXINT, right = -MAXINT, max, ret;
    max = ret = root->val;
    if (root->left) {
        left = traverse(root->left, ans);
        max = MAX(max, left + root->val);
    }
    if (root->right) {
        right = traverse(root->right, ans);
        max = MAX(max, right + root->val);
    }
    ret = max;
    max = MAX(max, left);
    max = MAX(max, right);
    if (root->left && root->right) max = MAX(max, left + right + root->val);
    *ans = MAX(*ans, max);
    return ret;
}

int maxPathSum(struct TreeNode* root){
    int max = -MAXINT;
    traverse(root, &max);
    return max;
}



