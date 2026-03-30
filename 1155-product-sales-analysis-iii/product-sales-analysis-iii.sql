# Write your MySQL query statement below
with s as (
    select product_id, min(year) over (
        partition by product_id
    ) as first_year, year,
    quantity, price
    from sales)

select product_id, first_year, quantity, price from s where first_year = year


