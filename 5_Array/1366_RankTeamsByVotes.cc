// 1366. Rank Teams by Votes
// Medium
// Basic sorting function.
// TC: O(NlogN)
// SC: O(N)
class Solution {
 public:
  string rankTeams(vector<string>& votes) {
    int n = votes[0].size();
    std::vector<std::vector<int>> team_votes(26, std::vector<int>(n));
    for (const std::string& vote : votes) {
      for (int i = 0; i < n; ++i) {
          team_votes[vote[i] - 'A'][i]++;
      }
    }
    auto f = [&team_votes](char a, char b) {
      return team_votes[a - 'A'] > team_votes[b - 'A'] || team_votes[a - 'A'] == team_votes[b - 'A'] && a < b;
    };
    std::sort(votes[0].begin(), votes[0].end(), f);
    return votes[0];
  }
};
