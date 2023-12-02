class Solution:
    def maxBalancedSubsequenceSum(self, nums: List[int]) -> int:
        def dp(i):
            if i == 0:
                return (nums[0], 0)
            ans = nums[i]
            index = i
            for j in range(i - 1, -1, -1):
                new_ans, last_ind = dp(j)
                if i - last_ind >= nums[i] - nums[j]:
                    if new_ans + nums[i] > ans:
                        ans = new_ans + nums[i]
                        index = i
        
