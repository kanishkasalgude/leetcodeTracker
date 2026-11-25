import math

class Solution:
    def maxLength(self, nums: List[int]) -> int:
        n = len(nums)
        max_len = 1
        for i in range(n):
            prod = nums[i]
            g = nums[i]
            l = nums[i]

            for j in range(i+1, n):
                prod = nums[j]*prod
                g = math.gcd(g, nums[j])
                l = math.lcm(l, nums[j])

                if prod == l*g:
                    max_len = max(max_len, j-i+1)
                elif prod > l*g:
                    break
        return max_len
