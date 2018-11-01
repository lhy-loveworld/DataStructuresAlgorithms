//#505. The Maze II
//Medium
//Method: two methods
//Complexity: m, n is number of rows and cols

class Solution {
public:
    //Method 1: dijkstra's algorithm with priority_queue
    //Complexity: time O(mnlog(mn)) space O(mn)
    struct myComp { // We can define structure inside a class
      bool operator()(const tuple<int, int, int> &a, const tuple<int, int, int> &b) const {
          return get<2>(a) > get<2>(b); // priority queue is implemented as a vector, its top element is its last element, true means a will go before b (a becomes b's child)
      }
    };
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        vector<vector<int> > dists;
        int rows = maze.size(), cols = maze[0].size();
        dists = vector<vector<int> > (rows, vector<int> (cols, 10000));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, myComp> pq;
        pq.push(make_tuple(start[0], start[1], 0));
        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();
            int row = get<0>(p), col = get<1>(p), dist = get<2>(p);
            if (dist >= dists[row][col]) continue;
            if (row == destination[0] && col == destination[1])
                return dist;
            dists[row][col] = dist;
            for (int dir = 0; dir < 4; ++dir) {
                int nxtRow = row, nxtCol = col, nxtDist = dist;
                switch (dir) {
                    case 0:
                        while (nxtRow && !maze[nxtRow - 1][nxtCol]) {
                            --nxtRow;
                            ++nxtDist;
                        }
                        break;
                    case 1:
                        while (nxtRow < rows - 1 && !maze[nxtRow + 1][nxtCol]) {
                            ++nxtRow;;
                            ++nxtDist;
                        }
                        break;
                    case 2:
                        while (nxtCol && !maze[nxtRow][nxtCol - 1]) {
                            --nxtCol;;
                            ++nxtDist;
                        }
                        break;
                    case 3:
                        while (nxtCol < cols - 1 && !maze[nxtRow][nxtCol + 1]) {
                            ++nxtCol;;
                            ++nxtDist;
                        }
                        break;
                }
                if (nxtDist < dists[nxtRow][nxtCol]) {
                    pq.push(make_tuple(nxtRow, nxtCol, nxtDist));
                }
            }
        }
        return -1;
    }


    //Method 2: BFS
    //Complexity: time O(mn) space O(m + n) for queue, O(mn) for unordered_set
    //This method is slower because there are two many push and pop options for the queue
    queue<tuple<int, int, int> > Q;
      unordered_set<int> isVisited;
int rows, cols;
  int gen_feature(int a, int b, int c) {
    return c + b * 10 + a * 10000;
  }
  bool proceed(int row, int col, int dir, vector<vector<int>>& maze, vector<int>& destination) {
    int nxtRow = row, nxtCol = col;
    switch (dir) {
      case 0:
        --nxtRow;
        break;
      case 1:
        ++nxtRow;
        break;
      case 2:
        --nxtCol;
        break;
      case 3:
        ++nxtCol;
        break;
    }
    if (nxtCol < cols && nxtCol >= 0 && nxtRow < rows && nxtRow >= 0 && maze[nxtRow][nxtCol] == 0) {
      int feature = gen_feature(nxtRow, nxtCol, dir);
      if (!isVisited.count(feature)) {
        isVisited.insert(feature);
        Q.push(make_tuple(nxtRow, nxtCol, dir));
      }
    } else {
      if (row == destination[0] && col == destination[1]) return true;
      for (int newDir = 0; newDir < 4; ++newDir) {
        if (dir == newDir) continue;
        int feature = gen_feature(row, col, newDir);
        if (!isVisited.count(feature)) {
          isVisited.insert(feature);
          if (proceed(row, col, newDir, maze, destination)) return true;
        }
      }
    }
    return false;
  }
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination){
      
      int distance = 0;
      rows = maze.size(); cols = maze[0].size();
      for (int dir = 0; dir < 4; ++dir) {
        Q.push(make_tuple(start[0], start[1], dir));
        isVisited.insert(gen_feature(start[0], start[1], dir));
      }
      while (!Q.empty()) {
        int rnd = Q.size();

        while (rnd) {
          auto tmp = Q.front();
          int row = get<0>(tmp), col = get<1>(tmp), dir = get<2>(tmp);
          Q.pop();
          if (proceed(row, col, dir, maze, destination)) return distance;
          --rnd;
        }
        ++distance;
      }
      return -1;
    }
};