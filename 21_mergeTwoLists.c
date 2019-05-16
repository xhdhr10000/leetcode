// Author: xhdhr10000
// Date: 2019-05-15
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ret = NULL, *p = NULL;
    while (l1 && l2) {
        if (l1->val < l2->val) {
            if (!ret) {
                ret = l1;
                p = ret;
            } else {
                p->next = l1;
                p = p->next;
            }
            l1 = l1->next;
        } else {
            if (!ret) {
                ret = l2;
                p = ret;
            } else {
                p->next = l2;
                p = p->next;
            }
            l2 = l2->next;
        }
    }
    if (l1) {
        if (!ret) ret = l1;
        else p->next = l1;
    }
    if (l2) {
        if (!ret) ret = l2;
        else p->next = l2;
    }
    return ret;
}



