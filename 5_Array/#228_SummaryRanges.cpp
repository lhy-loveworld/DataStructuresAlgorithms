//#228. Summary Ranges
//Medium
//Method: 
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        string curStr;
        int curNum;
        for (int i: nums) {
            if (curStr.empty() || i != curNum + 1) {
                if (!curStr.empty()) {
                    if (stoi(curStr) != curNum) curStr += ("->" + to_string(curNum));
                    res.push_back(curStr);  
                }
                curStr = to_string(i);
            }
            curNum = i;
        }
        if (!curStr.empty()) {
            if (stoi(curStr) != curNum) curStr += ("->" + to_string(curNum));
            res.push_back(curStr);
        }
        return res;
    }
};