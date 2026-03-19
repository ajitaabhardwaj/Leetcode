# Write your MySQL query statement below
select customer_number from orders group by customer_number having Count(order_number) =
    (select max(order_count) from
        (select count(order_number) as order_count from orders group by customer_number)
        t
    );