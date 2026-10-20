# [1614. Maximum Nesting Depth of the Parentheses](https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/)

[String](../README.md) / [All problems](../../README.md)

| Difficulty | Status | Submissions | First tried | Solved on |
| --- | --- | --- | --- | --- |
| Easy | Solved | 3 | 2026-06-15 | 2026-06-15 |

**Topics:** String, Stack, Bracket Sequences

## My code

| Language | Result | Runtime | Memory | Date |
| --- | --- | --- | --- | --- |
| [cpp](solution.cpp) | Accepted | 0 ms | 8.4 MB | 2026-06-15 |

## Submission history

| Date | Result | Language | Runtime | Memory |
| --- | --- | --- | --- | --- |
| 2026-06-15 | Accepted | cpp | 0 ms | 8.4 MB |
| 2026-06-15 | Compile Error | cpp | - | - |
| 2026-06-15 | Wrong Answer | cpp | - | - |

## Problem

<details>
<summary>Show description</summary>

<p>Given a <strong>valid parentheses string</strong> <code>s</code>, return the <strong>nesting depth</strong> of<em> </em><code>s</code>. The nesting depth is the <strong>maximum</strong> number of nested parentheses.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;(1+(2*3)+((8)/4))+1&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>Digit 8 is inside of 3 nested parentheses in the string.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;(1)+((2))+(((3)))&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<p>Digit 3 is inside of 3 nested parentheses in the string.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;()(())((()()))&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 100</code></li>
	<li><code>s</code> consists of digits <code>0-9</code> and characters <code>&#39;+&#39;</code>, <code>&#39;-&#39;</code>, <code>&#39;*&#39;</code>, <code>&#39;/&#39;</code>, <code>&#39;(&#39;</code>, and <code>&#39;)&#39;</code>.</li>
	<li>It is guaranteed that parentheses expression <code>s</code> is a VPS.</li>
</ul>

</details>
