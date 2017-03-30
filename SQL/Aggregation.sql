/* MySQL Aggregation */


/*
https://www.hackerrank.com/challenges/revising-aggregations-the-count-function

Revising Aggregations - The Count Function
*/

SELECT COUNT(ID) FROM CITY WHERE POPULATION > 100000;



/*
https://www.hackerrank.com/challenges/revising-aggregations-sum

Revising Aggregations - The Sum Function
*/

SELECT SUM(POPULATION) FROM CITY WHERE DISTRICT = 'California';



/*
https://www.hackerrank.com/challenges/revising-aggregations-the-average-function

Revising Aggregations - Averages
*/

SELECT AVG(POPULATION) FROM CITY WHERE DISTRICT = 'California';



/*
https://www.hackerrank.com/challenges/average-population

Average Population
*/

SELECT ROUND(AVG(POPULATION),0) FROM CITY;



/*
https://www.hackerrank.com/challenges/japan-population

Japan Population
*/

SELECT SUM(POPULATION) FROM CITY WHERE COUNTRYCODE = 'JPN';



/*
https://www.hackerrank.com/challenges/population-density-difference

Population Density Difference
*/

SELECT MAX(POPULATION) - MIN(POPULATION) from CITY;



/*
https://www.hackerrank.com/challenges/the-blunder

The Blunder

Note: if num 2.51 floor is 2 and ceil is 3. Thus round up to the next integer is ceil function
*/

SELECT CEIL(AVG(SALARY)-AVG(REPLACE(SALARY,0,'')))
FROM EMPLOYEES;



/*
https://www.hackerrank.com/challenges/earnings-of-employees

Top Earners
*/

SELECT (salary * months) as te, count(employee_id) FROM employee
GROUP BY te 
HAVING te = max(salary * months) 
ORDER BY te desc
limit 1;

/*
or
also simple by no using group by and limit :

SELECT salary*months, count(*) FROM employee
WHERE salary*months = (select max(salary*months) from employee);
*/



/*
https://www.hackerrank.com/challenges/weather-observation-station-2

Weather Observation Station 2
*/

select CONCAT(ROUND(SUM(LAT_N),2), ' ', ROUND(SUM(LONG_W),2)) 
from STATION;   



/*
https://www.hackerrank.com/challenges/weather-observation-station-13

Weather Observation Station 13
*/

SELECT CAST(SUM(LAT_N) as decimal(36,4))  /* also ROUND(SUM(LAT_N),4) */
FROM STATION
WHERE LAT_N>=38.7880 AND LAT_N<=137.2345; /* also LAT_N between 38.7880 and 137.2345 */



/*
https://www.hackerrank.com/challenges/weather-observation-station-14

Weather Observation Station 14
*/

SELECT TRUNCATE(MAX(LAT_N), 4) /* also using ROUND or CAST */
FROM STATION
WHERE LAT_N < 137.2345;



/*
https://www.hackerrank.com/challenges/weather-observation-station-15

Weather Observation Station 15
*/

SELECT ROUND(LONG_W,4)
FROM STATION
WHERE LAT_N=(SELECT MAX(LAT_N) FROM STATION WHERE LAT_N < 137.2345);



/*
https://www.hackerrank.com/challenges/weather-observation-station-16

Weather Observation Station 16
*/

SELECT ROUND(MIN(LAT_N), 4)
FROM STATION
WHERE LAT_N > 38.7780;



/*
https://www.hackerrank.com/challenges/weather-observation-station-17

Weather Observation Station 17
*/

SELECT ROUND(LONG_W, 4)
FROM STATION
WHERE LAT_N = (SELECT MIN(LAT_N) FROM STATION WHERE LAT_N > 38.7780);



/*
https://www.hackerrank.com/challenges/weather-observation-station-18

Weather Observation Station 18

Note: Manhattan Distance
*/

SELECT ROUND(ABS(S.A-S.C)+ABS(S.B-S.D), 4)
FROM (SELECT MIN(LAT_N) AS A, MIN(LONG_W) AS B, MAX(LAT_N) AS C, MAX(LONG_W) AS D FROM STATION) S;



/*
https://www.hackerrank.com/challenges/weather-observation-station-19

Weather Observation Station 19

Note: Euclidean Distance
*/

SELECT ROUND(SQRT(POW(S.A-S.C,2) + POW(S.B - S.D,2)), 4)
FROM (SELECT MIN(LAT_N) AS A, MIN(LONG_W) AS B, MAX(LAT_N) AS C, MAX(LONG_W) AS D FROM STATION) S;



/*
https://www.hackerrank.com/challenges/weather-observation-station-20

Weather Observation Station 20

1)Use rownu as a distinct row id for each of the ordered Northern Latitudes
2)WHERE clause to index the median row id, then retrieve finally the LAT_N to 4 decimal places
*/

SET @rownumber=0;

SELECT CAST(X.LAT_N AS DECIMAL(36,4))
FROM
(
    SELECT LAT_N, @rownumber:=@rownumber+1 AS ROWNU
    FROM STATION
    ORDER BY LAT_N
) AS X
WHERE ROWNU = (SELECT ROUND((COUNT(LAT_N)+1)/2, 0) FROM STATION);
