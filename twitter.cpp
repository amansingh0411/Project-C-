#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// twitter class to implement the feature of twitter

class miniTwitter
{
private:
    unordered_map<int, set<int>> network;
    unordered_map<int, vector<pair<int, int>>> timeline;
    long long time=0;

public:
    miniTwitter()
    {
        time = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId)
    {
        timeline[userId].push_back({time++, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId)
    {
        priority_queue<pair<int, int>> maxHeap;
        for (auto it = timeline[userId].begin(); it != timeline[userId].end(); ++it)
            maxHeap.push(*it);
        for (auto it1 = network[userId].begin(); it1 != network[userId].end(); ++it1)
        {
            int usr = *it1; // get target user
            for (auto it2 = timeline[usr].begin(); it2 != timeline[usr].end(); ++it2)
                maxHeap.push(*it2);
        }
        vector<int> res;
        while (maxHeap.size() > 0)
        {
            res.push_back(maxHeap.top().second);
            if (res.size() == 10)
                break;
            maxHeap.pop();
        }
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId)
    {
        if (followerId != followeeId)
            network[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId)
    {
        network[followerId].erase(followeeId);
    }
};

int main()
{
    // Initialize the twitter object
    miniTwitter twitter;

    while (true)
    {
        cout << "Choose an action:\n";
        cout << "1. Post a tweet\n";
        cout << "2. Follow a user\n";
        cout << "3. Unfollow a user\n";
        cout << "4. Get recent tweets\n";
        cout << "5. Exit\n";
        
        int choice;
        cin >> choice;

        if (choice == 1)
        {
            int userId, tweetId;
            cout << "Enter user ID: ";
            cin >> userId;
            cout << "Enter tweet ID: ";
            cin >> tweetId;
            twitter.postTweet(userId, tweetId);
        }
        else if (choice == 2)
        {
            int followerId, followeeId;
            cout << "Enter follower's ID: ";
            cin >> followerId;
            cout << "Enter followee's ID: ";
            cin >> followeeId;
            twitter.follow(followerId, followeeId);
        }
        else if (choice == 3)
        {
            int followerId, followeeId;
            cout << "Enter follower's ID: ";
            cin >> followerId;
            cout << "Enter followee's ID: ";
            cin >> followeeId;
            twitter.unfollow(followerId, followeeId);
        }
        else if (choice == 4)
        {
            int userId;
            cout << "Enter user ID: ";
            cin >> userId;
            vector<int> recentTweets = twitter.getNewsFeed(userId);
            cout << "Recent tweets:\n";
            for (int tweetId : recentTweets)
            {
                cout << tweetId << " ";
            }
            cout << endl;
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
