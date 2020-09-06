#
# @lc app=leetcode id=486 lang=python3
#
# [486] Predict the Winner
#

# @lc code=start
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        @lru_cache
        def max_score(s, e):
            if s == e:
                return nums[s]
            a = nums[s] - max_score(s+1, e)
            b = nums[e] - max_score(s, e-1)
            return max(a, b)
        return max_score(0, len(nums)-1) >= 0
        
# @lc code=end
