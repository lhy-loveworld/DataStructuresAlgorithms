//#287. Find the Duplicate Number
//Medium
//Method: O(1) memory, nums readonly, complexity not exceed O(N^2)
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0, slow = 0;
        do {
            fast = nums[nums[fast]];
            slow = nums[slow];
        } while (fast != slow);
        fast = 0;
        while (fast != slow) {
            fast = nums[fast];
            slow = nums[slow];
        }
        return slow;
    }
};

//It's actually a directed graph. Nodes are from 0 to N.
//Every nodes' out-degree is 1, only 1 to N has in-degree.
//Thus 0 must have no in-degree. Some nodes from 1 to N may not have in-degree either.
//We need to find out the one with multiple indegree.
//The whole graph is combined with one path starts from 0 and (0, 1, 2...) paths and (1, 2,...) circles.
//All the paths' ends must at the same point 'x'. And meet only 1 circle at the same point 'x'.
//For the path from 0 and that circle.
//x: length from 0 to the meeting point
//a: length from the meeting point to some point within the circle, and the fast pointer meets the slow pointer there.
//n: some rounds
//c: length of the circle

//x + a = n * c  length of the slow pointer walks.
//x = n * c - a   they will meet at the entry of the circle