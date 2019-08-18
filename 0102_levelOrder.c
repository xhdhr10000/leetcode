// Author: xhdhr10000
// Date: 2019-08-16
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    struct TreeNode *n;
    int level;
} Entry;

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int sq = 256, sr = 32, sd = 16;
    int **ret = (int**)malloc(sizeof(int*)*sr);
    int *d = (int*)malloc(sizeof(int)*sd);
    Entry *q = (Entry*)malloc(sizeof(Entry)*sq);
    int head = 0, rear = 1, level = 0, pd = 0;
    
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int)*sr);
    if (!root) { free(q); free(d); return ret; }
    
    q[0].n = root;
    q[0].level = 0;
    while (head < rear) {
        if (q[head].level != level) {
            level = q[head].level;
            ret[*returnSize] = d;
            (*returnColumnSizes)[*returnSize] = pd;
            (*returnSize)++;
            if (*returnSize >= sr) {
                sr *= 2;
                ret = (int**)realloc(ret, sizeof(int*)*sr);
                *returnColumnSizes = (int*)realloc(*returnColumnSizes, sizeof(int)*sr);
            }
            d = (int*)malloc(sizeof(int)*sd);
            pd = 0;
        }
        if (rear + 2 >= sq)  q = (Entry*)realloc(q, sizeof(Entry)*(sq*=2));
        if (q[head].n->left) {
            q[rear].n = q[head].n->left;
            q[rear].level = q[head].level + 1;
            rear++;
        }
        if (q[head].n->right) {
            q[rear].n = q[head].n->right;
            q[rear].level = q[head].level + 1;
            rear++;
        }
        if (pd >= sd) d = (int*)realloc(d, sizeof(int)*(sd *= 2));
        d[pd++] = q[head].n->val;
        head++;
    }
    ret[*returnSize] = d;
    (*returnColumnSizes)[*returnSize] = pd;
    (*returnSize)++;
    free(q);
    return ret;
}
