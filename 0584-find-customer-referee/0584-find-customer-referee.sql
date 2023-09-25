# Write your MySQL query statement below
#SELECT name FROM customer WHERE referee_Id <> 2;

#SELECT name FROM customer WHERE referee_id <> 2 OR referee_id IS NULL;

SELECT name FROM customer WHERE referee_id != 2 OR referee_id IS NULL;





# Now, let's break down this query and add comments for better understanding:

# We start by selecting the name of customers (c1.name) from the Customer table.
# We use a LEFT JOIN to join the Customer table with itself twice:
# c1 represents the customer for whom we want to find the name.
# c2 represents the referee of the customer (c1) if there is any (ON c1.id = c2.referee_id).
# In the WHERE clause, we filter the results:
# We select customers who either have no referee (c1.referee_id IS NULL) or whose referee's id is not equal to 2 (c1.referee_id != 2).
# This query will return the names of customers who are not referred by the customer with id = 2.