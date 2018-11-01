//#815. Bus Routes
//Hard
//Method: BFS, if there are fewer stops than buses, we should do BFS on stops
//Complexity: 

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
      if (S == T) return 0;
      int n = routes.size();  
      vector<unordered_set<int> > busToStop(n);
      vector<unordered_set<int> > busToBus(n);
      unordered_map<int, unordered_set<int> > stopToBus;
      for (int i = 0; i < n; ++i) {
        for (const int& j: routes[i]) {
          busToStop[i].insert(j);
          for (const int& k: stopToBus[j]) {
            busToBus[k].insert(i);
            busToBus[i].insert(k);
          }
          stopToBus[j].insert(i);
        }
      }
      vector<bool> isVisited(n);
      queue<int> busQueue;
      for (const int& i: stopToBus[S]) {
        busQueue.push(i);
        isVisited[i] = true;
      }
      int res = 0;
      while (!busQueue.empty()) {
        ++res;
        int rnd = busQueue.size();
        for (int i = 0; i < rnd; ++i) {
          int tmp = busQueue.front();
          busQueue.pop();
          if (busToStop[tmp].count(T)) return res;
          for (const int& nxtBus: busToBus[tmp]) {
            if (!isVisited[nxtBus]) {
              isVisited[nxtBus] = true;
              busQueue.push(nxtBus);
            }
          }
        }
      }
      return -1;
    }
};