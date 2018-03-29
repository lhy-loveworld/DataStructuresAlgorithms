//#138. Copy List with Random Pointer
//Medium
//Method: two methods
//Complexity: Time O(N); Space O(N), O(1)

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    //Method 1: use one run, store the relationship between two lists in an unordered_map
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode *, RandomListNode *> mp;
        RandomListNode res(0);
        RandomListNode *cur = head, *tail = &res;
        while (cur) {
            auto it = mp.find(cur);
            if (it == mp.end()) {
                RandomListNode *tmp = new RandomListNode(cur->label);
                it = mp.insert(make_pair(cur, tmp)).first;
            }
            tail->next = it->second;
            tail = tail->next;
            if (cur->random && !tail->random) {
                it = mp.find(cur->random);
                if (it == mp.end()) {
                    RandomListNode *tmp = new RandomListNode(cur->random->label);
                    it = mp.insert(make_pair(cur->random, tmp)).first;
                }
                tail->random = it->second;
            }
            cur = cur->next;
        }
        return res.next;
    }

    //Method 2: use 3 runs, space complexity O(1)
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return head;
        RandomListNode *cur = head;
        //first run is to put a copy behind every node
        while (cur) {
            RandomListNode *tmp = new RandomListNode (cur->label);
            tmp->next = cur->next;
            cur->next = tmp;
            cur = tmp->next;
        }
        cur = head;
        //second run is to copy the random pointer of each node
        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        RandomListNode *res = head->next;
        cur = head;
        //third run is to separate these two lists
        while (cur) {
            RandomListNode *tmp = cur->next;
            cur->next = tmp->next;
            if (cur->next) tmp->next = cur->next->next;
            cur = cur->next;
        }
        return res;
    }
};