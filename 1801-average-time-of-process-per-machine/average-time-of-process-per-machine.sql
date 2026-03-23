# Write your MySQL query statement below
select astart.machine_id, round(avg(aend.timestamp - astart.timestamp), 3) as processing_time
from activity astart
inner join activity aend
on astart.machine_id = aend.machine_id and astart.process_id = aend.process_id
and astart.activity_type = 'start' and aend.activity_type = 'end'
group by astart.machine_id order by machine_id asc;
