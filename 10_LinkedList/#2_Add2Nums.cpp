//#2 Add Two Numbers
//Medium
//Method: Corner case
//Complexity: Time O(N); Space O(1)

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
        if (!l1 || !l2) return ((l1) ? l1 : l2);
        ListNode* t1 = l1, *t2 = l2;
        int co = 0;
        t1->val = (t1->val + t2->val + co) % 10;
        co = (t1->val < t2->val + co);
        while (t1->next && t2->next) {
            t1 = t1->next;
            t2 = t2->next;
            t1->val = (t1->val + t2->val + co) % 10;
            co = (t1->val < t2->val + co);
        }
        if (t2->next) t1->next = t2->next;
        while (co) {
            if (!t1->next)
                t1->next = new ListNode (co);
            else
                t1->next->val = (t1->next->val + co) % 10;
            t1 = t1->next;
            co = (t1->val == 0);
        }
        return l1;
    }
};