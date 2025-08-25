# Write your MySQL query statement below

select e.Name as Employee from
Employee e join Employee m
on e.managerId = m.id
where m.salary < e.salary;