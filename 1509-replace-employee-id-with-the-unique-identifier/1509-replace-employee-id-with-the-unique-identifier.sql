# Write your MySQL query statement below
SELECT EUNI.unique_id, E.name
FROM Employees AS E
LEFT JOIN EmployeeUNI AS EUNI
ON E.id = EUNI.id;
