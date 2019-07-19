// Author: xhdhr10000
// Date: 2019-07-17
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int lenA = 0, lenB = 0;
    struct ListNode *a = headA, *b = headB;
    
    while (a) { lenA++; a = a->next; }
    while (b) { lenB++; b = b->next; }
    a = headA; b = headB;
    if (lenA > lenB) {
        for (int i=0; i<lenA-lenB; i++) a = a->next;
    } else {
        for (int i=0; i<lenB-lenA; i++) b = b->next;
    }
    while (a && b && a != b) { a = a->next; b = b->next; }
    if (a && b && a == b) return a;
    return NULL;
}
