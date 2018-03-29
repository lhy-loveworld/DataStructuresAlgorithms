//#127. Word Ladder
//Medium
//Method: BFS, two-end BFS
//Complexity: Time O(N * Len); Space O(N)

class Solution {
public:
    //Method 1: regular BFS. Use a queue to store current level of neighbors, and iterate each position of each string to check if it exists in
    //          the dictionary, if it is in and = endword, return;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty()) return 0;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<string> BFS;
        BFS.push(beginWord);
        dict.erase(beginWord);
        int res = 2;
        while (!BFS.empty()) {
            int n = BFS.size();
            for (int i = 0; i < n; ++i) {
                string cur = BFS.front();
                BFS.pop();
                for (int j = 0; j < cur.size(); ++j) {
                    for (int k = 0; k < 26; ++k) {
                        cur[j]++;
                        if (cur[j] > 'z') cur[j] -= 26;
                        if (dict.count(cur)) {
                            if (cur == endWord)
                                return res;
                            BFS.push(cur);
                            dict.erase(cur);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }
    //Method 2: 2-end BFS, use 2 dictionary to store current level of neighbors from begin and end reletively, do BFS search from the smaller one of them,
    //          first check if each transform exists at the current end set, if it does, return, then check if exists in the complete dictionary
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.empty()) return 0;
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        unordered_set<string> head, end, *phead, *pend;
        head.insert(beginWord);
        dict.erase(beginWord);
        end.insert(endWord);
        int res = 2;
        while (!head.empty() && !end.empty()) {
            unordered_set<string> tmp;
            if (head.size() > end.size()) {
                phead = &end;
                pend = &head;
            } else {
                phead = &head;
                pend = &end;
            }
            for (unordered_set<string>::iterator it = phead->begin(); it != phead->end(); ++it) {
                string str = *it;
                for (int i = 0; i < str.size(); ++i) {
                    for (int j = 0; j < 26; ++j) {
                        str[i]++;
                        if (str[i] > 'z') str[i] -= 26;
                        if (pend->count(str))
                            return res;
                        if (dict.count(str)) {
                            tmp.insert(str);
                            dict.erase(str);
                        }
                    }
                }
            }
            *phead = tmp;
            res++;
        }
        return 0;
    }
};