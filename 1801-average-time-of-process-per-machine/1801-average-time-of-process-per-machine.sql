# Write your MySQL query statement below
SELECT 
    a.machine_id,
    ROUND(SUM(end_time - start_time) / COUNT(DISTINCT a.process_id), 3) AS processing_time
FROM
    (SELECT
        machine_id,
        process_id,
        MAX(CASE WHEN activity_type = 'start' THEN timestamp END) AS start_time,
        MAX(CASE WHEN activity_type = 'end' THEN timestamp END) AS end_time
    FROM Activity
    GROUP BY machine_id, process_id) AS a
GROUP BY a.machine_id;
