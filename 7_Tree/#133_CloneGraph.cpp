//#133. Clone Graph
//Medium
//Method: two methods, caution for the duplicate nodes and self-loops
//Complexity: time O(N)

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    //Method 1: dfs
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> M; //use an unordered_map to avoid duplicate nodes
    void dfs(UndirectedGraphNode *a, UndirectedGraphNode *b) {
        for (const auto& n: b->neighbors) {
            if (!M.count(n)) {
                M[n] = new UndirectedGraphNode (n->label);
                dfs(M[n], n);
            }
            a->neighbors.push_back(M[n]);
        }
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode *res = nullptr;
        if (!node) return res;
        res = new UndirectedGraphNode (node->label);
        M[node] = res;
        dfs(res, node);
        return res;
    }

    //Method 2: bfs
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        UndirectedGraphNode *res = nullptr;
        if (!node) return res;
        res = new UndirectedGraphNode (node->label);
        queue<UndirectedGraphNode *> Q;
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> M; // also use an unordered_map to avoid duplicate nodes
        Q.push(node);
        M[node] = res;
        while (!Q.empty()) {
            auto t = Q.front();
            Q.pop();
            for (const auto& n: t->neighbors) {
                if (!M.count(n)) {
                    M[n] = new UndirectedGraphNode (n->label);
                    Q.push(n);
                }
                M[t]->neighbors.push_back(M[n]);
            }
        }
        return res;
    }
};