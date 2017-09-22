//#234 Palindrome Linked List
//Easy
//Method: Two methods
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
	//Method 1: first find the middle node, and then reverse the second half, and compare it with the first half.
	//Could be further optimized by reversing the first half while finding the middle node/
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        ListNode* p1 = head, *p2 = slow->next;
        while (p1 != slow) {
            if (!p2 || p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p2) return (p1->val == p2->val);
        return true;
    }
    
    ListNode* reverse(ListNode* nd) {
        ListNode* res = NULL;
        ListNode* tmp;
        while (nd) {
            tmp = nd;
            nd = nd->next;
            tmp->next = res;
            res = tmp;
        }
        return res;
    }

    //Method 2: Recursively compare from the head and tail
    ListNode *comp;
    bool isPalindrome(ListNode* head) {
        comp = head;
        return helper(head);
    }
    
    bool helper(ListNode* nd) {
        if (nd == NULL) return true;
        bool res = helper(nd->next) && (comp->val == nd->val);
        comp = comp->next;
        return res;
    }
};