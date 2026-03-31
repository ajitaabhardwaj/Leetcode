select employee_id, department_id
from (
    select employee_id, department_id, primary_flag, count(department_id) over(
    partition by employee_id
    )as count_dept
from Employee ) t
where primary_flag = (case when count_dept > 1 then 'Y' else 'N' end)

