# Write your MySQL query statement below
SELECT ROUND((SUM(CASE WHEN first_orders.customer_pref_delivery_date = first_orders.order_date THEN 1 ELSE 0 END) / COUNT(first_orders.delivery_id)) * 100, 2) AS immediate_percentage
FROM (
    SELECT delivery_id, customer_id, order_date, customer_pref_delivery_date,
           ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY order_date) AS order_rank
    FROM Delivery
) AS first_orders
WHERE first_orders.order_rank = 1;
