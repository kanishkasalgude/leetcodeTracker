# [610. Triangle Judgement](https://leetcode.com/problems/triangle-judgement/)

[Database](../README.md) / [All problems](../../README.md)

| Difficulty | Status | Submissions | First tried | Solved on |
| --- | --- | --- | --- | --- |
| Easy | Solved | 2 | 2026-10-31 | 2026-10-31 |

**Topics:** Database

## My code

| Language | Result | Runtime | Memory | Date |
| --- | --- | --- | --- | --- |
| [mysql](solution.sql) | Accepted | 393 ms | 0B | 2026-10-31 |

## Submission history

| Date | Result | Language | Runtime | Memory |
| --- | --- | --- | --- | --- |
| 2026-10-31 | Accepted | mysql | 393 ms | 0B |
| 2026-10-31 | Wrong Answer | mysql | - | - |

## Problem

<details>
<summary>Show description</summary>

<p>Table: <code>Triangle</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| x           | int  |
| y           | int  |
| z           | int  |
+-------------+------+
In SQL, (x, y, z) is the primary key column for this table.
Each row of this table contains the lengths of three line segments.
</pre>

<p>&nbsp;</p>

<p>Report for every three line segments whether they can form a triangle.</p>

<p>Return the result table in <strong>any order</strong>.</p>

<p>The&nbsp;result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> 
Triangle table:
+----+----+----+
| x  | y  | z  |
+----+----+----+
| 13 | 15 | 30 |
| 10 | 20 | 15 |
+----+----+----+
<strong>Output:</strong> 
+----+----+----+----------+
| x  | y  | z  | triangle |
+----+----+----+----------+
| 13 | 15 | 30 | No       |
| 10 | 20 | 15 | Yes      |
+----+----+----+----------+
</pre>

</details>
