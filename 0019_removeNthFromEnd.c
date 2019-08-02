// Author: xhdhr10000
// Date: 2019-07-23
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *t = head;
    for (int i=0; i<n; i++) p = p->next;
    if (!p) {
        /* Remove head */
        return head->next;
    }
    while (p->next) {
        p = p->next;
        t = t->next;
    }
    t->next = t->next->next;
    return head;
}
