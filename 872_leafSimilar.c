// Author: xhdhr10000
// Date: 2019-05-06
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void dfs(struct TreeNode *n, int *seq, int *ps) {
    if (!n->left && !n->right) {
        seq[(*ps)++] = n->val;
    } else {
        if (n->left) dfs(n->left, seq, ps);
        if (n->right) dfs(n->right, seq, ps);
    }
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2){
    int seq1[100], ps1 = 0, seq2[100], ps2 = 0;
    dfs(root1, seq1, &ps1);
    dfs(root2, seq2, &ps2);
    if (ps1 != ps2) return false;
    for (int i=0; i<ps1; i++)
        if (seq1[i] != seq2[i]) return false;
    return true;
}



