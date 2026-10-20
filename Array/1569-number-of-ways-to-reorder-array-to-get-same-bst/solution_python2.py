import sys

sys.setrecursionlimit(2000)

class Solution(object):
    def numOfWays(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        MOD = 10**9 + 7
        n = len(nums)
        comb = [[0]*n for _ in range(n)]
        for i in range(n):
            comb[i][0] = 1
            comb[i][i] = 1
            for j in range(1, i+1):
                comb[i][j] = (comb[i-1][j-1] + comb[i-1][j])%MOD

        def dfs(arr):
            if len(arr) <= 1:
                return 1

            root = arr[0]
            left = [x for x in arr if x < root]
            right = [x for x in arr if x > root]

            ways_comb = comb[len(left) + len(right)][len(left)]

            return (ways_comb*dfs(left)*dfs(right)) % MOD

        return (dfs(nums)-1) % MOD
        
