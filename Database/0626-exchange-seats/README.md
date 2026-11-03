# [626. Exchange Seats](https://leetcode.com/problems/exchange-seats/)

[Database](../README.md) / [All problems](../../README.md)

| Difficulty | Status | Submissions | First tried | Solved on |
| --- | --- | --- | --- | --- |
| Medium | Solved | 1 | 2026-11-02 | 2026-11-02 |

**Topics:** Database

## My code

| Language | Result | Runtime | Memory | Date |
| --- | --- | --- | --- | --- |
| [mysql](solution.sql) | Accepted | 387 ms | 0B | 2026-11-02 |

## Submission history

| Date | Result | Language | Runtime | Memory |
| --- | --- | --- | --- | --- |
| 2026-11-02 | Accepted | mysql | 387 ms | 0B |

## Problem

<details>
<summary>Show description</summary>

<p>Table: <code>Seat</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| student     | varchar |
+-------------+---------+
id is the primary key (unique value) column for this table.
Each row of this table indicates the name and the ID of a student.
The ID sequence always starts from 1 and increments continuously.
</pre>

<p>&nbsp;</p>

<p>Write a solution to swap the seat id of every two consecutive students. If the number of students is odd, the id of the last student is not swapped.</p>

<p>Return the result table ordered by <code>id</code> <strong>in ascending order</strong>.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> 
Seat table:
+----+---------+
| id | student |
+----+---------+
| 1  | Abbot   |
| 2  | Doris   |
| 3  | Emerson |
| 4  | Green   |
| 5  | Jeames  |
+----+---------+
<strong>Output:</strong> 
+----+---------+
| id | student |
+----+---------+
| 1  | Doris   |
| 2  | Abbot   |
| 3  | Green   |
| 4  | Emerson |
| 5  | Jeames  |
+----+---------+
<strong>Explanation:</strong> 
Note that if the number of students is odd, there is no need to change the last one&#39;s seat.
</pre>

</details>
