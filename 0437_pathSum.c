// Author: xhdhr10000
// Date: 2019-08-18
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void traverse(struct TreeNode *n, int **stack, int *p, int *size, int *ans, int k) {
    (*stack)[*p] = (*stack)[(*p)-1] + n->val;
    for (int i=0; i<*p; i++) if ((*stack)[*p]-(*stack)[i] == k) (*ans)++;
    (*p)++;
    if (*p >= *size) *stack = (int*)realloc(*stack, sizeof(int)*((*size) *= 2));
    if (n->left) traverse(n->left, stack, p, size, ans, k);
    if (n->right) traverse(n->right, stack, p, size, ans, k);
    (*p)--;
}

int pathSum(struct TreeNode* root, int sum){
    int size = 32;
    int *stack = (int*)malloc(sizeof(int)*size);
    int p = 1, ans = 0;
    stack[0] = 0;
    if (root) traverse(root, &stack, &p, &size, &ans, sum);
    free(stack);
    return ans;
}
