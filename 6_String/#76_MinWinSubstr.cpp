//#76. Minimum Window Substring
//Hard
//Method: two methods
//Complexity: Time O(N); Space O(N)

class Solution {
public:
    //Method 1: use queue and map, save space, and save time for the loop of the start point
    string minWindow(string s, string t) {
        string res;
        if (s.empty()) return s;
        unordered_map<char, pair<int, int> > mp;
        queue<int> q;
        for (int i = 0; i < t.size(); ++i) {
            if (mp.count(t[i]))
                mp[t[i]].first++;
            else
                mp[t[i]] = make_pair(1, 0);
        }
        int Size = 0;
        int start = 0, Min = INT_MAX;
        for (int i = 0; i < s.size(); ++i) {
            if (mp.count(s[i])) {
                if (mp[s[i]].second < mp[s[i]].first)
                    Size++;
                mp[s[i]].second++;
                q.push(i);
                while (Size == t.size()) {
                    if (Min > i - q.front() + 1) {
                        Min = i - q.front() + 1;
                        start = q.front();
                    }
                    if (mp[s[q.front()]].second-- == mp[s[q.front()]].first) {
                        Size--;
                    }
                    q.pop();
                }
            }
        }
        return (Min < INT_MAX) ? s.substr(start, Min) : res;
    }

    //Method 2: use 2 vectors, not suitable for non-ascii charactors
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        vector<int> t_map(128, 0);
        int count = 0;
        for (int i = 0; i < t.size(); ++i) {
            t_map[t[i]]++;
            count++;
        }
        vector<int> s_map(t_map);
        int start = 0, s_cur = 0, cur = 0, len = INT_MAX;
        while (cur < s.size()) {
            if (s_map[s[cur]] > 0 && t_map[s[cur]] > 0)
                count--;
            s_map[s[cur]]--;
            while (count == 0 && s_cur <= cur) {
                if (len > cur - s_cur + 1) {
                    start = s_cur;
                    len = cur - s_cur + 1;
                }
                if (s_map[s[s_cur]] == 0 && t_map[s[cur]] > 0)
                    count++;
                s_map[s[s_cur]]++;
                s_cur++;
            }
            cur++;
        }
        return (len == INT_MAX) ? "" : s.substr(start, len);
    }
};