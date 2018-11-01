//#406. Queue Reconstruction by Height
//Medium
//Method: topolofical sort
//Complexity: Time O(N^2); Space O(N)

class Solution {
    struct myComp{
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a > b;
    }
    };
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        priority_queue<pair<int, int>, deque<pair<int, int> >, myComp> pQ;
        vector<pair<int, int> > res(people.size(), make_pair(-1, 0));
        for (auto i: people) pQ.push(i);
        while (!pQ.empty()) {
            int t = pQ.top().second;
            int pos = 0;
            while (t || res[pos].first != -1) {
                if (res[pos].first == -1 || res[pos].first == pQ.top().first) t--;
                pos++;
            }
            res[pos] = pQ.top();
            pQ.pop();
        }
        return res;
    }
};