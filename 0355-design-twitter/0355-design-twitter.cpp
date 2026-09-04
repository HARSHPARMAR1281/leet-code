class Twitter {
public:
    vector<vector<int>> friends;
    vector<vector<pair<int, int>>> tweets;
    int timer = 0;

    Twitter() {
        friends.resize(501);
        tweets.resize(501);
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timer++, tweetId});
    }

    void follow(int followerId, int followeeId) {
        
        for (int it : friends[followerId]) {
            if (it == followeeId)
                return;
        }

        friends[followerId].push_back(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        auto &v = friends[followerId];

        v.erase(remove(v.begin(), v.end(), followeeId), v.end());
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        for (auto &[time, tweetId] : tweets[userId]) {
            pq.push({time, tweetId});
        }

        for (int it : friends[userId]) {
            for (auto &[time, tweetId] : tweets[it]) {
                pq.push({time, tweetId});
            }
        }
        vector<int> ans;

        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};
