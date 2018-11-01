//#289. Game of Life
//Medium 
//Method: 
//Complexity: Time O(N); Space O(1)

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty()) return;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                int lives = 0;
                if (i > 0) {
                    if (board[i - 1][j] == 1 || board[i - 1][j] == 3) lives++;
                    if (j > 0 && (board[i - 1][j - 1] == 1 || board[i - 1][j - 1] == 3)) lives++;
                    if (j < board[0].size() - 1 && (board[i - 1][j + 1] == 1 || board[i - 1][j + 1] == 3)) lives++;
                }
                if (j > 0 && (board[i][j - 1] == 1 || board[i][j - 1] == 3)) lives++;
                if (j < board[0].size() - 1 && board[i][j + 1] == 1) lives++;
               if (i < board.size() - 1) {
                    if (board[i + 1][j] == 1) lives++;
                    if (j > 0 && board[i + 1][j - 1] == 1) lives++;
                    if (j < board[0].size() - 1 && board[i + 1][j + 1] == 1) lives++;
                } 
                if (board[i][j] == 0) {
                    if (lives == 3) board[i][j] = 2;
                } else
                    if (lives < 2 || lives > 3) board[i][j] = 3;
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 2) board[i][j] = 1;
                else if (board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};