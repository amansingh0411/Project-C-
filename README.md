Mini Twitter Project Documentation
Introduction
The Mini Twitter project is a simple implementation of a social media platform that allows users to post tweets, follow other users, unfollow users, and retrieve recent tweets from themselves and users they follow. The project is implemented in C++ and provides a class miniTwitter to manage user actions and interactions.

Features
Posting Tweets: Users can post tweets with associated tweet IDs. The tweets are stored in the timeline data structure.

Following and Unfollowing Users: Users can follow other users to see their tweets in their news feed. Users can also unfollow users to stop seeing their tweets.

Retrieving Recent Tweets: Users can retrieve the 10 most recent tweets from their news feed. These tweets are ordered from the most recent to the least recent.

Class Structure
The project consists of a single class named miniTwitter, which contains the following private data members:

network: An unordered map that stores the followers for each user.
timeline: An unordered map that stores the tweets posted by each user along with their associated timestamps.
time: A variable to keep track of the timestamp for each tweet.
The class has the following public methods:

miniTwitter(): Constructor to initialize the class.
void postTweet(int userId, int tweetId): Method to post a new tweet by a user.
vector<int> getNewsFeed(int userId): Method to retrieve recent tweets from a user's news feed and the news feeds of the users they follow.
void follow(int followerId, int followeeId): Method for a user to follow another user.
void unfollow(int followerId, int followeeId): Method for a user to unfollow another user.
Usage
Compilation: Compile the code using a C++ compiler.

Running the Program: Run the compiled executable. The program will prompt the user with a menu of actions to choose from.

Posting a Tweet: Choose option 1, enter the user ID and tweet ID to post a new tweet.

Following a User: Choose option 2, enter the follower's ID and followee's ID to make the follower follow the followee.

Unfollowing a User: Choose option 3, enter the follower's ID and followee's ID to make the follower unfollow the followee.

Getting Recent Tweets: Choose option 4, enter the user ID to retrieve the 10 most recent tweets from the user's news feed.

Exiting the Program: Choose option 5 to exit the program.


Conclusion
The Mini Twitter project provides a basic implementation of a social media platform's functionalities. It can serve as a starting point for more complex projects or as a learning resource for understanding data structures and algorithms used in social media applications. Feel free to explore, modify, and build upon this project to suit your needs
