#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // state transition equation: dp[i] = dp[i-1] > 0 ? dp[i-1] + nums[i] : nums[i];
        auto total_max = nums[0];
        auto max = nums[0];
        for (auto i = 1; i < nums.size(); i++)
        {
            if (max < 0)
                max = nums[i];
            else
                max += nums[i];

            if (max > total_max)
                total_max = max;
        }

        return total_max;
    }
};
// @lc code=end
