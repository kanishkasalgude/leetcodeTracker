# Write your MySQL query statement below
with DailyTotals as (
    select 
        visited_on,
        sum(amount) as daily_amount
    from customer
    group by visited_on
), 
RollingStats as (
    select
        visited_on,
        sum(daily_amount) over (
            order by visited_on
            rows between 6 preceding and current row
        ) as amount,
        round(
            avg(daily_amount) over (
                order by visited_on
                rows between 6 preceding and current row
            ),2
        ) as average_amount,
        ROW_NUMBER() over(order by visited_on) as row_num
    from DailyTotals
)
select
    visited_on,
    amount,
    average_amount
from RollingStats
where row_num >=7
order by visited_on asc;
