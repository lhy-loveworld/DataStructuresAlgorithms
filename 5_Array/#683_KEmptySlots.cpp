//#683. K Empty Slots
//Hard
//Method: two methods
//Complexity: 

bool comparator(const int& i, const pair<int, int>& p) {
    return i < p.second;
}
class Solution {
public:
    //Method 1: use a list of intervals to record the valid intervals
    //time O(N^2) space O(N)
    int kEmptySlots(vector<int>& flowers, int k) {
        list<pair<int, int> > l {make_pair(0, flowers.size() + 1)};
        for (int i = 0; i < flowers.size(); ++i) {
            if (l.empty()) return -1;
            auto it = upper_bound(l.begin(), l.end(), flowers[i], comparator);
            if (it == l.end() || flowers[i] < it->first) continue;
            if (it->first + k + 1 == flowers[i]) {
                if (it->first != 0) return i + 1;
            }
            if (it->first + k + 1 < flowers[i]) l.insert(it, make_pair(it->first, flowers[i]));
            if (flowers[i] + k + 1 == it->second) {
                if (it->second != flowers.size() + 1) return i + 1;
            }
            if (flowers[i] + k + 1 < it->second) it->first = flowers[i];
            else l.erase(it);
        }
        return -1;
    }

    //Method 2: first convert the vector into a vector of time.  Then use a stack to find the consequent k+2 elements
    //time O(N) space O(N)
    int kEmptySlots(vector<int>& flowers, int k) {
        if (flowers.size() < k + 2) return -1;
        list<int> helper;
        vector<int> f(flowers.size());
        for (int i = 0; i < flowers.size(); ++i) {
            f[flowers[i] - 1] = i + 1;
        }
        int res = flowers.size() + 1;
        for (int i = 0; i < f.size(); ++i) {
            if (helper.empty()) {
                helper.push_front(i);
            } else {
                if (i - helper.front() > k) {
                    if (f[i] < f[helper.front()]) {
                        res = min(res, f[helper.front()]);
                        helper = list<int> {i};
                        continue;
                    } else {
                        helper.pop_front();
                        if (helper.empty() || f[i] < f[helper.front()]) {
                            res = min(res, f[i]);
                            helper = list<int> {i};
                            continue;
                        }
                    }
                }
                while (!helper.empty() && f[i] < f[helper.back()]) helper.pop_back();
                helper.push_back(i);
            }
        }
        return res > flowers.size() ? -1 : res;
    }
};