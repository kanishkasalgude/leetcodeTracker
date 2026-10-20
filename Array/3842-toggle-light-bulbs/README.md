# [3842. Toggle Light Bulbs](https://leetcode.com/problems/toggle-light-bulbs/)

[Array](../README.md) / [All problems](../../README.md)

| Difficulty | Status | Submissions | First tried | Solved on |
| --- | --- | --- | --- | --- |
| Easy | Solved | 4 | 2026-02-15 | 2026-02-15 |

**Topics:** Array, Hash Table, Sorting, Simulation

## My code

| Language | Result | Runtime | Memory | Date |
| --- | --- | --- | --- | --- |
| [cpp](solution.cpp) | Accepted | 13 ms | 37.1 MB | 2026-02-15 |

## Submission history

| Date | Result | Language | Runtime | Memory |
| --- | --- | --- | --- | --- |
| 2026-02-15 | Accepted | cpp | 13 ms | 37.1 MB |
| 2026-02-15 | Wrong Answer | cpp | - | - |
| 2026-02-15 | Wrong Answer | cpp | - | - |
| 2026-02-15 | Wrong Answer | cpp | - | - |

## Problem

<details>
<summary>Show description</summary>

<p>You are given an array <code>bulbs</code> of integers between 1 and 100.</p>

<p>There are 100 light bulbs numbered from 1 to 100. All of them are switched off initially.</p>

<p>For each element <code>bulbs[i]</code> in the array <code>bulbs</code>:</p>

<ul>
	<li>If the <code>bulbs[i]<sup>th</sup></code> light bulb is currently off, switch it on.</li>
	<li>Otherwise, switch it off.</li>
</ul>

<p>Return the list of integers denoting the light bulbs that are on in the end, <strong>sorted</strong> in <strong>ascending</strong> order. If no bulb is on, return an empty list.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> bulbs<span class="example-io"> = [10,30,20,10]</span></p>

<p><strong>Output:</strong> <span class="example-io">[20,30]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The <code>bulbs[0] = 10<sup>th</sup></code> light bulb is currently off. We switch it on.</li>
	<li>The <code>bulbs[1] = 30<sup>th</sup></code> light bulb is currently off. We switch it on.</li>
	<li>The <code>bulbs[2] = 20<sup>th</sup></code> light bulb is currently off. We switch it on.</li>
	<li>The <code>bulbs[3] = 10<sup>th</sup></code> light bulb is currently on. We switch it off.</li>
	<li>In the end, the 20<sup>th</sup> and the 30<sup>th</sup> light bulbs are on.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> bulbs<span class="example-io"> = [100,100]</span></p>

<p><strong>Output:</strong> <span class="example-io">[]</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The <code>bulbs[0] = 100<sup>th</sup></code> light bulb is currently off. We switch it on.</li>
	<li>The <code>bulbs[1] = 100<sup>th</sup></code> light bulb is currently on. We switch it off.</li>
	<li>In the end, no light bulb is on.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= bulbs.length &lt;= 100</code></li>
	<li><code>1 &lt;= bulbs[i] &lt;= 100</code></li>
</ul>

</details>
