//#57. Insert Interval
//Hard
//Method: usage of upper_bound and lower bound
//        upper_bound: will advance if {!(val < *it)} {*it <= val} {!comp(val, *it)}
//                      thus the bound must not equal to val
//        lower_bound: will advance if {*it < val} {comp(*it, val)} {comp(*it, val)}
//                      thus the bound might equal to val
//          advance() is O(1) for random-access-iterator, O(N) for non-random access iterator.
//          therefore it's actually slower used with non-random access iterator
//Complexity: time O(N). space O(N)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool operator<(const Interval& a, const Interval& b) {
    return a.end < b.start;
}
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        auto it = lower_bound(intervals.begin(), intervals.end(), newInterval);
        vector<Interval> res(intervals.begin(), it);
        if (it == intervals.end() || it->start > newInterval.end) {
            res.push_back(newInterval);
            res.insert(res.end(), it, intervals.end());
        } else {
            res.emplace_back(min(it->start, newInterval.start), max(it->end, newInterval.end));
            it++;
            while (it != intervals.end()) {
                if (it->start > res.back().end) {
                    res.insert(res.end(), it, intervals.end());
                    break;
                }
                res.back().end = max(res.back().end, it->end);
                it++;
            }
        }
        return res;
    }
};