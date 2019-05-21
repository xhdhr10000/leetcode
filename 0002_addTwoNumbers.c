// Author: xhdhr10000
// Date: 2019-05-20
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode inline *allocNode() {
    struct ListNode *ret = (struct ListNode*)malloc(sizeof(struct ListNode));
    ret->next = NULL;
    return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *ret = allocNode(), *p = ret;
    int inc = 0;
    while (l1 && l2) {
        p->next = allocNode();
        p = p->next;
        p->val = (l1->val + l2->val + inc) % 10;
        inc = (l1->val + l2->val + inc) / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    while (l1) {
        p->next = allocNode();
        p = p->next;
        p->val = (l1->val + inc) % 10;
        inc = (l1->val + inc) / 10;
        l1 = l1->next;
    }
    while (l2) {
        p->next = allocNode();
        p = p->next;
        p->val = (l2->val + inc) % 10;
        inc = (l2->val + inc) / 10;
        l2 = l2->next;
    }
    if (inc) {
        p->next = allocNode();
        p = p->next;
        p->val = inc;
    }
    
    return ret->next;
}



