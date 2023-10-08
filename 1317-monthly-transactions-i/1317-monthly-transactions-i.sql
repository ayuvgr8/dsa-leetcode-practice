# Write your MySQL query statement below
SELECT
    DATE_FORMAT(trans_date, '%Y-%m') AS month, -- Extract the year and month from trans_date
    country, -- Select the country for the output
    COUNT(*) AS trans_count, -- Calculate the total number of transactions for each group
    SUM(CASE WHEN state = 'approved' THEN 1 ELSE 0 END) AS approved_count, -- Calculate the number of approved transactions
    SUM(amount) AS trans_total_amount, -- Calculate the total amount of transactions
    SUM(CASE WHEN state = 'approved' THEN amount ELSE 0 END) AS approved_total_amount -- Calculate the total amount of approved transactions
FROM
    Transactions
GROUP BY
    month, country -- Group the results by month and country
