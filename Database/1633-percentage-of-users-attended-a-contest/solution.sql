# Write your MySQL query statement below
select
    r.contest_id,
    ROUND(COUNT(*)*100.0/(select count(*) from users),2) as percentage
from Register r
group by r.contest_id
order by percentage DESC, r.contest_id ASC;
