//#206
//Easy
//Arthor: lhy-loveworld
//Method: Iteratively and Recursively
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
	//Iteratively
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *res = head, *next = head->next;
        head->next = NULL;
        ListNode *prev;
        while (next != NULL) {
            prev = res;
            res = next;
            next = next->next;
            res->next = prev;
        }
        return res;
    }
    //Recursively
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* res = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return res;
    }
};