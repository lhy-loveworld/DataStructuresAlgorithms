//#269. Alien Dictionary
//Hard
//Method: topological sort, DFS
//Complexity: Time O(N to N^2); Space O(N)

class Solution {
public:
    void topo(int i, vector<int> &aprc, vector<unordered_set<char> > &adj, string &res, bool &Stop) {
        aprc[i] = 0;
        for (auto ch: adj[i]) {
            if (aprc[ch - 'a'] == 0) {
                Stop = true;
                res = "";
                return;
            }
            if (aprc[ch - 'a'] > 0)
                topo(ch - 'a', aprc, adj, res, Stop); 
        }
        if (Stop) return;
        aprc[i] = -1;
        char ch = 'a' + i;
        res = ch + res;
    }
    string alienOrder(vector<string>& words) {
        if (words.empty()) return "";
        vector<unordered_set<char> > adj(26);
        vector<int> aprc(26);
        //Build the adjacent vector, only need to consider each adjacent word
        for (int i = 0; i < words.size() - 1; ++i) {
            string &a = words[i], &b = words[i + 1];
            int j = 0;
            while (a[j] == b[j] && j < min(a.size(), b.size())) {
                aprc[a[j] - 'a'] = 1;
                j++;
            }
            if (j < min(a.size(), b.size())) {
                adj[a[j] - 'a'].insert(b[j]);
            }
            while (j < a.size()) {
                aprc[a[j] - 'a'] = 1;
                j++;
            }
        }
        for (char ch: words.back())
            aprc[ch - 'a'] = 1;
        string res;
        bool Stop = false;

        //DFS, needs 3 states for each character, it cannot be searched twice within one single recursion, but can in different recursions.
        //If we use BFS, we need to also record the in-degree of each vertice.
        for (int i = 0; i < 26; ++i) {
            if (Stop)
                break;
            if (aprc[i] > 0) {
                topo(i, aprc, adj, res, Stop);
            }
        }
        return res;
    }
};