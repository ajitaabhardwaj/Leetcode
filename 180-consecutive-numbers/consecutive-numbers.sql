select distinct num as ConsecutiveNums 
from (
    select id, num, 
    lead(num) over(
        order by id
    )as nxt, 
    lead(num,2) over(
        order by id
    )as nxt2
from logs
)t
where num = nxt and nxt = nxt2

