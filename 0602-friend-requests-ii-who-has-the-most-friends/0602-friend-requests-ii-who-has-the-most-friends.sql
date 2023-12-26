# Write your MySQL query statement below
SELECT id, COUNT(*) AS num
FROM (
    SELECT requester_id AS id
    FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS id
    FROM RequestAccepted
) t
GROUP BY id
ORDER BY num DESC
LIMIT 1;


# Explanation:

# SELECT requester_id AS id FROM RequestAccepted UNION ALL SELECT accepter_id AS id FROM RequestAccepted: This subquery combines the requester and accepter IDs from the RequestAccepted table. UNION ALL is used to combine the IDs from both columns into one list of IDs.

# SELECT id, COUNT(*) AS num FROM (...) t GROUP BY id ORDER BY num DESC LIMIT 1: The outer query groups the combined IDs obtained from the subquery, counts the occurrences of each ID, orders them in descending order based on the count, and limits the result to the first row (with the highest count), effectively getting the person with the most friends.

# This query first aggregates all the requester and accepter IDs into one list, then counts the occurrences of each ID to find the person with the most friends by selecting the ID with the highest count. If multiple people have the same highest count, they will all be retrieved due to the LIMIT 1 clause which returns only the first row, but you can remove the LIMIT 1 clause if you want to see all people with the same maximum count of friends.