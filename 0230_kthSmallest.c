// Author: xhdhr10000
// Date: 2019-05-27
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int find(struct TreeNode *root, int k, int *ans, bool *found) {
    if (*found) return 0;
    int left = root->left ? find(root->left, k, ans, found) : 0;
    if (left == k-1) {
        *ans = root->val;
        *found = true;
    }
    int right = root->right ? find(root->right, k - left - 1, ans, found) : 0;
    return left + right + 1;
}

int kthSmallest(struct TreeNode* root, int k){
    int ans;
    bool found = false;
    if (root) find(root, k, &ans, &found);
    return ans;
}



