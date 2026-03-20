# Write your MySQL query statement below
select customer_id
from product p
left join customer c
on p.product_key = c.product_key
group by customer_id
having COUNT(DISTINCT p.product_key) >= (select COUNT(*) from product);