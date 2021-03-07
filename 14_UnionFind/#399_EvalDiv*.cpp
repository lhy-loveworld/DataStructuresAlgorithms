//#399. Evaluate Division
//Medium
//Method:
//Complexity: 

class Solution {
    //Method 1: Build a graph to store the relationship and use DFS to find path between two strings
    //Complexity: time build O(M) search O(QM). space O(M + N)
public:
    unordered_map<string, unordered_map<string, double> > helper;
    unordered_map<string, bool> isVisited;
    double dfs(const string& s1, const string& s2) {
        
        auto it = isVisited.find(s1);
        if (it == isVisited.end()) return -1.0;
        
        if (helper[s1].count(s2)) return helper[s1][s2];
        it->second = true;
        double res = -1.0;
        for (auto it: helper[s1]) {
            if (isVisited[it.first]) continue;
            res = dfs(it.first, s2);
            if (res > 0) return res * it.second;
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        for (int i = 0; i < equations.size(); ++i) {
            auto it = helper.find(equations[i].first);
            if (it != helper.end())
                (it->second)[equations[i].second] = values[i];
            else {
                helper[equations[i].first] = unordered_map<string, double> {make_pair(equations[i].second, values[i]), make_pair(equations[i].first, 1.0)};
                isVisited[equations[i].first] = false;
            }
            it = helper.find(equations[i].second);
            if (it != helper.end())
                (it->second)[equations[i].first] = 1.0 / values[i];
            else {
                helper[equations[i].second] = unordered_map<string, double> {make_pair(equations[i].first, 1.0 / values[i]), make_pair(equations[i].second, 1.0)};
                isVisited[equations[i].second] = false;
            }
        }
        vector<double> res(queries.size(), -1.0);
        for (int i = 0; i < queries.size(); ++i) {
            res[i] = dfs(queries[i].first, queries[i].second);
            for (auto& it: isVisited) it.second = false;
        }
        return res;
    }

    //Method 2: union set, only need to store one entry for each string, and only need to traverse one path when finding.
    //Complexity: time build O(MlogN) search O(QlogN) space O(N)
    unordered_map<string, pair<string, double> > unionSet;
public:
    pair<string, double> findSet(string s) {
        if (!unionSet.count(s)) return make_pair(s, -1.0);
        double m = 1.0;
        while (s != unionSet[s].first) {
            m *= unionSet[s].second;
            s = unionSet[s].first;
        }
        return make_pair(unionSet[s].first, m);
    }
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        for (const auto& p: equations) {
            unionSet[p.first] = make_pair(p.first, 1.0);
            unionSet[p.second] = make_pair(p.second, 1.0);
        }
        for (int i = 0; i < equations.size(); ++i) {
            auto p = equations[i];
            auto p1 = findSet(p.first);
            auto p2 = findSet(p.second);
            if (p1.first == p2.first) continue;
            unionSet[p.second] = make_pair(p.first, values[i] / p2.second);
        }
        vector<double> res;
        for (const auto& p: queries) {
            auto p1 = findSet(p.first);
            auto p2 = findSet(p.second);
            if (p1.first != p2.first || p1.second == -1) res.push_back(-1.0);
            else {
                res.push_back(p2.second / p1.second);
            }
        }
        return res;
    }
};