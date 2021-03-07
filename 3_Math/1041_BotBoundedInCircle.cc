// 1041. Robot Bounded In Circle
// Medium
// Repeat four times. If at the end of each rep, it returns to the starting
// point and faces the same dir. return true.
// TC: O(N)
// SC: O(1)
class Solution {
 public:
  bool isRobotBounded(string instructions) {
    std::pair<int, int> pos{0, 0};
    int dir = 0;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < instructions.size(); ++j) {
	switch (instructions[j]) {
          case 'G':
            switch (dir) {
              case 0:
                pos.second++;
		break;
              case 1:
                pos.first++;
                break;
              case 2:
                pos.second--;
                break;
              case 3:
                pos.first--;
	    }
            break;
          case 'L':
            dir = (dir + 3) % 4;
            break;
          case 'R':
            dir = (dir + 1) % 4;
	}
      }
      if (pos.first == 0 && pos.second == 0 && dir == 0) return true;
    }
    return false;
  }
};
