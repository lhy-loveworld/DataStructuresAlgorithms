//#239. Sliding Window Maximum
//Hard
//Method: two methods
//Complexity: Time O(N)   O(Nlog(k)); Space O(N)  O(N)

class Solution {
public:
	//Method 1: Use a deque to store all the maxs. 
	//Because the window is moving in 1 direction, thus we can discard all the previous elements smaller than the current one
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;
        deque<int> dq;
        for (int i = 0; i < k; ++i) {
            while (!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
        }
        res.push_back(dq.front());
        for (int i = k; i < nums.size(); ++i) {
            while (!dq.empty() && dq.back() < nums[i])
                dq.pop_back();
            dq.push_back(nums[i]);
            if (nums[i - k] == dq.front())
                dq.pop_front();
            res.push_back(dq.front());
        }
        return res;
    }

    //Method 2: Use a binary heap(priority queue)
    struct mycomp {
        bool operator() (pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (nums.empty()) return res;
        priority_queue<pair<int, int>, vector<pair<int, int> >, mycomp> q;
        for (int i = 0; i < k; ++i) {
            q.push(make_pair(nums[i], i));
        }
        res.push_back(q.top().first);
        for (int i = k; i < nums.size(); ++i) {
            q.push(make_pair(nums[i], i));
            while (q.top().second < i - k + 1)
                q.pop();
            res.push_back(q.top().first);
        }
        return res;
    }
};