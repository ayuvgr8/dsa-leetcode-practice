# Write your MySQL query statement below
SELECT E1.name
FROM Employee E1
JOIN (
    SELECT managerId, COUNT(*) AS reportCount
    FROM Employee
    GROUP BY managerId
) AS Reports ON E1.id = Reports.managerId
WHERE Reports.reportCount >= 5;

