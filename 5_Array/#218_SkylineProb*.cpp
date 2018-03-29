//#218. The Skyline Problem
//Hard
//Method: priority queue, store the height and end of each building
//Complexity: Time O(N)   O(Nlog(k)); Space O(N)  O(N)

class Solution {
public:
    //My own solution
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int> > res;
        if (buildings.empty()) return res;
        priority_queue<pair<int, int> > pq;
        int i = 0;
        int beg = buildings.front()[0];
        while (i < buildings.size()) {
            do {
                pq.push(make_pair(buildings[i][2], buildings[i][1]));
                i++;
            } while (i < buildings.size() && buildings[i][0] == buildings[i - 1][0]);
            if (i < buildings.size())
                while (beg < buildings[i][0]) {
                    while (!pq.empty() && pq.top().second <= beg)
                        pq.pop();
                    int tmp = 0;
                    if (!pq.empty())
                        tmp = pq.top().first;
                    if (res.empty() || res.back().second != tmp) {
                        res.push_back(make_pair(beg, tmp));
                    }
                    if (pq.empty() || pq.top().second > buildings[i][0])
                        beg = buildings[i][0];
                    else
                        beg = pq.top().second;
                }
            else {
                while (!pq.empty()) {
                    while (!pq.empty() && pq.top().second <= beg)
                        pq.pop();
                    if (!pq.empty()) {
                        if (res.empty() || res.back().second != pq.top().first)
                            res.push_back(make_pair(beg, pq.top().first));
                        beg = pq.top().second;
                    }
                }
                if (res.empty() || res.back().second != 0)
                    res.push_back(make_pair(beg, 0));
            }
        }
        return res;
    }

    //the answer's solution
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> res;
        int cur=0, cur_X, cur_H =-1,  len = buildings.size();
        priority_queue< pair<int, int>> liveBlg; // first: height, second, end time
        while(cur<len || !liveBlg.empty())
        { // if either some new building is not processed or live building queue is not empty
            cur_X = liveBlg.empty()? buildings[cur][0]:liveBlg.top().second; // next timing point to process

            if(cur>=len || buildings[cur][0] > cur_X)
            { //first check if the current tallest building will end before the next timing point
                  // pop up the processed buildings, i.e. those  have height no larger than cur_H and end before the top one
                while(!liveBlg.empty() && ( liveBlg.top().second <= cur_X) ) liveBlg.pop();
            }
            else
            { // if the next new building starts before the top one ends, process the new building in the vector
                cur_X = buildings[cur][0];
                while(cur<len && buildings[cur][0]== cur_X)  // go through all the new buildings that starts at the same point
                {  // just push them in the queue
                    liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
                    cur++;
                }
            }
            cur_H = liveBlg.empty()?0:liveBlg.top().first; // outut the top one
            if(res.empty() || (res.back().second != cur_H) ) res.push_back(make_pair(cur_X, cur_H));
        }
        return res;
    }
};
};