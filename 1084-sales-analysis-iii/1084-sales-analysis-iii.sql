# Write your MySQL query statement below
select p.product_id as product_id, p.product_name as product_name
from Product p left join Sales s
on p.product_id=s.product_id
group by product_id
having max(sale_date) <='2019-03-31'
    and min(sale_date) >='2019-01-01';