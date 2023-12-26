# Write your MySQL query statement below
SELECT user_id, CONCAT(UPPER(LEFT(name, 1)), LOWER(SUBSTRING(name, 2))) AS name
FROM Users
ORDER BY user_id;



# Explanation:

# SELECT user_id, ...:

# Selects the user_id column and a modified version of the name column.
# CONCAT(UPPER(LEFT(name, 1)), LOWER(SUBSTRING(name, 2))) AS name:

# Constructs the corrected name using string manipulation functions:
# UPPER(LEFT(name, 1)): Extracts the first character of name and converts it to uppercase.
# LOWER(SUBSTRING(name, 2)): Extracts the rest of the name (from the second character onwards) and converts it to lowercase.
# CONCAT(...): Combines the uppercase first character and lowercase rest into a single string, resulting in the desired format.
# FROM Users:

# Retrieves data from the Users table.
# ORDER BY user_id:

# Arranges the results in ascending order based on the user_id column.
# Key Points:

# UPPER() and LOWER() functions are used for case manipulation.
# LEFT() and SUBSTRING() functions extract specific parts of a string.
# CONCAT() joins multiple strings together.
# The query effectively corrects the name format without modifying the underlying table data.