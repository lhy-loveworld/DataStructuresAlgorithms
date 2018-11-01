//#56. Merge Intervals
//Medium
//Method: sort it first
//Complexity: Time O(NlogN); Space O(1)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
static int x=[](){ std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
class Solution {
public:
    struct mycomp{
        bool operator()(Interval& a, Interval& b) {
            return a.start < b.start;
        }
    } myobj;
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), myobj);
        vector<Interval> res;
        for (Interval& i: intervals) {
            if (res.empty() || res.back().end < i.start) {
                res.push_back(i);
            } else {
                res.back().end = max(res.back().end, i.end);
            }
        }
        return res;
    }
};