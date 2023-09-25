# Write your MySQL query statement below
SELECT tweet_id
FROM Tweets
WHERE LENGTH(content) > 15;

# Explanation:

# We are selecting the tweet_id from the Tweets table.
# We use the WHERE clause to filter the rows where the length of the content column is greater than 15. This checks if the number of characters in the tweet content is strictly greater than 15.
# The result will be the tweet_id of tweets that are considered invalid based on the condition.
# The output will be the tweet IDs of invalid tweets where the content length is greater than 15.