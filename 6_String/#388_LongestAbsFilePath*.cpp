//#388. Longest Absolute File Path
//Medium
//Method: cautious for special characters, treat them just as other characters
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    int lengthLongestPath(string input) {
        bool isFile = false;
        int maxLen = 0;
        int curLen = 0;
        int nameLen = 0;
        int level = 0;
        stack<int> lenStack;
        for (int i = 0; i < input.size(); ++i) {
            switch (input[i]) {
                case '.':
                    isFile = true;
                    nameLen++;
                    break;
                case '\n':
                    while (lenStack.size() > level) {
                        curLen -= lenStack.top();
                        lenStack.pop();
                    }
                    if (level) nameLen++;
                    curLen += nameLen;
                    lenStack.push(nameLen);
                    if (isFile) maxLen = max(maxLen, curLen);
                    isFile = false;
                    nameLen = 0;
                    level = 0;
                    break;
                case '\t':
                    level++;
                    break;
                default:
                    nameLen++;
            }
            
        }
        while (lenStack.size() > level) {
            curLen -= lenStack.top();
            lenStack.pop();
        }
        if (level) nameLen++;
        curLen += nameLen;
        lenStack.push(nameLen);
        if (isFile) maxLen = max(maxLen, curLen);
        return maxLen;
    }
};