/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */
char* serialize(struct TreeNode* root) {
    int size = 256;
    struct TreeNode **queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*size);
    int head = -1, rear = 0, null = 0;
    char *ans;
    
    /* Construct queue from tree */
    queue[rear] = root;
    if (!root) null++;
    while (head < rear) {
        head++;
        if (!queue[head]) continue;
        if (rear+2 >= size) {
            size *= 2;
            queue = (struct TreeNode**)realloc(queue, sizeof(struct TreeNode*)*size);
        }
        queue[++rear] = queue[head]->left;
        if (!queue[rear]) null++;
        queue[++rear] = queue[head]->right;
        if (!queue[rear]) null++;
    }
    
    /* Print queue to string */
    ans = (char*)malloc(sizeof(char)*(null*5 + (rear+1-null)*11 + 3));
    sprintf(ans, "[");
    for (int i=0; i<=rear; i++) {
        if (queue[i])
            sprintf(&ans[strlen(ans)], "%d,", queue[i]->val);
        else
            sprintf(&ans[strlen(ans)], "null,");
    }
    sprintf(&ans[strlen(ans)-1], "]");
    
    //printf("%s\n", ans);
    free(queue);
    return ans;
}

/** Decodes your encoded data to tree. */
struct TreeNode* deserialize(char* data) {
    if (data[0] != '[' || data[strlen(data)-1] != ']') return NULL;
    data++;
    data[strlen(data)-1] = 0;
    
    /* Construct queue */
    int size = 256;
    struct TreeNode **queue = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*size);
    int count = 0;
    for (char *s = strtok(data, ","); s; s = strtok(NULL, ",")) {
        if (count >= size) {
            size *= 2;
            queue = (struct TreeNode**)realloc(queue, sizeof(struct TreeNode*)*size);
        }
        if (!strcmp(s, "null")) {
            queue[count++] = NULL;
        } else {
            queue[count] = (struct TreeNode*)malloc(sizeof(struct TreeNode));
            queue[count]->val = atoi(s);
            queue[count]->left = queue[count]->right = NULL;
            count++;
        }
    }
    if (!count || !queue[0]) {
        free(queue);
        return NULL;
    }
    
    /* Construct tree from queue */
    struct TreeNode *root = queue[0];
    int head = -1, rear = 0;
    while (head < rear) {
        head++;
        if (!queue[head]) continue;
        queue[head]->left = queue[++rear];
        queue[head]->right = queue[++rear];
    }
    free(queue);
    return root;
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);
