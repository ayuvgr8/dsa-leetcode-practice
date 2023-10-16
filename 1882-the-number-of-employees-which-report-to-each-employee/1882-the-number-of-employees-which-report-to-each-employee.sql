# Write your MySQL query statement below
WITH DirectReports AS (
    SELECT
        reports_to AS manager_id,
        COUNT(*) AS reports_count,
        ROUND(AVG(age), 0) AS average_age
    FROM Employees
    WHERE reports_to IS NOT NULL
    GROUP BY reports_to
)

SELECT
    e.employee_id AS employee_id,
    e.name AS name,
    COALESCE(dr.reports_count, 0) AS reports_count,
    COALESCE(dr.average_age, 0) AS average_age
FROM Employees e
LEFT JOIN DirectReports dr ON e.employee_id = dr.manager_id
WHERE dr.reports_count IS NOT NULL
ORDER BY e.employee_id;
