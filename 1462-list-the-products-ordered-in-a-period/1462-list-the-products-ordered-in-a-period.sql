# Write your MySQL query statement below
SELECT p.product_name, SUM(o.unit) AS unit
-- Select the product name from the Products table
-- and calculate the sum of units ordered as 'unit' from the Orders table.
FROM Products p
-- Use an alias 'p' for the Products table.
-- This allows us to refer to the table with a shorter name.
INNER JOIN Orders o
-- Perform an inner join between the Products and Orders tables.
-- We want to match product_id from Products with product_id from Orders.
ON p.product_id = o.product_id
-- This condition links the two tables based on the product_id column.
-- It ensures that each product's information corresponds to its orders.
WHERE YEAR(order_date) = 2020
-- Filter rows where the order_date year is 2020.
AND MONTH(order_date) = 2
-- Further filter rows where the order_date month is February (month number 2).
GROUP BY p.product_name
-- Group the results by product name. This combines rows with the same product name.
HAVING SUM(o.unit) >= 100
-- Use the HAVING clause to filter grouped results.
-- We want to keep only products with a total unit sum greater than or equal to 100.
