// Author: xhdhr10000
// Date: 2019-05-04
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){
    int len = 0;
    struct ListNode *p = root;
    while (p) {
        len++;
        p = p->next;
    }
    int count = len / k, first = len % k;
    struct ListNode **ret = (struct ListNode**)malloc(sizeof(struct ListNode*)*k);
    p = root;
    for (int i=0; i<k; i++) {
        struct ListNode *last = p;
        ret[i] = p;
        if (p) p = p->next;
        for (int j=1; j<count+(i<first?1:0); j++) {
            last = p;
            if (p) p = p->next;
        }
        if (last) last->next = NULL;
    }
    *returnSize = k;
    return ret;
}



