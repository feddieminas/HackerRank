/* MySQL Advanced Join */


/*
https://www.hackerrank.com/challenges/projects

Projects
*/

SELECT PS.Start_Date, PE.End_Date
FROM 
    (select Start_Date from Projects where Start_Date not in (select End_Date from Projects)) PS,
    (select End_Date from Projects where End_Date not in (select Start_Date from Projects)) PE
WHERE PS.Start_Date < PE.End_Date
GROUP BY PS.Start_Date 
ORDER BY DATEDIFF(PS.Start_Date,PE.End_Date) DESC, PS.Start_Date asc;



/*
https://www.hackerrank.com/challenges/placements

Placements
*/

SELECT s.Name
FROM Students s
INNER JOIN Friends f ON s.ID = f.ID
INNER JOIN Packages p1 ON s.ID = p1.ID
INNER JOIN Packages p2 ON f.Friend_ID = p2.ID /*two diff Packages P1 and P2 for friends and best_friends salary comparisons*/
WHERE p1.Salary < p2.Salary
ORDER BY p2.Salary;



/*
https://www.hackerrank.com/challenges/symmetric-pairs

Symmetric Pairs

Select the ones with diff numbers (i.e. 20 21) and in asc order (f2.x>f1.x) to output 20 21 rather than 21 20
union
Select the ones with unique numbers (i.e. 20 20), more than a single record exists to verify there is a symmetric pair
Order by the value of x.
*/

SELECT *  /*x,y*/
FROM
(
select x, y from Functions f1
    where exists(select x, y from functions f2 where f2.y=f1.x
    and f2.x=f1.y and f2.x>f1.x) and (f1.x!=f1.y)  
union
select x, y from Functions f1 where x=y and
    ((select count(*) from functions where x=f1.x and y=f1.x)>1)
) ft
ORDER BY ft.x; 



/*
https://www.hackerrank.com/challenges/interviews

Interviews
*/

SELECT CONT.Contest_id, CONT.hacker_id, CONT.Name, SUM(S.TS), SUM(S.TAS), SUM(V.TV), SUM(V.TUV) 
FROM Contests CONT 
INNER JOIN Colleges COL ON COL.Contest_id = CONT.Contest_id 
INNER JOIN Challenges CH ON CH.College_id = COL.College_id 
LEFT JOIN ( select Challenge_id, SUM(ifnull(total_submissions,0)) AS TS, SUM(ifnull(total_accepted_submissions,0)) TAS from SUBMISSION_STATS group by Challenge_id ) AS S ON S.Challenge_id = CH.Challenge_id
LEFT JOIN ( select Challenge_id, SUM(ifnull(total_views,0)) AS TV, SUM(ifnull(total_unique_views,0)) TUV from VIEW_STATS group by Challenge_id ) AS V ON V.Challenge_id = CH.Challenge_id
WHERE S.TS!=0 OR S.TAS!=0 OR V.TV!=0 OR V.TUV!=0
GROUP BY CONT.Contest_id 
ORDER BY CONT.Contest_id;



/*
https://www.hackerrank.com/challenges/15-days-of-learning-sql

15 Days of Learning SQL

Sairam866

SELECT 
unique submission date,
number of different hackers who made a submission and have made a submission each previous day until current one, 
retrieve the hacker with max number of submissions having the total on desc order (C4 desc) and hacker_id on asc order (HID4 asc) in case same number of max submissions per day is found,
join your clause with the Hackers table to retrieve the name of this hacker
*/

SELECT SD, (select count(distinct S2.Hacker_id) from Submissions S2 where S2.Submission_Date = SD and (select count(distinct S3.Submission_Date) from Submissions S3 where S2.Hacker_id = S3.Hacker_id and S3.Submission_Date < S2.Submission_Date) = DATEDIFF(SD, '2016-03-01')) AS U_CNT, MAX_HID, MAX_HN 
FROM (select distinct Submission_Date as SD from Submissions S1) DTS 
INNER JOIN 
(SELECT SD4 AS SD5, HID4 AS MAX_HID, H.NAME AS MAX_HN FROM 
(select S4.Submission_Date as SD4, S4.Hacker_id as HID4, COUNT(S4.Hacker_id) as C4 from Submissions S4 group by S4.Submission_Date, S4.Hacker_id order by S4.Submission_Date, C4 desc, HID4 asc) Max_Hacker INNER JOIN Hackers H ON H.Hacker_id = HID4 group by SD4) Max_Hackers 
ON DTS.SD = Max_Hackers.SD5;
