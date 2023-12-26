# Write your MySQL query statement below
SELECT
    CASE
        WHEN id % 2 = 1 AND total_count != id THEN id + 1
        WHEN id % 2 = 0 THEN id - 1
        ELSE id
    END AS id,
    student
FROM (
    SELECT
        id,
        student,
        COUNT(*) OVER () AS total_count
    FROM Seat
) AS seats
ORDER BY id;
