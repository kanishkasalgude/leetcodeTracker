# [1789. Primary Department for Each Employee](https://leetcode.com/problems/primary-department-for-each-employee/)

[Database](../README.md) / [All problems](../../README.md)

| Difficulty | Status | Submissions | First tried | Solved on |
| --- | --- | --- | --- | --- |
| Easy | Solved | 1 | 2026-10-31 | 2026-10-31 |

**Topics:** Database

## My code

| Language | Result | Runtime | Memory | Date |
| --- | --- | --- | --- | --- |
| [mysql](solution.sql) | Accepted | 684 ms | 0B | 2026-10-31 |

## Submission history

| Date | Result | Language | Runtime | Memory |
| --- | --- | --- | --- | --- |
| 2026-10-31 | Accepted | mysql | 684 ms | 0B |

## Problem

<details>
<summary>Show description</summary>

<p>Table: <code>Employee</code></p>

<pre>
+---------------+---------+
| Column Name   |  Type   |
+---------------+---------+
| employee_id   | int     |
| department_id | int     |
| primary_flag  | varchar |
+---------------+---------+
(employee_id, department_id) is the primary key (combination of columns with unique values) for this table.
employee_id is the id of the employee.
department_id is the id of the department to which the employee belongs.
primary_flag is an ENUM (category) of type (&#39;Y&#39;, &#39;N&#39;). If the flag is &#39;Y&#39;, the department is the primary department for the employee. If the flag is &#39;N&#39;, the department is not the primary.
</pre>

<p>&nbsp;</p>

<p>Employees can belong to multiple departments. When the employee joins other departments, they need to decide which department is their primary department. Note that when an employee belongs to only one department, their primary column is <code>&#39;N&#39;</code>.</p>

<p>Write a solution to report all the employees with their primary department. For employees who belong to one department, report their only department.</p>

<p>Return the result table in <strong>any order</strong>.</p>

<p>The&nbsp;result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> 
Employee table:
+-------------+---------------+--------------+
| employee_id | department_id | primary_flag |
+-------------+---------------+--------------+
| 1           | 1             | N            |
| 2           | 1             | Y            |
| 2           | 2             | N            |
| 3           | 3             | N            |
| 4           | 2             | N            |
| 4           | 3             | Y            |
| 4           | 4             | N            |
+-------------+---------------+--------------+
<strong>Output:</strong> 
+-------------+---------------+
| employee_id | department_id |
+-------------+---------------+
| 1           | 1             |
| 2           | 1             |
| 3           | 3             |
| 4           | 3             |
+-------------+---------------+
<strong>Explanation:</strong> 
- The Primary department for employee 1 is 1.
- The Primary department for employee 2 is 1.
- The Primary department for employee 3 is 3.
- The Primary department for employee 4 is 3.
</pre>

</details>
