//#23 Merge k Sorted Lists
//Hard
//Method: Heap or divide and conqure
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
    //Method 1: heap priority queue
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct comparator {
            bool operator () (ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };
        
        priority_queue<ListNode*, vector<ListNode*>, comparator> q;
        for (int i = 0; i < lists.size(); ++i) {
            if (lists[i])
                q.push(lists[i]);
        }
        ListNode* head = new ListNode (0);
        ListNode* end = head;
        while (!q.empty()) {
            end->next = q.top();
            end = end->next;
            q.pop();
            if (end->next)
                q.push(end->next);
        }
        return head->next;
    }

    //Method 2: divide and conqure. Merge sort
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head, *p, *p1, *p2;
        if (l1->val < l2->val) {
            head = l1;
            p1 = l1->next;
            p2 = l2;
        } else {
            head = l2;
            p1 = l1;
            p2 = l2->next;
        }
        p = head;
        while (p1 && p2) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = (p1) ? p1 : p2;
        return head;
    }
    
    ListNode* helper(vector<ListNode*>& lists, int low, int high) {
        if (low == high)
            return lists[low];
        return merge2Lists(helper(lists, low, (high + low) / 2), helper(lists, (high + low) / 2 + 1, high));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;
        return helper(lists, 0, lists.size() - 1);
    }
};