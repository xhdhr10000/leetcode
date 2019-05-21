// Author: xhdhr10000
// Date: 2019-05-14
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    while (head) {
        if (head->val == (int)head->next) return true;
        head->val = (int)head->next;
        head = head->next;
    }
    return false;
}
