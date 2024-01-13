# Write your MySQL query statement below
SELECT product_id
FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y';

# Explanation:

# We are selecting the product_id from the Products table.
# We use the WHERE clause to filter the rows where low_fats is 'Y' (low fat) and recyclable is 'Y' (recyclable).
# The result will be the product IDs of products that satisfy both conditions, which are low fat and recyclable.
# The output will be the product IDs in any order where the products are both low fat and recyclable.