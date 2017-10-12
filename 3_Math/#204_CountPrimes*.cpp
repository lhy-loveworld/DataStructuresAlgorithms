//#204. Count Primes
//Easy
//Method: Only count odd nums, and remove all the nums not satisfying, also only consider odd nums
//Complexity: time O(n); space O(n)

class Solution {
public:
    int countPrimes(int n) {
        if (n < 3) return 0;
        vector<bool> notPrime(n, false);
        int count = n / 2;
        for (int i = 3; i * i < n; i += 2)
          if (!notPrime[i])
            for (int j = i * i; j < n; j += 2 * i)
              if (!notPrime[j]) {
                --count;
                notPrime[j] = true;
              }
        return count;
    }
};
