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

void traverse(struct TreeNode *n, int **ret, int *size, int *count) {
    if (!n) return;
    if (n->left) traverse(n->left, ret, size, count);
    if (*count >= *size) {
        *size *= 2;
        *ret = (int*)realloc(*ret, sizeof(int)*(*size));
    }
    (*ret)[(*count)++] = n->val;
    if (n->right) traverse(n->right, ret, size, count);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int size = 256;
    int *ret = (int*)malloc(sizeof(int)*size);
    *returnSize = 0;
    traverse(root, &ret, &size, returnSize);
    return ret;
}
