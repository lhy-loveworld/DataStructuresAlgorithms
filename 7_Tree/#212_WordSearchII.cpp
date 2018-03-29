//#212. Word Search II
//Hard
//Method: Use of DFS and trie
//        Store all the words in the trie and use DFS search the matrix
//Complexity: Time O(N^3); Space O(length of words)

class Solution {
    struct Node {
        int pos;
        vector<Node*> children;
        Node() {
            pos = -1;
            children = vector<Node*> (26, NULL);
        }
    };
    Node *root;
public:
    void Build_Trie(vector<string>& words) {
        root = new Node;
        for (int i = 0; i < words.size(); ++i) {
            Node* cur = root;
            for (int j = 0; j < words[i].size(); ++j) {
                if (!cur->children[words[i][j] - 'a'])
                    cur->children[words[i][j] - 'a'] = new Node;
                cur = cur->children[words[i][j] - 'a'];
            }
            cur->pos = i;
        }
    }
    void SubSearch(int i, int j, vector<vector<char> >& board, vector<string>& res, Node* cur, vector<string>& words) {
        if (board[i][j] == ' ') return;
        if (cur->children[board[i][j] - 'a']) {
            cur = cur->children[board[i][j] - 'a'];
            if (cur->pos >= 0) {
                res.push_back(words[cur->pos]);
                cur->pos = -1;
            }
            char tmp = board[i][j];
            board[i][j] = ' ';
            if (i > 0)
                SubSearch(i - 1, j, board, res, cur, words);
            if (j > 0)
                SubSearch(i, j - 1, board, res, cur, words);
            if (i < board.size() - 1)
                SubSearch(i + 1, j, board, res, cur, words);
            if (j < board[0].size() - 1)
                SubSearch(i, j + 1, board, res, cur, words);
            board[i][j] = tmp;
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        if (board.empty() || board[0].empty() || words.empty()) return res;
        Build_Trie(words);
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                SubSearch(i, j, board, res, root, words);
            }
        }
        return res;
    }
};