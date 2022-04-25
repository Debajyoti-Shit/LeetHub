# Write your MySQL query statement below
select stock_name, sum(
    case
        when operation='Buy' then (-1)* price #if 'Buy' then we - the price,
        else price #else + to the sum
    end
) as capital_gain_loss
from Stocks
group by stock_name;