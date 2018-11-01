//#340. Longest Substring with At Most K Distinct Characters
//Hard
//Method: list, map
//Complexity: time O(N). space O(N)

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        list<char> curCharsList;
        unordered_map<char, pair<int, list<char>::iterator> > curCharsMap;
        int curLen = 0, maxLen = 0;
        int curBegin = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto it = curCharsMap.find(s[i]);
            if (it == curCharsMap.end()) {
                curCharsList.push_back(s[i]);
                auto lastIt = curCharsList.end();
                --lastIt;
                curCharsMap[s[i]] = make_pair(i, lastIt);
                if (curCharsList.size() > k) {
                    curBegin = curCharsMap[curCharsList.front()].first + 1;
                    curCharsMap.erase(curCharsList.front());
                    curCharsList.pop_front();
                }
            } else {
                curCharsList.erase((it->second).second);
                curCharsList.push_back(s[i]);
                (it->second).first = i;
                auto lastIt = curCharsList.end();
                --lastIt;
                (it->second).second = lastIt;
            }
            curLen = i - curBegin + 1;
            if (curLen > maxLen) maxLen = curLen;
        }
        return maxLen;
    }
};