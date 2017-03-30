/* MySQL Alternative Queries */


/*
https://www.hackerrank.com/challenges/draw-the-triangle-1

Draw the Triangle 1

* * * * * 
* * * * 
* * * 
* * 
*

*/

select repeat('* ', @n := @n - 1) from information_schema.tables, (select @n := 21) t limit 20;

/*
or

set @n=21;
select repeat('* ', @n := @n - 1) from information_schema.tables limit 20;
*/


/*
https://www.hackerrank.com/challenges/draw-the-triangle-2

Draw the Triangle 2

* 
* * 
* * * 
* * * * 
* * * * *

*/

select repeat('* ', @n := @n + 1) from information_schema.tables, (select @n := 0) t limit 20;

/*
or

set @n=0;
select repeat('* ', @n := @n + 1) from information_schema.tables limit 20;
*/


/*
https://www.hackerrank.com/challenges/print-prime-numbers

Print Prime Numbers

Write a query to print all prime numbers less than or equal to 1000.

Note: AND clauses needed as divisibles of these numbers are not primes (ex. num = 6 % 3 <> 0) unless is the number itself (ex. num=3)
num=3 occurs at join cols 3|0|0
num=6 occurs at join cols 6|0|0
*/

SELECT
    GROUP_CONCAT(sol.num
        SEPARATOR '&') AS result
FROM
    (SELECT
        a.a + (10 * b.a) + (100 * c.a) AS num
    FROM
        (SELECT 0 AS a UNION ALL SELECT 1 UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4 UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8 UNION ALL SELECT 9) AS a
    CROSS JOIN (SELECT 0 AS a UNION ALL SELECT 1 UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4 UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8 UNION ALL SELECT 9) AS b
    CROSS JOIN (SELECT 0 AS a UNION ALL SELECT 1 UNION ALL SELECT 2 UNION ALL SELECT 3 UNION ALL SELECT 4 UNION ALL SELECT 5 UNION ALL SELECT 6 UNION ALL SELECT 7 UNION ALL SELECT 8 UNION ALL SELECT 9) AS c
    HAVING (num > 1) AND (num % 2 <> 0 OR num = 2)
        AND (num % 3 <> 0 OR num = 3)
        AND (num % 5 <> 0 OR num = 5)
        AND (num % 7 <> 0 OR num = 7)
        AND (num % 11 <> 0 OR num = 11)
        AND (num % 13 <> 0 OR num = 13)
        AND (num % 17 <> 0 OR num = 17)
        AND (num % 19 <> 0 OR num = 19)
        AND (num % 23 <> 0 OR num = 23)
        AND (num % 29 <> 0 OR num = 29)
        AND (num % 31 <> 0 OR num = 31)) sol;