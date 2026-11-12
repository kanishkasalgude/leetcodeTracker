class Solution(object):
    def minimumCost(self, cost1, cost2, costBoth, need1, need2):
        """
        :type cost1: int
        :type cost2: int
        :type costBoth: int
        :type need1: int
        :type need2: int
        :rtype: int
        """
        rem1 = rem2 = 0
        if need2 > need1:
            rem2 = need2 - need1
        if need1 > need2:
            rem1 = need1 - need2
        return min(costBoth, cost1+cost2)*min(need2, need1) + rem1*min(costBoth, cost1) + rem2*min(costBoth, cost2)
        
