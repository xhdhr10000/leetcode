// Author: xhdhr10000
// Date: 2019-05-14
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* sortList(struct ListNode* head){
    struct ListNode *c = head, *l=NULL, *r=NULL, *pl=NULL, *pr=NULL;
    while (head && head->next) {
        head = head->next;
        if (head->val < c->val) {
            if (!l) {
                l = head;
                pl = l;
            } else {
                pl->next = head;
                pl = head;
            }
        } else {
            if (!r) {
                r = head;
                pr = r;
            } else {
                pr->next = head;
                pr = head;
            }
        }
    }
    if (pl) pl->next = NULL;
    if (pr) pr->next = NULL;
    if (l && l->next) l = sortList(l);
    if (r && r->next) r = sortList(r);
    pl = l;
    while (pl && pl->next) pl = pl->next;
    pr = r;
    while (pr && pr->next) pr = pr->next;
    
    if (!l) {
        l = c;
        pl = l;
    } else pl->next = c;
    if (c) c->next = r;
    return l;
}



