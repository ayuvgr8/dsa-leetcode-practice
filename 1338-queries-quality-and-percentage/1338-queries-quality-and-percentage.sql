# Write your MySQL query statement below
SELECT
    query_name, -- Select the query_name for the output
    ROUND(
        AVG(rating / position), -- Calculate the average of the ratio between query rating and position
        2
    ) AS quality, -- Rename the calculated value as quality and round it to 2 decimal places
    ROUND(
        (SUM(CASE WHEN rating < 3 THEN 1 ELSE 0 END) / COUNT(*)) * 100, -- Calculate the poor_query_percentage
        2
    ) AS poor_query_percentage -- Rename the calculated value as poor_query_percentage and round it to 2 decimal places
FROM
    Queries
GROUP BY
    query_name; -- Group the results by query_name
