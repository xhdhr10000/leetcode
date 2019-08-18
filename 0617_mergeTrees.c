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
typedef struct TreeNode TN;

void merge(TN *t, TN *t1, TN *t2) {
    if (!t1 && !t2) return;
    t->val = t1 && t2 ? t1->val+t2->val : (t1 ? t1->val : t2->val);
    if (t1 && t1->left || t2 && t2->left) {
        t->left = (TN*)malloc(sizeof(TN));
        merge(t->left, t1 ? t1->left : NULL, t2 ? t2->left : NULL);
    } else t->left = NULL;
    if (t1 && t1->right || t2 && t2->right) {
        t->right = (TN*)malloc(sizeof(TN));
        merge(t->right, t1 ? t1->right : NULL, t2 ? t2->right : NULL);
    } else t->right = NULL;
}

struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2){
    if (!t1 && !t2) return NULL;
    TN *root = (TN*)malloc(sizeof(TN));
    merge(root, t1, t2);
    return root;
}
