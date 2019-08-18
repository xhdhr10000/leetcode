/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* allocNode() {
    struct TreeNode *ret = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    ret->val = 0;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}

int sum = 0;

void traverse(struct TreeNode *n, struct TreeNode *ret) {
    if (n->right) {
        ret->right = allocNode();
        traverse(n->right, ret->right);
    }
    sum += n->val;
    ret->val = sum;
    if (n->left) {
        ret->left = allocNode();
        traverse(n->left, ret->left);
    }
}

struct TreeNode* bstToGst(struct TreeNode* root){
    struct TreeNode *ret = allocNode();
    sum = 0;
    traverse(root, ret);
    return ret;
}
