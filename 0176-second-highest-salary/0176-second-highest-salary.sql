# Write your MySQL query statement below
SELECT 
    (SELECT DISTINCT salary  -- Get distinct salaries
     FROM Employee
     ORDER BY salary DESC  -- Order from highest to lowest
     LIMIT 1 OFFSET 1)  -- Get the second highest
AS SecondHighestSalary;

# Explanation:

# SELECT (SELECT DISTINCT salary ...) AS SecondHighestSalary:

# The main SELECT statement retrieves a single value, which is the result of the nested SELECT query.
# It aliases the final result as SecondHighestSalary.
# (SELECT DISTINCT salary FROM Employee ORDER BY salary DESC LIMIT 1 OFFSET 1):

# This nested SELECT query does the heavy lifting:
# SELECT DISTINCT salary: Selects distinct salaries to avoid duplicates.
# FROM Employee: Fetches salaries from the Employee table.
# ORDER BY salary DESC: Orders the salaries in descending order.
# LIMIT 1 OFFSET 1: Takes only the second highest salary:
# LIMIT 1: Retrieves a single salary.
# OFFSET 1: Skips the first highest salary.
# Key Points:

# The nested SELECT query effectively isolates the second highest salary.
# DISTINCT ensures only unique salaries are considered.
# ORDER BY DESC arranges salaries in descending order, positioning the second highest salary at the desired index.
# LIMIT 1 OFFSET 1 efficiently fetches only the second highest salary.
# The outer SELECT presents the result with the appropriate alias.
