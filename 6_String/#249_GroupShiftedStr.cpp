//#249. Group Shifted Strings
//Medium
//Method: unordered_map, use a feature string to represent each pattern
//Complexity: time O(NM). space O(MN)

class Solution {
public:
    string get_feature_string(const string& s) {
        string res;
        for (int i = 1; i < s.size(); ++i) {
            res.push_back('a' + (s[i] + 26 - s[i - 1]) % 26);
        }
        return res;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string> > res;
        unordered_map<string, vector<string> > featureStrToVector;
        for (const string& s: strings) {
            string featureStr = get_feature_string(s);
            auto it = featureStrToVector.find(featureStr);
            if (it == featureStrToVector.end()) {
                featureStrToVector[featureStr] = vector<string> {s};
            } else {
                (it->second).push_back(s);
            }
        }
        for (const auto& p: featureStrToVector) {
            res.push_back(p.second);
        }
        return res;
    }
};