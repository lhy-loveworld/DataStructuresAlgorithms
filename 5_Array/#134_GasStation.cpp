//#134. Gas Station
//Medium
//Method: only need 1 run, when the current sum is below 0, we can start from the next point
//Complexity: time O(N). space O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start = 0, n = gas.size(), tankLv = 0;
        while (1) {
            int cur = start, i = 0, tankLv = 0;
            for (; i < n; ++i, ++cur) {
                if (cur >= n) cur -=n;
                tankLv += gas[cur] - cost[cur];
                if (tankLv < 0) break;
            }
            if (i == n) return start;
            int newStart = (cur + 1) % n;
            if (newStart <= start) return -1;
            start = newStart;
        }
    }
};