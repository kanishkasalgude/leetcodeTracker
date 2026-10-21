class Solution(object):
    def sortableIntegers(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        sorted_nums = sorted(nums)
        
        # Helper function to check if a block can be cyclically rotated to match target
        def can_rotate(arr_block, target_block, k):
            if arr_block == target_block:
                return True
            
            # Target segment must be a substring of arr_block + arr_block
            double_block = arr_block + arr_block
            # Quick check using string matching / sliding window approach
            for start in range(k):
                if double_block[start : start + k] == target_block:
                    return True
            return False

        # Find all divisors of n
        divisors = []
        for d in range(1, int(n**0.5) + 1):
            if n % d == 0:
                divisors.append(d)
                if d * d != n:
                    divisors.append(n // d)
        
        ans = 0
        
        # Test each divisor k
        for k in divisors:
            is_sortable = True
            for i in range(0, n, k):
                block = nums[i : i + k]
                target = sorted_nums[i : i + k]
                
                if not can_rotate(block, target, k):
                    is_sortable = False
                    break
            
            if is_sortable:
                ans += k
                
        return ans
