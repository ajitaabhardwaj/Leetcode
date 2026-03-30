select contest_id,
round(count(r.user_id) *100/ (select count(*) from users), 2) as percentage
from users u
join register r
using (user_id)
group by r.contest_id
order by percentage desc, contest_id;