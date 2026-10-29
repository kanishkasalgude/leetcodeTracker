# [1729. Find Followers Count](https://leetcode.com/problems/find-followers-count/)

[Database](../README.md) / [All problems](../../README.md)

| Difficulty | Status | Submissions | First tried | Solved on |
| --- | --- | --- | --- | --- |
| Easy | Solved | 1 | 2026-10-29 | 2026-10-29 |

**Topics:** Database

## My code

| Language | Result | Runtime | Memory | Date |
| --- | --- | --- | --- | --- |
| [mysql](solution.sql) | Accepted | 747 ms | 0B | 2026-10-29 |

## Submission history

| Date | Result | Language | Runtime | Memory |
| --- | --- | --- | --- | --- |
| 2026-10-29 | Accepted | mysql | 747 ms | 0B |

## Problem

<details>
<summary>Show description</summary>

<p>Table: <code>Followers</code></p>

<pre>
+-------------+------+
| Column Name | Type |
+-------------+------+
| user_id     | int  |
| follower_id | int  |
+-------------+------+
(user_id, follower_id) is the primary key (combination of columns with unique values) for this table.
This table contains the IDs of a user and a follower in a social media app where the follower follows the user.</pre>

<p>&nbsp;</p>

<p>Write a solution that will, for each user, return the number of followers.</p>

<p>Return the result table ordered by <code>user_id</code> in ascending order.</p>

<p>The&nbsp;result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> 
Followers table:
+---------+-------------+
| user_id | follower_id |
+---------+-------------+
| 0       | 1           |
| 1       | 0           |
| 2       | 0           |
| 2       | 1           |
+---------+-------------+
<strong>Output:</strong> 
+---------+----------------+
| user_id | followers_count|
+---------+----------------+
| 0       | 1              |
| 1       | 1              |
| 2       | 2              |
+---------+----------------+
<strong>Explanation:</strong> 
The followers of 0 are {1}
The followers of 1 are {0}
The followers of 2 are {0,1}
</pre>

</details>
