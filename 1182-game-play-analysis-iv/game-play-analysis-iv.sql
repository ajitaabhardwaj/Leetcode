select round(
    (
        select count(distinct a1.player_id) 
        from activity a1 
        join activity a2 
        on date_Add(a1.event_date, interval 1 day) = a2.event_date 
        and a1.player_id = a2.player_id 
        where a1.event_date = (
            select min(event_date) from activity a3 where a1.player_id = a3.player_id
            )
        )/ count(distinct player_id), 2) 
as fraction
from activity;
