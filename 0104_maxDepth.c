// Author: xhdhr10000
// Date: 2019-05-14
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(X,Y) ((X)>(Y)?(X):(Y))

typedef struct {
    struct TreeNode *t;
    int depth;
} Node;

int maxDepth(struct TreeNode* root){
    int size = 256;
    Node *q = (Node*)malloc(sizeof(Node)*size);
    int head = -1, tail = -1, max = 0;
    
    if (root) {
        tail++;
        q[tail].t = root;
        q[tail].depth = 1;
    }
    while (head != tail) {
        head++;
        max = MAX(max, q[head].depth);
        if (q[head].t->left) {
            if (tail >= size-1) {
                size *= 2;
                q = (Node*)realloc(q, sizeof(Node)*size);
            }
            tail++;
            q[tail].t = q[head].t->left;
            q[tail].depth = q[head].depth+1;
        }
        if (q[head].t->right) {
            if (tail >= size-1) {
                size *= 2;
                q = (Node*)realloc(q, sizeof(Node)*size);
            }
            tail++;
            q[tail].t = q[head].t->right;
            q[tail].depth = q[head].depth+1;
        }
    }
    free(q);
    return max;
}



