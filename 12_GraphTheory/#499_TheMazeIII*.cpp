//#499. The Maze III
//Hard
//Method: dijkstra algorithm with priority queue
//Complexity: m, n is number of rows and cols

class Solution {
public:
  int rows, cols;
  unordered_map<int, pair<int, string> > isVisited;
  int get_index(int a, int b) {return 100 * a + b;}
  bool operator()(const tuple<int, int, int, string> &a, const tuple<int, int, int, string> &b) {
    return (get<2>(a) > get<2>(b)) || ((get<2>(a) == get<2>(b)) & (get<3>(a) > get<3>(b)));
  }
  string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
    rows = maze.size();
    cols = maze[0].size();
    priority_queue<tuple<int, int, int, string>, vector<tuple<int, int, int, string> >, Solution> q;
    q.push(make_tuple(ball[0], ball[1], 0, ""));
    isVisited[get_index(ball[0], ball[1])] = make_pair(0, "");
    while (!q.empty()) {
      auto tmp = q.top();
      int row = get<0>(tmp), col = get<1>(tmp), dist = get<2>(tmp);
      string dir = get<3>(tmp);
      q.pop();
      if ((row == hole[0]) & (col == hole[1])) return dir;
      int index = get_index(row, col);
      if (isVisited.count(index) && make_pair(dist, dir) > isVisited[index]) continue;
      if (row + 1 < rows && !maze[row + 1][col]) {
        int nxtRow = row + 1;
        while (nxtRow + 1 < rows && !maze[nxtRow + 1][col]) {
          if ((nxtRow == hole[0]) & (col == hole[1])) break;
          ++nxtRow;
        }
        int index = get_index(nxtRow, col);
        if (!isVisited.count(index) || make_pair(nxtRow - row + dist, dir + 'd') < isVisited[index]) {
          isVisited[index] = make_pair(nxtRow - row + dist, dir + 'd');
          q.push(make_tuple(nxtRow, col, nxtRow - row + dist, dir + 'd'));
        }
      }
      if (col + 1 < cols && !maze[row][col + 1]) {
        int nxtCol = col + 1;
        while (nxtCol + 1 < cols && !maze[row][nxtCol + 1]) {
          if ((row == hole[0]) & (nxtCol == hole[1])) break;
          ++nxtCol;
        }
        int index = get_index(row, nxtCol);
        if (!isVisited.count(index) || make_pair(nxtCol - col + dist, dir + 'r') < isVisited[index]) {
          isVisited[index] = make_pair(nxtCol - col + dist, dir + 'r');
          q.push(make_tuple(row, nxtCol, nxtCol - col + dist, dir + 'r'));
        }
      }
      if (row > 0 && !maze[row - 1][col]) {
        int nxtRow = row - 1;
        while (nxtRow > 0 && !maze[nxtRow - 1][col]) {
          if ((nxtRow == hole[0]) & (col == hole[1])) break;
          --nxtRow;
        }
        int index = get_index(nxtRow, col);
        if (!isVisited.count(index) || make_pair(row - nxtRow + dist, dir + 'u') < isVisited[index]) {
          isVisited[index] = make_pair(row - nxtRow + dist, dir + 'u');
          q.push(make_tuple(nxtRow, col, row - nxtRow + dist, dir + 'u'));
        }
      }
      if (col > 0 && !maze[row][col - 1]) {
        int nxtCol = col - 1;
        while (nxtCol > 0 && !maze[row][nxtCol - 1]) {
          if ((row == hole[0]) & (nxtCol == hole[1])) break;
          --nxtCol;
        }
        int index = get_index(row, nxtCol);
        if (!isVisited.count(index) || make_pair(col - nxtCol + dist, dir + 'l') < isVisited[index]) {
          isVisited[index] = make_pair(col - nxtCol + dist, dir + 'l');
          q.push(make_tuple(row, nxtCol, col - nxtCol + dist, dir + 'l'));
        }
      }
    }
    return "impossible";
    }
};