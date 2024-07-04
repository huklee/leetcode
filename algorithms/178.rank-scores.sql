-- # Write your MySQL query statement below
SELECT
  Score,
  (SELECT count(distinct score) FROM Scores WHERE Score >= s.score) AS "rank"
FROM Scores s
ORDER BY Score desc
