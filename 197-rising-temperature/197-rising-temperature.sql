# Write your MySQL query statement below
Select w1.id
from Weather w1
join Weather w2
where w1.temperature >w2.temperature
and Datediff(w1.recordDate,w2.recordDate)=1;