# Write your MySQL query statement below
SELECT 
    V.customer_id,
    COUNT(V.visit_id) AS count_no_trans  -- Count visits without transactions
FROM Visits V
LEFT JOIN Transactions T ON V.visit_id = T.visit_id  -- Join visits with transactions
WHERE T.visit_id IS NULL  -- Filter visits without matching transactions
GROUP BY V.customer_id;  -- Group by customer to count their visits without transactions
