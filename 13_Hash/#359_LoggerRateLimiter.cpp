//#359. Logger Rate Limiter
//Easy
//Method: unordered_map
//Complexity: time O(1). space O(N)

class Logger {
    private:
    unordered_map<string, int> msgToTimestamp;
public:
    /** Initialize your data structure here. */
    Logger() {
        
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = msgToTimestamp.find(message);
        bool res = false;
        if (it == msgToTimestamp.end() || timestamp - it->second >= 10) {
            res = true;
            msgToTimestamp[message] = timestamp;
        }
        return res;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */