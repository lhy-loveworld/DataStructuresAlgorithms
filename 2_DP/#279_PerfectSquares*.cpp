//#279
//Medium
//Arthor: lhy-loveworld
//Method: Method 1 uses BFS. Every round checks the numbers with the same numSquares.
//        Method 2 uses static variable. Caution for the static identifier's position.
//Complexity: time O(N)~O(N^2) space O(N)

class Solution {
public:
	//Method 1: BFS
    int numSquares(int n) {
        vector<int> perfS;
        vector<int> helper(n, 0);
        for (int i = 1; i * i <= n; ++i) {
            perfS.push_back(i * i);
            helper[i * i - 1] = 1;
        }
        if (helper[n - 1]) return 1;
        queue<int> squareQ;
        int curCnt = 2;
        for (int i = 0; i < perfS.size(); ++i) {
            for (int j = i; j < perfS.size(); ++j) {
                if (perfS[i] + perfS[j] > n) break;
                if (helper[perfS[i] + perfS[j] - 1] == 0) {
                    squareQ.push(perfS[i] + perfS[j]);
                    helper[perfS[i] + perfS[j] - 1] = curCnt;
                }
            }
        }
        while (helper[n - 1] == 0) {
            ++curCnt;
            int rnd = squareQ.size();
            for (int i = 0; i < rnd; ++i) {
                for (int j = 0; j < perfS.size(); ++j) {
                    if (squareQ.front() + perfS[j] > n) break;
                    if (helper[squareQ.front() + perfS[j] - 1] == 0) {
                        squareQ.push(squareQ.front() + perfS[j]);
                        helper[squareQ.front() + perfS[j] - 1] = curCnt;
                    }
                }
                squareQ.pop();
            }
        }
        return helper[n - 1];
    }

    //Method 2: static variable
    int numSquares(int n) {
        static vector<int> helper;
        if (helper.size() < n) {
            for (int i = helper.size(); i < n; ++i) {
                int Min = INT_MAX;
                for (int j = 1; j * j <= i + 1; ++j) {
                    if (j * j == i + 1)
                        Min = 1;
                    else
                        Min = min(Min, helper[j * j - 1] + helper[i - j * j]);
                }
                helper.push_back(Min);
            }
        }
        return helper[n - 1];
    }
};