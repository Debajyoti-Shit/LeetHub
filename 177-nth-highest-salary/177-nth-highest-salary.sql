CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  #declare M INT;
  set N=N-1;
  RETURN (
      # Write your MySQL query statement below.
      select distinct salary from Employee
      order by salary desc limit N,1
  );
END