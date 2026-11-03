# Write your MySQL query statement below
(
    select u.name as results
    from users u
    join movierating r
    on u.user_id = r.user_id
    group by u.user_id, u.name
    order by count(r.rating) desc, u.name asc
    limit 1
)
union all
(
    select m.title as results
    from movies m
    join movierating r
    on m.movie_id = r.movie_id
    where r.created_at >= '2020-02-01' and created_at<='2020-02-29'
    group by m.movie_id, m.title
    order by avg(r.rating) desc, m.title asc
    limit 1
);
