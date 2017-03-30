/* MySQL Advanced Select */


/*
https://www.hackerrank.com/challenges/what-type-of-triangle

Type of Triangle
*/

SELECT CASE             
           WHEN A + B > C AND A + C > B AND B + C > A THEN /*if true Scalene unless. If false not a triangle*/
               CASE 
                   WHEN A = B AND B = C THEN 'Equilateral'
                   WHEN A = B OR B = C OR A = C THEN 'Isosceles'
                   ELSE 'Scalene'  /*A!=B and A!=C and B!=C */
               END
           ELSE 'Not A Triangle'
       END
FROM TRIANGLES;



/*
https://www.hackerrank.com/challenges/the-pads

The PADS
*/

SELECT CONCAT(Name,'(',SUBSTR(Occupation,1,1),')') FROM OCCUPATIONS
ORDER BY NAME;

SELECT CONCAT('There are total ', COUNT(Occupation), ' ', lower(Occupation), 's. ') /*or count(*) */
FROM OCCUPATIONS
GROUP BY Occupation
ORDER BY count(Occupation) ASC, Occupation ASC;  /*or count(*) */



/*
https://www.hackerrank.com/challenges/occupations

Occupations

Note: 
based idea of group by and min function in strings
Link: http://stackoverflow.com/questions/11377433/min-function-in-sql
Alternative to Pivot function in MySQL. Use if, case and aggr functions such as count
Link: http://stackoverflow.com/questions/12004603/mysql-pivot-row-into-dynamic-number-of-columns
*/

SET @d=0, @p=0, @s=0, @a=0;
SELECT MIN(Doctor),MIN(Professor),MIN(Singer),MIN(Actor) /*MIN(text) for sort order*/
FROM
(SELECT IF(OCCUPATION='Doctor',NAME,NULL) AS Doctor,
        IF(OCCUPATION='Professor',NAME,NULL) AS Professor,
        IF(OCCUPATION='Singer',NAME,NULL) AS Singer,
        IF(OCCUPATION='Actor',NAME,NULL) AS Actor,
 CASE OCCUPATION
    WHEN 'Doctor' THEN @d:=@d+1
    WHEN 'Professor' THEN @p:=@p+1
    WHEN 'Singer' THEN @s:=@s+1
    WHEN 'Actor' THEN @a:=@a+1
 END
AS idnum FROM OCCUPATIONS ORDER BY NAME ) tmp 
GROUP BY tmp.idnum; /*do this group by with the subselect statement to "transpose" your orig table */



/*
https://www.hackerrank.com/challenges/binary-search-tree-1

Binary Search Tree
*/

SELECT N, 
CASE 
WHEN P IS NULL THEN 'Root'
WHEN N IN (SELECT DISTINCT P FROM BST) THEN 'Inner' /* N IN (2,8,5) but 5 used prev as the root node */
ELSE 'Leaf'
END
FROM BST
ORDER BY N;



/*
https://www.hackerrank.com/challenges/the-company

New Companies
*/

SELECT c.company_code, c.founder, 
    COUNT(DISTINCT lm.lead_manager_code), COUNT(DISTINCT sm.senior_manager_code), 
    COUNT(DISTINCT m.manager_code),COUNT(DISTINCT e.employee_code) 
FROM Company c, Lead_Manager lm, Senior_Manager sm, Manager m, Employee e 
WHERE c.company_code = lm.company_code  /*or all relations with company_code field*/
    and lm.lead_manager_code= sm.lead_manager_code 
    and sm.senior_manager_code= m.senior_manager_code 
    and m.manager_code= e.manager_code 
GROUP BY c.company_code 
ORDER BY c.company_code;