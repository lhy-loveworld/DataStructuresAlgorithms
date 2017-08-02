//#371
//Easy
//Arthor: lhy-loveworld
//Method: The first part is the sum without carryovers. The second part is the carryovers.
//Complexity: Time ; Space O(1)

class Solution {
public:
    int getSum(int a, int b) {
    	return b==0? a:getSum(a^b, (a&b)<<1);
	}
};
