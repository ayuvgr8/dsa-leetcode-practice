# Write your MySQL query statement below
SELECT
    sell_date,
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product ASC) AS products
-- We start by using the SELECT statement to choose columns for the output.

FROM Activities
-- We are working with the Activities table.

GROUP BY sell_date
-- We group the rows by the sell_date. This allows us to aggregate data for each date.

ORDER BY sell_date
-- Finally, we order the result table by the sell_date in ascending order.
