// Author: xhdhr10000
// Date: 2019-05-16
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode *t = node->next;
    node->val = t->val;
    node->next = t->next;
    free(t);
}
