//#148. Sort List
//Medium
//Method: Merge sort. Divide and conqure
//Complexity: Time O(NlogN); Space O(1)

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
    ListNode* Merge(ListNode* a, ListNode* b) {
        ListNode res(0), *tail = &res;
        while (a || b) {
            if (!a || b && b->val < a->val) {
                tail->next = b;
                b = b->next;
            } else {
                tail->next = a;
                a = a->next;
            }
            tail = tail->next;
        }
        return res.next;
    }
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        ListNode* fast = head, *slow = head;
        while (fast->next && fast->next->next) { //caution about the corner case
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = sortList(slow->next); //corner case
        if (!fast) return head; //corner case
        slow->next = NULL;
        slow = sortList(head);
        return Merge(fast, slow);
    }
};