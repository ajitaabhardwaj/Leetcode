(select u.name as results
from users u 
join MovieRating mr 
on mr.user_id = u.user_id
group by u.name
order by count(*) desc, u.name asc
limit 1)
union all
(select m.title as results
from movies m
join MovieRating mr
on m.movie_id = mr.movie_id
where created_at between '2020-02-01' and '2020-02-29'
group by m.title
order by avg(mr.rating) desc, m.title limit 1
)