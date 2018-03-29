//#355. Design Twitter
//Easy
//Method: two methods
//Complexity: Time O(N); Space O(1)

class Twitter {
    private:
        unordered_map<int, unordered_set<int> > Users;
        deque<pair<int, int> > Tweets;
public:
    /** Initialize your data structure here. */
    Twitter() {
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if (!Users.count(userId))
            Users[userId] = unordered_set<int> ({});
        Tweets.push_front(make_pair(userId, tweetId));
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        if (Users.count(userId)) {
            for (auto p: Tweets) {
                if (p.first == userId || Users[userId].count(p.first)) {
                    res.push_back(p.second);
                    if (res.size() == 10)
                        return res;
                }
            }
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if (!Users.count(followerId))
            Users[followerId] = unordered_set<int> ({});
        Users[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (Users.count(followerId))
            Users[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */