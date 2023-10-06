# Write your MySQL query statement below
SELECT
    p.project_id, -- Select the project_id for the output
    ROUND(AVG(e.experience_years), 2) AS average_years -- Calculate the average experience_years and round to 2 digits
FROM
    Project p
JOIN
    Employee e ON p.employee_id = e.employee_id -- Join Project and Employee tables on employee_id
GROUP BY
    p.project_id; -- Group the results by project_id
