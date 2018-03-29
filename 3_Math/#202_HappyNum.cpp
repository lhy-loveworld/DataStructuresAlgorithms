//#202. Happy Number
//Easy
//Method: hash, fast and slow runner
//Complexity: Time O(N^2); Space O(N^2)

class Solution {
    int digitSquareSum(int a){
        int sum = 0;
        while(a != 0){
            sum += (a%10)*(a%10);
            a /= 10;
        }
        return sum;
    }
public:
    //Method 1: Fast and slow runner, can solve all the whether is a loop problem
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do{
            slow = digitSquareSum(slow);
            fast = digitSquareSum(fast);
            fast = digitSquareSum(fast);
        }while(slow != fast);
        return slow==1?1:0;
    }

    //Method 2: Hash set
    bool isHappy(int n) {
        unordered_set<int> Interim;
        while (n != 1) {
            Interim.insert(n);
            int tmp = 0;
            while (n) {
                tmp += (n % 10) * (n % 10);
                n /= 10;
            }
            if (Interim.count(tmp))
                return false;
            n = tmp;
        }
        return true;
    }
};