// Author: xhdhr10000
// Date: 2019-05-16
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* reverse(struct ListNode *node, struct ListNode *prev) {
    struct ListNode *ret = node;
    if (node->next) ret = reverse(node->next, node);
    node->next = prev;
    return ret;
}

struct ListNode* reverseList(struct ListNode* head){
    if (!head) return NULL;
    return reverse(head, NULL);
    
    struct ListNode *node = head, *next = head->next, *prev = NULL;
    while (next) {
        node->next = prev;
        prev = node;
        node = next;
        next = node->next;
    }
    node->next = prev;
    return node;
}



