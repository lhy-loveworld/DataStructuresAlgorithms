//#348. Design Tic-Tac-Toe
//Medium
//Method: only need to record the progress of each row, column and diagnal
//Complexity: time O(N). space O(N)

class TicTacToe {
public:
    vector<vector<int> > win_progress;
    int N;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        win_progress = vector<vector<int> > (2, vector<int> (2 * n + 2, n));
        N = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        win_progress[player - 1][row]--;
        if (!win_progress[player - 1][row]) return player;
        win_progress[player - 1][N + col]--;
        if (!win_progress[player - 1][N + col]) return player;
        if (row == col) {
            win_progress[player - 1][2 * N]--;
            if (!win_progress[player - 1][2 * N]) return player;
        }
        if (row + col == N - 1) {
            win_progress[player - 1][2 * N + 1]--;
            if (!win_progress[player - 1][2 * N + 1]) return player;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */