//#253. Meeting Rooms II
//Medium
//Method: two methods, always sorting
//Complexity: Time O(NlogN); Space O(N)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool compInt(Interval& a, Interval& b) {
    return a.start < b.start || a.start == b.start && a.end < b.end;
}

class Solution {
public:

    //Method 1: split each interval into start time and end time to form a helper array, then sort it
    //          then traverse this array.
    int minMeetingRooms(vector<Interval>& intervals) {
        vector< pair<int, int> > helper;
        for (Interval i: intervals) {
            helper.emplace_back(i.start, 1);
            helper.emplace_back(i.end, -1);
        }
        sort(helper.begin(), helper.end());
        int res = 0, cur = 0;
        for (auto p: helper) {
            cur += p.second;
            res = max(res, cur);
        }
        return res;
    }

    //Method 2: track the end time of the meeting of each room
    //          after sorting, the new meeting will never occupy the time gap between previous meetings
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compInt);
        vector<int> roomEnd;
        for (Interval& i: intervals) {
            bool isFit = false;
            for (int& e: roomEnd) {
                if (e <= i.start) {
                    e = i.end;
                    isFit = true;
                    break;
                }
            }
            if (!isFit) roomEnd.push_back(i.end);
        }
        return roomEnd.size();
    }
};