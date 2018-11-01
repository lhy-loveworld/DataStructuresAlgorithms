//#681. Next Closest Time
//Medium
//Method: two methods
//Complexity: 

class Solution {
public:
    //Method 1: BFS to find the next combination
    bool isValid(const string& s) {
        return s[0] < '3' && (s[0] < '2' || s[1] < '4') && s[2] < '6';
    }
    string nextClosestTime(string time) {
        set<char> Set{time[0], time[1], time[3], time[4]};
        string first;
        queue<string> Q;
        bool isRes = false;
        Q.push("");
        while (!Q.empty()) {
            string tmp = Q.front();
            Q.pop();
            if (tmp.size() == 4) {
                if (isValid(tmp)) {
                    tmp.insert(2, 1, ':');
                    if (first.empty()) first = tmp;
                    if (isRes) return tmp;
                    if (tmp == time) isRes = true;
                }
            } else {
                tmp.push_back(' ');
                for (const char& c: Set) {
                    tmp.back() = c;
                    
                    Q.push(tmp);
                }
            }
        }
        return first;
    }

    //Method 2: using a binary search tree, hard code to find next
    string nextClosestTime(string time) {
        set<char> Set{time[0], time[1], time[3], time[4]};
        auto it = Set.find(time[4]);
        it++;
        if (it != Set.end()) {
            time[4] = *it;
            return time;
        }
        time[4] = *(Set.begin());
        it = Set.find(time[3]);
        it++;
        if (it != Set.end() && *it < '6') {
            time[3] = *it;
            return time;
        }
        time[3] = *(Set.begin());
        it = Set.find(time[1]);
        it++;
        if (it != Set.end() && (*it < '4' || time[0] != '2')) {
            time[1] = *it;
            return time;
        }
        time[1] = *(Set.begin());
        it = Set.find(time[0]);
        it++;
        if (it != Set.end() && *it < '3') {
            time[0] = *it;
        } else {
            time[0] = *(Set.begin());
        }
        return time;
    }
};