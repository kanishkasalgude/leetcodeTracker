# Write your MySQL query statement below
select
    round(
        count(distinct s.player_id)/count(distinct f.player_id)
        ,2
    ) as fraction
from (
    select player_id, min(event_date) as first_login 
    from activity
    group by player_id
) f
left join activity s
    on f.player_id = s.player_id
    and s.event_date = DATE_ADD(f.first_login, INTERVAL 1 DAY);   
