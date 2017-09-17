//#160 Intersection of Two Linked Lists
//Easy
//Method: Require time O(N) and Space O(1) and cannot modify the lists, the only way is to loop.
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *tmp1 = headA, *tmp2 = headB;
        while (tmp1 != tmp2) {
            tmp1 = tmp1 ? tmp1->next : headA;
            tmp2 = tmp2 ? tmp2->next : headB;
        }
        return tmp1;
    }
};