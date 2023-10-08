# Write your MySQL query statement below
SELECT
    teacher_id, -- Select the teacher_id for the output
    COUNT(DISTINCT subject_id) AS cnt -- Calculate the count of unique subjects taught by each teacher
FROM
    Teacher
GROUP BY
    teacher_id; -- Group the results by teacher_id
