//#490. The Maze
//Medium
//Method: dfs
//Complexity: time O(N^2). space O(N)

class Solution {
public:
    bool dfs(vector<vector<int>>& maze, int s_row, int s_col, vector<int>& destination) {
        maze[s_row][s_col] = 2;
        int i = s_row;
        while (i != 0 && maze[i - 1][s_col] != 1) i--;
        if (s_col == destination[1] && i == destination[0]) return true;
        if (maze[i][s_col] == 0 && dfs(maze, i, s_col, destination)) return true;
        i = s_row;
        while (i != maze.size() - 1 && maze[i + 1][s_col] != 1) i++;
        if (s_col == destination[1] && i == destination[0]) return true;
        if (maze[i][s_col] == 0 && dfs(maze, i, s_col, destination)) return true;
        i = s_col;
        while (i != maze[0].size() - 1 && maze[s_row][i + 1] != 1) i++;
        if (s_row == destination[0] && i == destination[1]) return true;
        if (maze[s_row][i] == 0 && dfs(maze, s_row, i, destination)) return true;
        i = s_col;
        while (i != 0 && maze[s_row][i - 1] != 1) i--;
        if (s_row == destination[0] && i == destination[1]) return true;
        if (maze[s_row][i] == 0 && dfs(maze, s_row, i, destination)) return true;
        return false;
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return dfs(maze, start[0], start[1], destination);
    }
};