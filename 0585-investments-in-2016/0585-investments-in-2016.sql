# Write your MySQL query statement below
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance
WHERE tiv_2015 IN (
    SELECT tiv_2015
    FROM Insurance
    GROUP BY tiv_2015
    HAVING COUNT(pid) > 1
)
AND (lat, lon) IN (
    SELECT lat, lon
    FROM Insurance
    GROUP BY lat, lon
    HAVING COUNT(pid) = 1
);


# Explanation:

# SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016: Selects the rounded sum of tiv_2016 values as tiv_2016 in the output.

# WHERE tiv_2015 IN (...): Filters rows where tiv_2015 values are present in the subquery.

# SELECT tiv_2015 FROM Insurance GROUP BY tiv_2015 HAVING COUNT(pid) > 1: Subquery finds tiv_2015 values that are shared by more than one policyholder.

# AND (lat, lon) IN (...): Further filters rows based on unique location pairs.

# SELECT lat, lon FROM Insurance GROUP BY lat, lon HAVING COUNT(pid) = 1: Subquery finds unique location pairs.

# This query retrieves the sum of tiv_2016 for policyholders meeting both conditions: having the same tiv_2015 value as other policyholders and being in a unique location (unique latitude and longitude pair). The ROUND function ensures the result is rounded to two decimal places, as required in the output.