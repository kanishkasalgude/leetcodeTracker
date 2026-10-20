# [1781. Sum of Beauty of All Substrings](https://leetcode.com/problems/sum-of-beauty-of-all-substrings/)

[Hash Table](../README.md) / [All problems](../../README.md)

| Difficulty | Status | Submissions | First tried | Solved on |
| --- | --- | --- | --- | --- |
| Medium | Solved | 1 | 2026-06-21 | 2026-06-21 |

**Topics:** Hash Table, String, Counting

## My code

| Language | Result | Runtime | Memory | Date |
| --- | --- | --- | --- | --- |
| [cpp](solution.cpp) | Accepted | 130 ms | 26.2 MB | 2026-06-21 |

## Submission history

| Date | Result | Language | Runtime | Memory |
| --- | --- | --- | --- | --- |
| 2026-06-21 | Accepted | cpp | 130 ms | 26.2 MB |

## Problem

<details>
<summary>Show description</summary>

<p>The <strong>beauty</strong> of a string is the difference in frequencies between the most frequent and least frequent characters.</p>

<ul>
	<li>For example, the beauty of <code>&quot;abaacc&quot;</code> is <code>3 - 1 = 2</code>.</li>
</ul>

<p>Given a string <code>s</code>, return <em>the sum of <strong>beauty</strong> of all of its substrings.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aabcb&quot;
<strong>Output:</strong> 5
<strong>Explanation: </strong>The substrings with non-zero beauty are [&quot;aab&quot;,&quot;aabc&quot;,&quot;aabcb&quot;,&quot;abcb&quot;,&quot;bcb&quot;], each with beauty equal to 1.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aabcbaa&quot;
<strong>Output:</strong> 17
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;=<sup> </sup>500</code></li>
	<li><code>s</code> consists of only lowercase English letters.</li>
</ul>

</details>
