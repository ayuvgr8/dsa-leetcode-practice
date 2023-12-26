# Write your MySQL query statement below
SELECT s.product_id, MIN(s.year) AS first_year, s.quantity, s.price
FROM Sales s
JOIN Product p ON s.product_id = p.product_id
WHERE (s.product_id, s.year) IN (
    SELECT product_id, MIN(year) AS first_year
    FROM Sales
    GROUP BY product_id
)
GROUP BY s.product_id, s.year, s.quantity, s.price

# Explanation with line-by-line comments:

# SELECT s.product_id, MIN(s.year) AS first_year, s.quantity, s.price: Select the product_id, the minimum year as first_year, quantity, and price from the Sales table.

# FROM Sales s: Declare the Sales table with alias s.

# JOIN Product p ON s.product_id = p.product_id: Join the Sales table with the Product table based on the product_id column to get the product names.

# WHERE (s.product_id, s.year) IN (SELECT product_id, MIN(year) AS first_year FROM Sales GROUP BY product_id): Filter the rows to only include those where the combination of product_id and year matches the first year of each product's sale.

# GROUP BY s.product_id, s.year, s.quantity, s.price: Group the results by product_id, year, quantity, and price. This ensures that you get distinct records for each combination of product_id, year, quantity, and price.

# This query selects the desired columns from the Sales table, identifies the first year a product was sold, and retrieves the associated quantity and price for that first year for each product. The output will display product_id, first_year, quantity, and price for the first year of every product sold.