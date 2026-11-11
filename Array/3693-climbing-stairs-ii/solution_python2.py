class Solution(object):
    def climbStairs(self, n, costs):
        """
        :type n: int
        :type costs: List[int]
        :rtype: int
        """
        dp = [float('inf')]*(n+1)
        dp[0] = 0
        for i in xrange(1, n+1):
            step_cost = costs[i-1]
            for jump in (1,2,3):
                if i-jump >= 0:
                    cost = step_cost + dp[i-jump] + (jump*jump)
                    if cost < dp[i]:
                        dp[i] = cost
        return dp[n]
        
