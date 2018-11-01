//#295. Find Median from Data Stream
//Hard
//Method: two methods
//Complexity: time O(logN). space O(N)

class MedianFinder {
public:
    //Method 1: using two priority queues to store the left half and the right half.
    //          we only care about the top of each half
    priority_queue<int> left;
    priority_queue<int, vector<int>, std::greater<int> > right;
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    //O(N)
    void addNum(int num) {
        if (left.empty() || num <= left.top()) left.push(num);
        else right.push(num);
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
        if (left.size() < right.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    //O(1)
    double findMedian() {
        if (left.empty()) return 0;
        if (left.size() > right.size()) return left.top();
        return (left.top() + right.top()) / 2.0;
    }

    //Method 2: use a binary search tree to store the whole stream, and use index for duplicate nums
    //iterator operation is constant time
    /** initialize your data structure here. */
    map<int, int> helper;
    map<int, int>::const_iterator MedianIter;
    int TotalNumber;
    int MedianIndex;
    MedianFinder() {
        TotalNumber = 0;
        MedianIndex = 0;
    }
    
    void addNum(int num) {
        if (helper.empty()) {
            helper[num] = 1;
            MedianIter = helper.cbegin();
        } else {
            helper[num]++;
            if (num >= MedianIter->first) {
                if (TotalNumber % 2 == 0) {
                    MedianIndex++;
                    if (MedianIndex == MedianIter->second) {
                        MedianIter++;
                        MedianIndex = 0;
                    }
                }
            } else {
                if (TotalNumber % 2) {
                    MedianIndex--;
                    if (MedianIndex < 0) {
                        MedianIter--;
                        MedianIndex = MedianIter->second - 1;
                    }
                }
            }
        }
        TotalNumber++;
    }
    
    double findMedian() {
        if (TotalNumber % 2 || MedianIndex + 1 < MedianIter->second) return MedianIter->first;
        auto it = MedianIter;
        it++;
        return (MedianIter->first + it->first) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */