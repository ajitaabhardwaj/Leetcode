# Write your MySQL query statement below
select employee_id
from employees emp
where salary<30000
and emp.manager_id NOT IN (select employee_id from employees)
order by employee_id asc;