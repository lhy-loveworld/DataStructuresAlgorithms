//#237 Delete Node
//Easy
//https://leetcode.com/problems/delete-node-in-a-linked-list/description/
//Arthor: lhy-loveworld
//Method: Copy the next node and delete.
//Complexity: Time O(N); Space O(N)

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
    void deleteNode(ListNode* node) {
        ListNode* tmp = node->next;
        *node = *tmp;
        delete tmp;
    }
};