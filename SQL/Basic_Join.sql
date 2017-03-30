/* MySQL Basic Join */


/*
https://www.hackerrank.com/challenges/asian-population

Asian Population
*/

select SUM(city.population) FROM country,city WHERE continent='Asia' and country.code=city.countrycode;



/*
https://www.hackerrank.com/challenges/african-cities

Asian Cities
*/

select city.name from country,city where continent='Africa' and country.code=city.countrycode;



/*
https://www.hackerrank.com/challenges/average-population-of-each-continent

Average Population of Each Continent
*/

SELECT country.continent, FLOOR(AVG(city.population))
FROM country
INNER JOIN city
ON country.code=city.countrycode
GROUP BY country.continent;



/*
https://www.hackerrank.com/challenges/the-report

The Report

1)Use case statement to print names equal or higher than grade 8
2)relate the two tables student and grades to create the marks interval (min_mark<=stud_marks<=max_mark) for grade result per student
3)order by descending order by grade, then order students by their name alphabetically, then list them by their marks in ascending order
*/

SELECT
    CASE WHEN G.Grade>=8
        THEN S.Name
        ELSE NULL
    END,
G.Grade, S.Marks
FROM Students S
LEFT JOIN Grades G /*works also for INNER JOIN*/
    ON G.Min_Mark <= S.Marks AND S.Marks <= G.Max_Mark /*marks interval*/
ORDER BY G.Grade DESC, S.Name, S.Marks;



/*
https://www.hackerrank.com/challenges/full-score

Top Competitors

1)create your table using delegation order matching with the inner join. Hackers->Submission->Challenges->Difficulty. Relate them all each other and with the where statement. Eliminate ppl that did not earn full score (difficulty.score = submissions.score).
2)group by to name the hackers who achieved full scores for more than one challenge.
3)order by same as group by plus hacker_id as challenge stated
*/

SELECT submissions.hacker_id, hackers.name
FROM hackers
INNER JOIN submissions ON submissions.hacker_id = hackers.hacker_id
INNER JOIN challenges ON challenges.challenge_id=submissions.challenge_id
INNER JOIN difficulty ON challenges.difficulty_level = difficulty.difficulty_level
WHERE difficulty.difficulty_level= challenges.difficulty_level
    AND difficulty.score = submissions.score
GROUP BY submissions.hacker_id, hackers.name 
HAVING COUNT(submissions.hacker_id) > 1
ORDER BY COUNT(submissions.hacker_id) desc, hacker_id asc;



/*
https://www.hackerrank.com/challenges/harry-potter-and-wands

Ollivander's Inventory

1)Isolate the non-evil wand records
2a)min(coins_needed) the minimum number of gold galleons needed to buy of same power and age of non-evil wand records
2b)the sorting of min(coins_needed) of same power and age on inner select is explained well to the "The data for wands of age 40 (code 2):" on the testcase explanation
3)order by power then age descending as challenge stated
*/

SELECT w.id, wp.age, w.coins_needed, w.power FROM Wands as w
INNER JOIN Wands_Property as wp ON (w.code = wp.code) WHERE wp.is_evil = 0 and w.coins_needed = (select min(coins_needed) from Wands as w1
INNER JOIN Wands_Property as wp1 ON (w1.code = wp1.code) WHERE w1.power = w.power and wp1.age = wp.age)
ORDER BY w.power desc, wp.age desc;



/*
https://www.hackerrank.com/challenges/challenges

Challenges

1)select hacker_id, name, and the total number of challenges and join with challenges based on id
2)group by the hackers who create challenges and not then the same amount of them less than the max
3a)select all hackers with max challenges as same ppl with max challenges are accepted
3b)but not select the ones that have same number of challenges with different hacker_id (i.e different ppl solved same number of challenges) and have submit less than max challenges.
4)order your output by the total number of challenges in descending order, then sort the result by hacker_id

Note: 
group by c1.hacker_id order by count(c1.challenge_id) desc limit 1
Link: http://dba.stackexchange.com/questions/48418/sql-limit-count-group
*/

SELECT c.hacker_id, h.name, count(c.challenge_id) as recs FROM challenges c
INNER JOIN hackers h on c.hacker_id = h.hacker_id
GROUP BY c.hacker_id
HAVING
recs =
(select count(c1.challenge_id) from challenges as c1
 group by c1.hacker_id
 order by count(c1.challenge_id) desc limit 1)
OR
recs not in
(select count(c2.challenge_id) from challenges as c2
 group by c2.hacker_id having
 c.hacker_id != c2.hacker_id)
ORDER BY recs desc, c.hacker_id asc;



/*
https://www.hackerrank.com/challenges/contest-leaderboard

Contest Leaderboard

1)select hacker_id, name, and total score of the hackers
2a)find max score group by hacker and challenge to distinct results per challenge per score
2b)sum 2a) results per group by hacker_id
3)ordered by the descending score, then sort the result by ascending hacker_id
*/

SELECT h.hacker_id,h.name,sum(recs.scr) as tot
FROM Hackers h
INNER JOIN
    (
        select s2.hacker_id as hac_id,
        s2.challenge_id as ch_id,
        max(s2.score) as scr
        from Submissions s2
        group by s2.hacker_id,s2.challenge_id
        having scr > 0
    ) as recs
ON h.hacker_id = recs.hac_id
GROUP BY h.hacker_id
ORDER BY tot desc, h.hacker_id asc;
