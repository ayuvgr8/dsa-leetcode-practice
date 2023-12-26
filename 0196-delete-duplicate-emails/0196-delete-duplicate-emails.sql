# Write your MySQL query statement below
DELETE p1  -- Delete rows from the Person table
FROM Person p1
JOIN Person p2  -- Join with itself to find duplicates
ON p1.email = p2.email AND p1.id > p2.id;  -- Keep only the first instance (lowest id)


# Explanation:

# DELETE p1 FROM Person p1:

# Initiates a DELETE operation to remove rows from the Person table.
# Targets rows to be deleted using the alias p1.
# JOIN Person p2 ON p1.email = p2.email AND p1.id > p2.id:

# Joins the Person table with itself using aliases p1 and p2.
# Matches rows where email is the same in both instances.
# Crucially, p1.id > p2.id ensures we only consider duplicate emails where the id in p1 is higher than the id in p2.
# This means we'll keep the row with the lowest id for each unique email.
# WHERE clause (implicit):

# There's no explicit WHERE clause, but the JOIN condition effectively acts as a filter.
# Rows in p1 that don't have a matching duplicate in p2 based on the email and id conditions won't be deleted.
# Key Points:

# The self-join identifies duplicate emails.
# The p1.id > p2.id condition ensures we only delete the duplicates with higher id values, preserving the first instance.
# The implicit WHERE clause within the JOIN filters the rows to be deleted.
