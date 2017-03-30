/* MySQL Basic Select */


/*
https://www.hackerrank.com/challenges/revising-the-select-query

Revising the Select Query I
*/

SELECT * FROM CITY WHERE COUNTRYCODE = 'USA' AND POPULATION > 100000;



/*
https://www.hackerrank.com/challenges/revising-the-select-query-2

Revising the Select Query II
*/

SELECT NAME FROM CITY WHERE COUNTRYCODE = 'USA' AND POPULATION > 120000;



/*
https://www.hackerrank.com/challenges/select-all-sql

Select All
*/

SELECT * FROM CITY;



/*
https://www.hackerrank.com/challenges/select-by-id

Select By ID
*/

SELECT * FROM CITY WHERE ID = 1661;



/*
https://www.hackerrank.com/challenges/japanese-cities-attributes

Japanese Cities' Attributes
*/

SELECT * FROM CITY WHERE COUNTRYCODE = 'JPN';



/*
https://www.hackerrank.com/challenges/japanese-cities-name

Japanese Cities' Names
*/

SELECT NAME FROM CITY WHERE COUNTRYCODE = 'JPN';



/*
https://www.hackerrank.com/challenges/weather-observation-station-1

Weather Observation Station 1
*/

SELECT CITY, STATE
FROM STATION
ORDER BY CITY, STATE;



/*
https://www.hackerrank.com/challenges/weather-observation-station-3

Weather Observation Station 3
*/

SELECT DISTINCT CITY
FROM STATION
WHERE MOD(ID,2) = 0
ORDER BY CITY;



/*
https://www.hackerrank.com/challenges/weather-observation-station-4

Weather Observation Station 4
*/

SELECT COUNT(CITY)-COUNT(DISTINCT CITY)
FROM STATION;



/*
https://www.hackerrank.com/challenges/weather-observation-station-5

Weather Observation Station 5
*/

SELECT CITY, LENGTH(CITY)
FROM STATION
ORDER BY LENGTH(CITY) ASC LIMIT 1;

SELECT CITY, LENGTH(CITY)
FROM STATION
ORDER BY LENGTH(CITY) DESC LIMIT 1;



/*
https://www.hackerrank.com/challenges/weather-observation-station-6

Weather Observation Station 6
*/

select DISTINCT(CITY) from STATION where lower(substr(city,1,1)) in ('a','e','i','o','u');



/*
https://www.hackerrank.com/challenges/weather-observation-station-7

Weather Observation Station 7
*/

SELECT DISTINCT(City) FROM Station WHERE RIGHT(City, 1) in ('a','e','i','o','u');



/*
https://www.hackerrank.com/challenges/weather-observation-station-8

Weather Observation Station 8

Note:
^ means exlusion or match occur at start
$ means match occur at the end
. means only single character after
+ means matches previous element one or more times
*/

SELECT DISTINCT(CITY) FROM STATION WHERE 
(CITY LIKE 'A%' OR CITY LIKE 'E%' OR CITY LIKE 'I%' OR CITY LIKE 'O%' OR CITY LIKE 'U%') 
AND (CITY LIKE '%a' OR CITY LIKE '%e' OR CITY LIKE '%i' OR CITY LIKE '%o' OR CITY LIKE '%u') ORDER BY City;



/*
https://www.hackerrank.com/challenges/weather-observation-station-9

Weather Observation Station 9

Note:
^ means exlusion or match occur at start
$ means match occur at the end
. means only single character after
+ means matches previous element one or more times
*/

SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP '^[^aeiouAEIOU]';



/*
https://www.hackerrank.com/challenges/weather-observation-station-10

Weather Observation Station 10
*/

SELECT DISTINCT CITY
FROM STATION
WHERE CITY REGEXP '[^aeiouAEIOU]$';



/*
https://www.hackerrank.com/challenges/weather-observation-station-11

Weather Observation Station 11
*/

select DISTINCT(T2.City) from 
(SELECT T1.City FROM station T1 WHERE lower(substr(T1.City, 1,1)) NOT IN ('a','e','i','o','u') 
union all
SELECT T1.City FROM station T1 WHERE lower(substr(T1.City, -1, 1)) NOT IN ('a','e','i','o','u')) T2;



/*
https://www.hackerrank.com/challenges/weather-observation-station-12

Weather Observation Station 12
*/

SELECT DISTINCT(CITY)
FROM STATION
WHERE CITY REGEXP "^[^aeiouAEIOU].+[^aeiouAEIOU]$"
ORDER BY CITY;



/*
https://www.hackerrank.com/challenges/more-than-75-marks

Higher Than 75 Marks
*/

SELECT Name
FROM STUDENTS
WHERE Marks>75
ORDER BY substr(Name, LENGTH(Name)-2, 3), ID;



/*
https://www.hackerrank.com/challenges/name-of-employees

Employee Names
*/

SELECT Name FROM EMPLOYEE ORDER BY Name;



/*
https://www.hackerrank.com/challenges/salary-of-employees

Employee Salaries
*/

SELECT Name FROM EMPLOYEE WHERE SALARY > 2000 AND MONTHS < 10 ORDER BY EMPLOYEE_ID;
