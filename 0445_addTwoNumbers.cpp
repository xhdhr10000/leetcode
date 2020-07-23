// Author: xhdhr10000
// Date: 2020-04-14
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<ListNode*> stack;
        int c1 = 0, c2 = 0;

        ListNode *l = l1;
        while (l) { c1++; l = l->next; }
        l = l2;
        while (l) { c2++; l = l->next; }

        ListNode *ans = new ListNode(0), *cur;
        l = ans;
        stack.push_back(ans);
        while (c1 > c2) {
            cur = new ListNode(l1->val);
            l->next = cur;
            l = cur;
            l1 = l1->next;
            c1--;

            if (cur->val != 9) stack.clear();
            stack.push_back(cur);
        }
        while (c2 > c1) {
            cur = new ListNode(l2->val);
            l->next = cur;
            l = cur;
            l2 = l2->next;
            c2--;

            if (cur->val != 9) stack.clear();
            stack.push_back(cur);
        }

        while (c1 > 0) {
            cur = new ListNode(l1->val + l2->val);
            l->next = cur;
            l = cur;
            l1 = l1->next;
            l2 = l2->next;
            c1--;

            if (cur->val >= 10) {
                cur->val -= 10;
                stack.back()->val++;
                while (!stack.empty() && stack.back()->val >= 10) {
                    stack.back()->val -= 10;
                    stack.pop_back();
                    stack.back()->val++;
                }
            }
            if (cur->val != 9) stack.clear();
            stack.push_back(cur);
        }

        if (!ans->val) {
            l = ans;
            ans = ans->next;
            delete l;
        }
        return ans;
    }
};
