# Write your MySQL query statement below
SELECT
    r.contest_id, -- Select the contest_id for the output
    ROUND(COUNT(r.user_id) / (SELECT COUNT(DISTINCT user_id) FROM Users) * 100, 2) AS percentage -- Calculate the percentage of users registered in each contest
FROM
    Register r
GROUP BY
    r.contest_id -- Group the results by contest_id
ORDER BY
    percentage DESC, -- Order the result by percentage in descending order
    r.contest_id ASC; -- In case of a tie, order it by contest_id in ascending order
