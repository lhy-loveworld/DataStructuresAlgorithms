//#79. Word Search
//Medium
//Method: DFS
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    bool SubSearch(vector<vector<char>>& board, int i, int j, string& word, int cur) {
        if (board[i][j] == word[cur]) {
            if (++cur == word.size()) return true;
            char tmp = ' ';
            swap(board[i][j], tmp);
            if (i > 0 && SubSearch(board, i - 1, j, word, cur)) return true;
            if (i + 1 < board.size() && SubSearch(board, i + 1, j, word, cur)) return true;
            if (j > 0 && SubSearch(board, i, j - 1, word, cur)) return true;
            if (j + 1 < board[0].size() && SubSearch(board, i, j + 1, word, cur)) return true;
            swap(board[i][j], tmp);
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (SubSearch(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }
};