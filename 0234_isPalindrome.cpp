// Author: xhdhr10000
// Date: 2020-04-08
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        if (!head->next) return true;
        if (!head->next->next) return head->val == head->next->val;

        ListNode *slow = head, *fast = head, *last = NULL;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *rev = fast->next ? fast->next : fast;
        slow = slow->next;
        fast = slow->next;
        slow->next = NULL;
        while (fast) {
            last = slow;
            slow = fast;
            fast = fast->next;
            slow->next = last;
        }
        while (rev && head && rev->val == head->val) {
            cout << rev->val << " ";
            rev = rev->next;
            head = head->next;
        }
        return !rev;
    }
};
