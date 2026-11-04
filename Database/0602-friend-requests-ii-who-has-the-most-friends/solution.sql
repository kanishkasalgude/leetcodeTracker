# Write your MySQL query statement below
with AllFriends as (
    select requester_id as id from RequestAccepted
    union all
    select accepter_id as id from RequestAccepted
)
select 
    id, 
    count(*) as num
from AllFriends
group by id
order by num desc
limit 1;
