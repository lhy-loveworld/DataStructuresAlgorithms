// #686. Repeated String Match
// Medium
// Method: Use of KMP Algo
// Complexity: time O(A + B). space O(B)

class Solution {
 public:
  int repeatedStringMatch(string A, string B) {
    int sA = A.size(), sB = B.size();
    if (!sB) return 1;
    if (!sA) return -1;

    // building of partial match table. (also known as failure function)
    // entry in this table means when this match fails, which position in B
    // should we go to. -1 means this rep fails, we also need to change the pos
    // in A.
    vector<int> helper(sB);
    helper[0] = -1;
    // pos means the next char in our search (the suffix of the substring so far
    // ), cnd means the next candidate char to match (which is the end of the
    // prefix of B)
    int pos = 1, cnd = 0;
    while (pos < sB) {
      if (B[pos] == B[cnd]) {
        helper[pos] = helper[cnd];
      } else {
        // when the match fails, it need to match with B[cnd]
        helper[pos] = cnd;

        // these two lines is to find the matching suffix and prefix
        cnd = helper[cnd];
        while (cnd != -1 && B[cnd] != B[pos]) cnd = helper[cnd];
      }
      pos++;
      cnd++;
    }
    int pA = 0, pB = 0;
    while (1) {
      if (A[pA % sA] == B[pB]) {
        // when matches, we continue
        pA++;
        pB++;
	if (pA == sA + sB) return -1;
        if (pB == sB) return ceil(double(pA) / sA);
      } else {
	// when this match fails, we go back to last candidate, but still keep
	// pos in A
        pB = helper[pB];

        // if -1, the search fails, we update pos in A and restart search
        if (pB < 0) {
	  pA++;
          pB++;
	  if (pA == sA + sB) return -1;
        }
      }
    }
  }
};
