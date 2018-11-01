//#307. Range Sum Query - Mutable
//Medium
//Method: multiple methods
//Complexity: time O(logN). space O(N)

class NumArray {
    //Method 1: segment tree (binary tree stored in vector)
    //Complexity: time O(logN) for both, space O(N)
    vector<int> segTree;
public:
    //Store the nums in the leaf nodes.
    //The value of every node is the sum of its children
    NumArray(vector<int> nums) {
        segTree = vector<int> (nums.size());
        segTree.insert(segTree.end(), nums.begin(), nums.end());
        for (int i = nums.size() - 1; i > 0; --i) {
            segTree[i] = segTree[2 * i] + segTree[2 * i + 1];
        }
    }
    
    void update(int i, int val) {
        int n = segTree.size() / 2, diff = val - segTree[n + i];
        i += n;
        while (i > 0) {
            segTree[i] += diff;
            i /= 2;
        }
    }
    
    //find the least nodes need to be summed up
    int sumRange(int i, int j) {
        int n = segTree.size() / 2;
        i += n;
        j += n;
        int res = 0;
        while (i <= j) {
            if (i % 2) {
                res += segTree[i];
                ++i;
            }
            if (j % 2 == 0) {
                res += segTree[j];
                --j;
            }
            i /= 2;
            j /= 2;
        }
        return res;
    }

    //Method 2: every entry in partialSum stores any pos whose binary form is contained by the current num
    //Complexity: time O(logN) for both, space O(N)
private:
    vector<int> original;
    vector<int> partialSum;
public:
    NumArray(vector<int> nums) {
        original = vector<int> (nums.size());
        partialSum = vector<int> (nums.size());
        for (int i = 0; i < nums.size(); ++i) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        int diff = val - original[i];
        original[i] = val;
        while (i < partialSum.size()) {
            partialSum[i] += diff;
            i |= i + 1; //bit operation
        }
    }
    //When calculating the range sum, first convert it into ranges starting from 0, and adds up all the 1's combination (the binary representations containing most 1s) that don't overlap with each other
    int sumRange(int i, int j) {
        if (i == 0) {
            int res = 0;
            while (j >= 0) {
                res += partialSum[j];
                j = (j & (j + 1)) - 1; //bit operation
            }
            return res;
        }
        return sumRange(0, j) - sumRange(0, i - 1);
    }

    //Method 3: use piecewise sum, the best situation is when the number of pieces is sqrt(N)
    //Complexity: time O(sqrt(N)), space O(N)
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */