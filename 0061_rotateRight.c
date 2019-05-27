// Author: xhdhr10000
// Date: 2019-05-27
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){
    int size = 0, count = 0;
    struct ListNode *p = head, *t;
    while (p && p->next) {
        size++;
        p = p->next;
    }
    if (p) {
        size++;
        p->next = head;
    }
    t = p;
    p = head;
    
    size = !size ? 0 : ((k-1)/size+1)*size - k;
    while (count < size) {
        t = p;
        p = p->next;
        count++;
    }
    if (t) t->next = NULL;
    return p;
}



