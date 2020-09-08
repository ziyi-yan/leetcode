#include <vector>
using namespace std;
/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
    //  1: true
    // -1: false
    //  0: uninitialized
    int dfs(vector<int> &nums, vector<vector<int>> &memo, int target, int idx,
            int curr) {
        if (curr > target) {
            return -1;
        }
        if (curr == target) {
            return 1;
        }
        if (idx == nums.size()) {
            return -1;
        }

        if (!memo[idx][curr]) {
            memo[idx][curr] =
                (dfs(nums, memo, target, idx + 1, curr + nums[idx]) == 1 ||
                 dfs(nums, memo, target, idx + 1, curr) == 1)
                    ? 1
                    : -1;
        }
        return memo[idx][curr];
    }

  public:
    bool canPartition(vector<int> &nums) {
        auto sum = 0;
        for (auto x : nums) {
            sum += x;
        }
        if (sum % 2 != 0) {
            return false;
        }

        auto target = sum / 2;
        vector<vector<int>> memo(nums.size(), vector<int>(target, 0));
        return dfs(nums, memo, target, 0, 0) == 1;
    }
};
// @lc code=end
